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

	std::vector<std::pair<int, int>> ans;
	std::vector<std::vector<int>> G(n);

	std::function<bool(int, int)> dfs = [&](int u, int fa) {
		std::vector<int> son;
		for (int v : E[u]) {
			if (v != fa) {
				if (!dfs(v, u)) {
					son.push_back(v);
				}
			}
		}
		for (int i = 0; i < 2 && i < (int)son.size(); ++i) {
			G[u].push_back(son[i]);
			G[son[i]].push_back(u);
		}
		for (int i = 2; i < (int)son.size(); ++i) {
			ans.emplace_back(u, son[i]);
		}
		if ((int)son.size() >= 2 && fa != -1) {
			ans.emplace_back(u, fa);
			return true;
		} else {
			return false;
		}
	};

	dfs(0, -1);

	std::vector<std::pair<int, int>> chain;
	for (int i = 0; i < n; ++i) {
		assert((int)G[i].size() <= 2);
		if ((int)G[i].size() == 0) {
			chain.emplace_back(i, i);
			continue;
		};
		if ((int)G[i].size() == 1) {
			int u = G[i][0], v = i;
			while ((int)G[u].size() == 2) {
				int t = u;
				u = G[u][0] ^ G[u][1] ^ v;
				v = t;
			}
			if (i < u) {
				chain.emplace_back(i, u);
			}
			continue;
		};
	}

	std::cout << ans.size() << "\n";
	for (int i = 0; i < (int)ans.size(); ++i) {
		std::cout << ans[i].first + 1 << " " << ans[i].second + 1 << " "
		          << chain[i].second + 1 << " " << chain[i + 1].first + 1 << "\n";
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