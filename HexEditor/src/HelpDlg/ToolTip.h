/*
this file is part of notepad++
Copyright (C)2003 Don HO < donho@altern.org >

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef __TOOLTIP_H__
#define __TOOLTIP_H__

#include <string>
#include "Hex.h"
#include "Window.h"


using namespace std;

#ifdef UNICODE
#define string wstring
#endif

class ToolTip : public Window
{
public :
	ToolTip():_defaultProc(),_startPt() {};
	void destroy(void){
		DestroyWindow(_hSelf);
		_hSelf = NULL;
	};

// Attributes
public:

// Implementation
public:
	virtual void init(HINSTANCE hInst, HWND hParent);
	void Show(RECT rectTitle, string strTitleText, int iXOff = 0, int iWidthOff = 0);

protected:
	POINT		_startPt;
    WNDPROC		_defaultProc;

    static LRESULT CALLBACK staticWinProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
        return (((ToolTip *)(::GetWindowLongPtr(hwnd, GWLP_USERDATA)))->runProc(Message, wParam, lParam));
    };
	LRESULT runProc(UINT Message, WPARAM wParam, LPARAM lParam);
};

#endif // __TOOLTIP_H__
