#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> fa(n, -1);
	std::vector<std::vector<int>> son(n);
	for (int i = 1; i < n; ++i) {
		std::cin >> fa[i];
		son[fa[i]].push_back(i);
	}
	std::vector<int> dis(n, 0);
	for (int i = n - 1; i > 0; --i) {
		if (fa[i] != -1) {
			dis[fa[i]] = std::max(dis[fa[i]], dis[i] + 1);
		}
	}
	for (int i = 0; i < n; ++i) {
		std::sort(son[i].begin(), son[i].end(), [&](int u, int v) {
			return dis[u] < dis[v];
		});
	}

	std::vector<int> id;
	std::vector<int> ans;
	std::function<void(int)> dfs = [&](int u) {
		id.push_back(u);
		for (int v : son[u]) {
			dfs(v);
		}
		for (int i = 1; i < (int)son[u].size(); ++i) {
			for (int j = 0; j < dis[son[u][i - 1]] + 1; ++j) {
				ans.push_back(son[u][i]);
			}
		}
	};

	dfs(0);
	
	for (int i : id) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	std::cout << ans.size() << "\n";
	for (int i : ans) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}