#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n;
inline string P1(string s) {
	for (int i = n - 1; i >= 0; i--) if (s[i] == '0') {
		s[i] = '1';
		break;
	} else {
		s[i] = '0';
	}
	return s;
}
inline void Xor(string &s, string t) {
	for (int i = 0; i < n; i++) if (t[i] == '1') s[i] ^= 1;
}
string s, t;
int main() {
	cin >> n >> s >> t;
	if (n == 1 && t[0] == '0') {
		cout << '0' << endl;
		return 0;
	}
	if (s[0] == '0') {
		cout << string(n, '1') << endl;
		return 0;
	}
	string x = s;
	int cnt = 1;
	while (x != t && cnt < 4) {
		cnt++;
		x = P1(x);
	}
	if (cnt >= 4) {
		t.back() = '1';
		cout << t << endl;
		return 0;
	}
	x = s;
	string ans(n, '0');
	for (int i = 1; i <= cnt; i++) {
		string y = x, cur(n, '0');
		for (int j = i; j <= cnt; j++) {
			Xor(cur, y);
			ans = max(ans, cur);
			y = P1(y);
		}
		x = P1(x);
	}
	cout << ans << endl;
	return 0;
}