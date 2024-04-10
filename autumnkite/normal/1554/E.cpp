#include <bits/stdc++.h>

const int P = 998244353;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> edges(n - 1);
	std::vector<int> deg(n);
	std::vector<int> ans(n + 1);
	ans[1] = 1;
	for (int i = 0; i < n - 1; ++i) {
		int &u = edges[i].first, &v = edges[i].second;
		std::cin >> u >> v;
		--u, --v;
		++deg[u], ++deg[v];
		ans[1] = 2 * ans[1] % P;
	}

	std::vector<std::vector<std::pair<int, int>>> add_edges(n);
	std::vector<std::vector<int>> add_nodes(n);
	for (int i = 0; i < n; ++i) {
		add_nodes[deg[i]].push_back(i);
	}
	int mn = n;
	for (auto &[u, v] : edges) {
		if (deg[u] > deg[v]) {
			std::swap(u, v);
		}
		add_edges[deg[u]].emplace_back(u, v);
		mn = std::min(mn, deg[v]);
	}

	std::vector<bool> vis(n);
	std::vector<std::vector<int>> E(n);
	std::vector<int> p;
	for (int i = n - 1; i >= 2; --i) {
		auto dfs = [&](auto &self, int u, int fa) -> int {
			vis[u] = true;
			int d = deg[u] - (int)E[u].size();
			for (int v : E[u]) {
				if (v != fa) {
					int t = self(self, v, u);
					if (t == -1) {
						return -1;
					}
					d += !t;
				}
			}
			if (d % i == 0) {
				return 0;
			} else if ((d + 1) % i == 0) {
				return 1;
			} else {
				return -1;
			}
		};
		for (int x : add_nodes[i]) {
			p.push_back(x);
		}
		for (auto [u, v] : add_edges[i]) {
			E[u].push_back(v);
			E[v].push_back(u);
		}
		if (i <= mn) {
			ans[i] = 1;
			for (int x : p) {
				if (!vis[x]) {
					int t = dfs(dfs, x, -1);
					if (t != 0) {
						ans[i] = 0;
						break;
					}
				}
			}
			for (int x : p) {
				vis[x] = false;
			}
		}
	}
	for (int i = n; i >= 1; --i) {
		for (int j = i + i; j <= n; j += i) {
			ans[i] = (ans[i] + P - ans[j]) % P;
		}
	}
	for (int i = 1; i <= n; ++i) {
		std::cout << ans[i] << " \n"[i == n];
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