#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<int> cnt(n);
	vector<vector<int>> a(n, vector<int> (m));
	vector<pair<int, int>> all;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			all.push_back({a[i][j], i});
		}
		sort(a[i].begin(), a[i].end());
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < m; ++i)
		cnt[all[i].second]++;
	int ttl_cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][(m - ttl_cnt + j) % m] << ' ';
		cout << '\n';
		ttl_cnt += cnt[i];
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t--)
		solve();
	
	return 0;
}