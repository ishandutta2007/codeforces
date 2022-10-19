#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> k(n);
	for (int i = 0; i < n; ++i)
		cin >> k[i];
	vector<int> c(m);
	for (int i = 0; i < m; ++i)
		cin >> c[i];
	sort(k.rbegin(), k.rend());
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (cur <= k[i] - 1)
			ans += c[cur++];
		else
			ans += c[k[i] - 1];
	}
	cout << ans << '\n';
}

signed main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}