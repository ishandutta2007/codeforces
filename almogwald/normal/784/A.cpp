//#include "stdafx.h"
#include <iostream>
#include <vector>

bool myfunction(int i, int j) { return (i<j); }
using namespace std;
int main() {
	/*int a,b,c,d,e,f,g,q1,q2,q3,q4;
	cin >> q4;
	cin >> q3;
	cin >> q2;
	cin >> q1;
	a = q1 | q2;
	b = q3 | q4 - (q3 & q4);
	c = q2 & q3;
	d = q1 | q4;
	e = c | d - (c & d);
	f = a & b;
	g = e | f;
	cout << a << ',' << b << ',' << c << ',' << d << ',' << e << ',' << f << ',' << g << '\n';*/
	int n, a[] = { 4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438, 454, 483, 517, 526, 535, 562, 576, 588, 627, 634, 636, 645, 648, 654, 663, 666, 690, 706, 728, 729, 762, 778, 825, 852, 861, 895, 913, 915, 922, 958, 985, 1086 };
	cin >> n;
	/*vector< int> s(n);
	vector< int> lol(4000000);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (s[min] > s[j]) {
				min = j;
			}
		}
		int t = s[i];
		s[i] = s[min];
		s[min] = t;
	}
	for (int i = 0; i < 6000000; i++) {
		s[i%n]++;
		s[i%n]--;
	}
	for (int i = 0; i < n; cout <<char(' '+ i-(i++))) {
		cout << s[i];
	}*/
	cout <<a[n-1] << '\n';

	return 0;
}