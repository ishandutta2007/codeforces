#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	while (1) {
		int n, m;
		std::cin >> n >> m;
		if (n == 0 && m == 0) {
			return 0;
		}
		std::vector<std::vector<int>> E(n);
		for (int i = 0; i < m; ++i) {
			int k;
			std::cin >> k;
			int lst;
			std::cin >> lst;
			--lst;
			for (int i = 1; i < k; ++i) {
				int v;
				std::cin >> v;
				--v;
				E[lst].push_back(v);
				E[v].push_back(lst);
				lst = v;
			}
		}

		int idx = 0;
		std::vector<int> dfn(n, -1), low(n);
		std::vector<int> sta;
		std::vector<bool> vis(n);
		std::vector<std::vector<int>> dcc;

		std::function<void(int)> tarjan = [&](int u) {
			dfn[u] = low[u] = idx++;
			sta.push_back(u);
			vis[u] = true;
			for (int v : E[u]) {
				if (dfn[v] == -1) {
					tarjan(v);
					low[u] = std::min(low[u], low[v]);
					if (dfn[u] <= low[v]) {
						dcc.emplace_back();
						do {
							dcc.back().push_back(sta.back());
							sta.pop_back();
						} while (dcc.back().back() != v);
						dcc.back().push_back(u);
					}
				} else {
					low[u] = std::min(low[u], dfn[v]);
				}
			}
		};

		tarjan(0);

		std::vector<std::vector<int>> G(n);
		for (const auto &v : dcc) {
			if ((int)v.size() == 2) {
				G[v[0]].push_back(v[1]);
				G[v[1]].push_back(v[0]);
			}
		}

		std::vector<std::pair<int, int>> ans;
		std::vector<bool> visited(n);

		std::function<std::pair<int, int>(int, int)> dfs = [&](int u, int fa) {
			visited[u] = true;
			std::vector<std::pair<int, int>> v1, v2;
			for (int v : G[u]) {
				if (v != fa) {
					auto t = dfs(v, u);
					++t.first;
					if (t.first == 1) {
						v1.push_back(t);
					} else {
						v2.push_back(t);
					}
				}
			}
			while ((int)v2.size() > 1) {
				int x = v2.back().second;
				v2.pop_back();
				int y = v2.back().second;
				v2.pop_back();
				ans.emplace_back(x, y);
			}
			if ((int)v2.size() == 1) {
				if ((int)v1.size() > 1) {
					ans.emplace_back(v1.back().second, v2.back().second);
					v1.pop_back(), v2.pop_back();
				} else if (fa != -1) {
					return v2.back();
				} else {
					ans.emplace_back(u, v2.back().second);
					return std::make_pair(0, u);
				}
			}
			if (v1.empty()) {
				return std::make_pair(0, u);
			} else {
				while ((int)v1.size() > 2) {
					int x = v1.back().second;
					v1.pop_back();
					int y = v1.back().second;
					v1.pop_back();
					ans.emplace_back(x, y);
				}
				if (fa != -1) {
					return v1.back();
				} else {
					if ((int)v1.size() == 2) {
						ans.emplace_back(v1[0].second, v1[1].second);
					}
					return std::make_pair(0, u);
				}
			}
		};

		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i, -1);
			}
		}

		std::cout << ans.size() << "\n";
		for (auto p : ans) {
			std::cout << p.first + 1 << " " << p.second + 1 << "\n";
		}
	}
}