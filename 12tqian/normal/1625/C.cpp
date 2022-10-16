#include <bits/stdc++.h>

using namespace std;

void solve_case(int tc = 0) {
	const int INF = 1e9;
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += a[i] * ((i != n - 1 ? d[i + 1] : l) - d[i]);
	}
	vector<vector<int>> set(n, vector<int>(k + 1, INF));
	auto prv = set, nxt = set;
	function<void(int, int, int)> push = [&](int x, int y, int z) {
		int delta = prv[y][z] + (d[x + 1] - d[x]) * a[y];
		if (z < k) {
			nxt[y][z + 1] = min(nxt[y][z + 1], delta);
		}
		nxt[x + 1][z] = min(nxt[x + 1][z], delta);
	};
	prv[0][0] = 0;
	for (int x = 0; x < n - 1; ++x) {
		for (int y = 0; y <= x; ++y) {
			for (int z = 0; z <= k; ++z) {
				push(x, y, z);
			}
		}
		prv.swap(nxt);
		nxt = set;
	}
	for (int y = 0; y < n; ++y) {
		for (int z = 0; z <= k; ++z) {
			ans = min(ans, prv[y][z] + (l - d[n - 1]) * a[y]);
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	// cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}