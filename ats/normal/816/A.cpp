#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a = (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
	int b = (int)(s[3] - '0') * 10 + (int)(s[4] - '0');
	int res = 0;
	for (int i = 0; i < 24 * 60; i++) {
		if (a / 10 == b % 10 && a % 10 == b / 10) {
			res = i;
			break;
		}
		b++;
		if (b >= 60) {
			b = 0;
			a++;
			if (a >= 24) {
				a = 0;
			}
		}
	}
	cout << res << endl;
	return 0;
	
}