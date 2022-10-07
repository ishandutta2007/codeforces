#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> edge;
	std::vector<std::vector<std::pair<int, int>>> E(n + 1);
	std::vector<int> cur(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		edge.emplace_back(u, v);
		E[u].emplace_back(v, i);
		E[v].emplace_back(u, i);
	}
	int idx = m;
	for (int i = 0; i < n; ++i) {
		if (E[i].size() & 1) {
			E[i].emplace_back(n, idx);
			E[n].emplace_back(i, idx);
			++idx;
		}
	}

	std::vector<bool> vis(idx);
	std::vector<int> path;

	std::function<void(int)> dfs = [&](int u) {
		while (cur[u] < (int)E[u].size()) {
			auto p = E[u][cur[u]++];
			if (!vis[p.second]) {
				vis[p.second] = true;
				dfs(p.first);
				path.push_back(p.second);
			}
		}
	};

	std::vector<std::pair<int, int>> ans;
	for (int u = 0; u <= n; ++u) {
		path.clear();
		dfs(u);
		int lst = 0;
		for (int i = 0; i <= (int)path.size(); ++i) {
			if (i == (int)path.size() || path[i] >= m) {
				for (int j = lst; j < i; j += 2) {
					ans.emplace_back(edge[path[j]].first, edge[path[j]].second);
				}
				if (lst < i && (i - 1 - lst) & 1) {
					ans.emplace_back(edge[path[i - 1]].first, edge[path[i - 1]].second);
				}
				lst = i + 1;
			}
		}
	}
	std::cout << ans.size() << "\n";
	for (auto [x, y] : ans) {
		std::cout << x + 1 << " " << y + 1 << "\n";
	}
}