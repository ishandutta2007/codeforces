#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		a[i] -= v;
	}

	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v), E[v].push_back(u);
	}

	bool ex = false;
	std::vector<int> col(n, -1);
	std::function<void(int, int)> dfs = [&](int u, int c) {
		if (col[u] != -1) {
			ex |= col[u] != c;
			return;
		}
		col[u] = c;
		for (int v : E[u]) {
			dfs(v, c ^ 1);
		}
	};
	dfs(0, 0);

	long long sum[2] = {0, 0};
	for (int i = 0; i < n; ++i) {
		sum[col[i]] += a[i];
	}
	if (ex) {
		std::cout << ((sum[0] + sum[1]) & 1 ? "NO" : "YES") << "\n";
	} else {
		std::cout << (sum[0] == sum[1] ? "YES" : "NO") << "\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}