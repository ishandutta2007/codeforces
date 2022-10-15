/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	string s;
	cin >> s;
	int a = ( (s[0] - '0') * 10) + (s[1] - '0');
	int b = ( (s[3] - '0') * 10) + (s[4] - '0');
	cin >> s;
	int c = ( (s[0] - '0') * 10) + (s[1] - '0');
	int d = ( (s[3] - '0') * 10) + (s[4] - '0');
	b -= d;
	if (b < 0){
		b += 60;
		a--;
	}
	a -= c;
	if (a < 0){
		a += 24;
	}
	if (a < 10)
		cout << 0;
	cout << a << ":";
	if (b < 10)
		cout << 0;
	cout << b;
}