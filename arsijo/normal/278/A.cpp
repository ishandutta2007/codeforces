//============================================================================
// Name        : He.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long a;
	cin >> a;
	int d[a];
	for(int i = 0; i < a; i++){
		cin >> d[i];
	}
	int l, r, e, t;
	cin >> e >> t;
	l = min(e, t);
	r = max(e, t);
	long a1, a2;
	a1 = 0;
	a2 = 0;
	for(int i = 0; i < a; i++){
		if (i + 1 >= l && i < r - 1){
			a1 += d[i];
		}else{
			a2 += d[i];
		}
	}
	cout << min(a1, a2);
}