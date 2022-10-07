#include <bits/stdc++.h>

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<int> f(n), g(n), sz(n);
	int ans = 0;

	std::function<void(int, int)> get_f = [&](int u, int fa) {
		sz[u] = 1;
		f[u] = 0;
		int cnt = 0;
		for (int v : E[u]) {
			if (v != fa) {
				get_f(v, u);
				sz[u] += sz[v];
				f[u] += f[v];
				cnt += k * f[v] == sz[v] - 1;
			}
		}
		f[u] += cnt / k;
	};

	std::function<void(int, int)> get_g = [&](int u, int fa) {
		int cnt = 0;
		for (int v : E[u]) {
			if (v != fa) {
				cnt += k * f[v] == sz[v] - 1;
			}
		}
		ans = std::max(ans, f[u] + g[u] - cnt / k + (cnt + (k * g[u] == n - sz[u] - 1)) / k);
		for (int v : E[u]) {
			if (v != fa) {
				g[v] = g[u] + f[u] - cnt / k - f[v] + (cnt - (k * f[v] == sz[v] - 1) + (k * g[u] == n - sz[u] - 1)) / k;
				get_g(v, u);
			}
		}
	};

	get_f(0, -1), get_g(0, -1);
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