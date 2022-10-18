#include <bits/stdc++.h>

using namespace std;

#define int int64_t
const int maxn = 1e5 + 42;

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s[n], t[m];
	for(int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for(int j = 0; j < m; j++) {
		cin >> t[j];
	}
	int q;
	cin >> q;
	while(q--) {
		int y;
		cin >> y;
		y--;
		cout << s[y % n] << t[y % m] << "\n";
	}
	return 0;
}