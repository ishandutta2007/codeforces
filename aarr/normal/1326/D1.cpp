#include <bits/stdc++.h>
using namespace std;


string s;


bool pal(int l, int r) {
	for (int i = l; i < r; i++) {
		if (s[i] != s[r - i + l - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> s;
		if (pal(0, s.size())) {
			cout << s << '\n';
			continue;
		}
		int lt = s.size() / 2;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1]) {
				lt = i;
				break;
			} 
		}
		int l = lt - 1, r = s.size() - lt;
		int x = -1, y = s.size() + 1;
		for (int i = l + 1; i < r; i++) {
			if (pal(l + 1, i + 1)) {
				x = i;
			}
		}
		for (int i = r - 1; i > l; i--) {
			if (pal(i, r)) {
				y = i;
			}
		}
	//	cout << l << " " << r << " " << x << " " << y << endl;
		if (x - l >= r - y) {
			for (int i = 0; i <= x; i++) {
				cout << s[i];
			}
			for (int i = r; i < s.size(); i++) {
				cout << s[i];
			}
		}
		else {
			for (int i = 0; i <= l; i++) {
				cout << s[i];
			}
			for (int i = y; i < s.size(); i++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}
	return 0;
}