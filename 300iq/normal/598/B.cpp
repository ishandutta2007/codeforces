#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	int m, l, r, k, n = (int) s.size();
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> k;
		l--, r--;
		string sub = "";
		for (int p = l; p <= r; p++) {
			sub += s[p];
		}
		n = (int) sub.size();
		for (int p = l; p <= r; p++) {
			s[p] = sub[((p - l - k) % n + n) % n];
		}
	}
	cout << s << endl;
}