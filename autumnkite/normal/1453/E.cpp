#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	int ans = 0;
	std::vector<int> mn(n);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		int d = 0;
		mn[u] = n;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				++d;
				mn[u] = std::min(mn[u], mn[v] + 1);
			}
		}
		if (d == 0) {
			mn[u] = 0;
			return;
		}
		if (d == 1) {
			return;
		}
		for (int v : E[u]) {
			if (v != fa) {
				ans = std::max(ans, mn[v] + 2);
			}
		}
	};
	int mx = -1;
	for (int u : E[0]) {
		dfs(u, 0);
		if (mx == -1 || mn[u] > mn[mx]) {
			mx = u;
		}
	}
	for (int u : E[0]) {
		if (u != mx) {
			ans = std::max(ans, mn[u] + 2);
		}
	}
	ans = std::max(ans, mn[mx] + 1);
	std::cout << ans << "\n";
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