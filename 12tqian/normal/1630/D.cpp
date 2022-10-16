#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	const long long INF = 1e18;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int k = 0;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		k = __gcd(k, x);
	}
	vector<vector<int>> group(k);
	for (int i = 0; i < n; ++i) {
		group[i % k].push_back(a[i]);
	}
	for (auto& g : group) {
		sort(g.begin(), g.end());
	}
	long long ans = -INF;
	{
		long long sum = 0;
		for (auto g : group) {
			int idx = 0;
			int sz = (int)g.size();
			while (idx < sz - 1 && g[idx + 1] <= 0) {
				sum -= g[idx] + g[idx + 1];
				idx += 2;
			}
			if (idx < sz - 1) {
				sum += max(g[idx] + g[idx + 1], -g[idx] - g[idx + 1]);
				idx += 2;
			}
			sum += accumulate(g.begin() + idx, g.end(), 0ll);
		}
		ans = max(ans, sum);
	}
	{
		long long sum = 0;
		for (auto g : group) {
			sum -= g[0];
			int idx = 1;
			int sz = (int)g.size();
			while (idx < sz - 1 && g[idx + 1] <= 0) {
				sum -= g[idx] + g[idx + 1];
				idx += 2;
			}
			if (idx < sz - 1) {
				sum += max(g[idx] + g[idx + 1], -g[idx] - g[idx + 1]);
				idx += 2;
			}
			sum += accumulate(g.begin() + idx, g.end(), 0ll);
		}
		ans = max(ans, sum);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}