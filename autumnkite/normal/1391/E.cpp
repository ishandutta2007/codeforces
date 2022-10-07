#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<bool> vis(n);
	std::vector<int> fa(n), dep(n);
	std::function<void(int)> dfs = [&](int u) {
		vis[u] = true;
		for (int v : E[u]) {
			if (!vis[v]) {
				fa[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
			}
		}
	};
	fa[0] = -1, dep[0] = 0;
	dfs(0);

	int u = std::max_element(dep.begin(), dep.end()) - dep.begin();
	int D = dep[u] + 1;
	if (D >= (n + 1) / 2) {
		std::cout << "PATH\n";
		std::vector<int> ans;
		for (int i = u; i != -1; i = fa[i]) {
			ans.push_back(i);
		}
		std::cout << ans.size() << "\n";
		for (int v : ans) {
			std::cout << v + 1 << " ";
		}
		std::cout << "\n";
		return;
	}

	std::vector<std::vector<int>> id(D);
	for (int i = 0; i < n; ++i) {
		id[dep[i]].push_back(i);
	}
	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < D; ++i) {
		for (int j = 0; j + 1 < (int)id[i].size(); j += 2) {
			ans.emplace_back(id[i][j], id[i][j + 1]);
		}
	}
	std::cout << "PAIRING\n";
	std::cout << ans.size() << "\n";
	for (auto p : ans) {
		std::cout << p.first + 1 << " " << p.second + 1 << "\n";
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