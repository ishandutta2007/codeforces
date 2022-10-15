/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int g = s[s.length() - 1] - '0', b = -1, c = -1;
	for (int i = s.length() - 2; i >= 0; i--) {
		int a = s[i] - '0';
		if (a % 2 == 0) {
			if (a < g)
				c = i;
			if (a > g && b == -1) {
				b = i;
			}
		}
	}
	if (c == -1 && b == -1) {
		cout << -1;
		return 0;
	}
	int pos;
	if (c == -1) {
		pos = b;
	} else {
		pos = c;
	}
	for (int i = 0; i < (s.length() - 1); i++) {
		if (i == pos)
			cout << s[s.length() - 1];
		else
			cout << s[i];
	}
	cout << s[pos];
}