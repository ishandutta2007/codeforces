/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int a, b, c, d;
	string s;
	cin >> s;
	a = s[0] - '0';
	b = s[1] - '0';
	c = s[3] - '0';
	d = s[4] - '0';
	do{
		d++;
		if (d == 10){
			d = 0;
			c++;
			if (c == 6){
				c = 0;
				b++;
				if (b == 10){
					b = 0;
					a++;
				}else if (b == 4 && a == 2){
					a = 0;
					b = 0;
				}
			}
		}
	}while(a != d || c != b);
	cout << a << b << ":" << c << d;
}