#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> w(n), b(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> b[i];
		}
		for (int i = 0; i < n; ++i) {
			std::cin >> w[i];
		}
		std::vector<std::vector<int>> E(n);
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			E[u].push_back(v);
			E[v].push_back(u);
		}

		std::vector<int> sz(n);
		std::vector<std::vector<std::pair<int, long long>>> f(n);
		std::function<void(int, int)> dfs = [&](int u, int fa) {
			sz[u] = 1;
			f[u].resize(1);
			f[u][0] = std::make_pair(0, w[u] - b[u]);
			for (int v : E[u]) {
				if (v != fa) {
					dfs(v, u);
					std::vector<std::pair<int, long long>> g(sz[u] + sz[v], std::make_pair(-1, 0));
					for (int i = 0; i < sz[u]; ++i) {
						for (int j = 0; j < sz[v]; ++j) {
							g[i + j] = std::max(
								g[i + j], 
								std::make_pair(f[u][i].first + f[v][j].first, f[u][i].second + f[v][j].second)
							);
							g[i + j + 1] = std::max(
								g[i + j + 1], 
								std::make_pair(f[u][i].first + f[v][j].first + (f[v][j].second > 0), f[u][i].second)
							);
						}
					}
					sz[u] += sz[v];
					f[u].swap(g);
				}
			}
		};
		dfs(0, -1);
		std::cout << f[0][m - 1].first + (f[0][m - 1].second > 0) << "\n";
	}
}