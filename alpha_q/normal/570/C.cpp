#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; string s; cin >> n >> m >> s;
	int q = 0, l = 0; bool f = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '.') {
			l++;
			if (!f) q++, f = 1;
		} else f = 0;
	}
	
	while (m--) {
		int p; char c;
		cin >> p >> c; p--;
		
		if (n == 1) {
			cout << 0 << endl;
			continue;
		}
		
		if (c == '.') {
			if (p == 0) {
				if (s[0] != '.') {
					l++;
					if (s[1] != '.') q++;
				} 
			}
			else if (p == n - 1) {
				if (s[n - 1] != '.') {
					l++;
					if (s[n - 2] != '.') q++;
				}
			}
			else {
				if (s[p] != '.') {
					l++;
					if (s[p - 1] == '.' && s[p + 1] == '.') q--;
					else if (s[p - 1] != '.' && s[p + 1] != '.') q++;
				}
			}
		} else {
			if (p == 0) {
				if (s[0] == '.') {
					l--;
					if (s[1] != '.') q--;
				} 
			}
			else if (p == n - 1) {
				if (s[n - 1] == '.') {
					l--;
					if (s[n - 2] != '.') q--;
				}
			}
			else {
				if (s[p] == '.') {
					l--;
					if (s[p - 1] == '.' && s[p + 1] == '.') q++;
					else if (s[p - 1] != '.' && s[p + 1] != '.') q--;
				}
			}
		}
		s[p] = c;
		cout << l - q << endl;
	}
	return 0;
}