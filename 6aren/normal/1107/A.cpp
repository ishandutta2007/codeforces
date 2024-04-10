#include <bits/stdc++.h>

using namespace std;

int ntest, n;

string s;

int main() {
	cin >> ntest;
	while (ntest--) {
		cin >> n >> s;
		if (n == 2 && (int) (s[0] - '0') >= (int) (s[1] - '0')) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			cout << 2 << endl;
			cout << s[0] << " ";
			for (int i = 1; i < s.size(); i++) {
				cout << s[i];
			}
			cout << endl;
		}
	}
	return 0;
}