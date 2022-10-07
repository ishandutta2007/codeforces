#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].emplace_back(v, i);
		E[v].emplace_back(u, i);
	}

	int cnt = 0;
	for (int u = 0; u < n; ++u) {
		cnt += E[u].size() & 1;
	}

	std::vector<int> hd(n);
	std::vector<bool> vis(m);
	std::vector<int> ans;

	std::function<void(int)> dfs = [&](int u) {
		while (hd[u] < (int)E[u].size()) {
			int v = E[u][hd[u]].first, id = E[u][hd[u]].second;
			++hd[u];
			if (!vis[id]) {
				vis[id] = true;
				dfs(v);
			}
		}
		ans.push_back(u);
	};

	auto get = [&](int u) {
		std::vector<int> v;
		for (auto p : E[u]) {
			if (vis[p.second]) {
				v.push_back(p.first);
			}
		}
		std::fill(hd.begin(), hd.end(), 0);
		ans.clear();
		dfs(u);
		if ((int)ans.size() - 1 == m - (int)v.size()) {
			ans.push_back(-2);
			for (int p : v) {
				ans.push_back(p);
				ans.push_back(u);
			}
			return true;
		} else {
			return false;
		}
	};

	for (int u = 0; u < n; ++u) {
		int tcnt = cnt - (E[u].size() & 1);
		for (auto p : E[u]) {
			if (E[p.first].size() & 1) {
				--tcnt;
			}
		}
		if (tcnt >= 2) {
			continue;
		}
		std::fill(vis.begin(), vis.end(), false);
		for (auto p : E[u]) {
			if (E[p.first].size() & 1) {
				vis[p.second] = true;
			}
		}
		if (get(u)) {
			std::cout << ans.size() << "\n";
			for (int v : ans) {
				std::cout << v + 1 << " ";
			}
			std::cout << "\n";
			return 0;
		}
		if (tcnt == 1) {
			continue;
		}
		for (auto q : E[u]) {
			if (E[q.first].size() & 1) {
				std::fill(vis.begin(), vis.end(), false);
				for (auto p : E[u]) {
					if (p != q && E[p.first].size() & 1) {
						vis[p.second] = true;
					}
				}
				if (get(u)) {
					std::cout << ans.size() << "\n";
					for (int v : ans) {
						std::cout << v + 1 << " ";
					}
					std::cout << "\n";
					return 0;
				}
			}
		}
	}
	std::cout << 0 << "\n";
}