#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, b;
		std::cin >> u >> v >> b;
		--u, --v;
		E[u].emplace_back(v, b);
		E[v].emplace_back(u, -b);
	}
	std::vector<int> col(n, -1);

	std::function<bool(int, int)> color = [&](int u, int c) {
		if (col[u] != -1) {
			return col[u] == c;
		}
		col[u] = c;
		for (auto [v, b] : E[u]) {
			if (!color(v, c ^ 1)) {
				return false;
			}
		}
		return true;
	};

	if (!color(0, 0) || std::find(col.begin(), col.end(), -1) != col.end()) {
		std::cout << "NO\n";
		return 0;
	}

	std::vector<std::vector<int>> dis(n, std::vector<int>(n, n));
	for (int i = 0; i < n; ++i) {
		dis[i][i] = 0;
	}
	auto upd = [&](int &a, int b) {
		a = std::min(a, b);
	};
	for (int u = 0; u < n; ++u) {
		if (col[u] == 0) {
			for (auto [v, b] : E[u]) {
				if (b == 0) {
					upd(dis[u][v], 0);
					upd(dis[v][u], 1);
				} else if (b == 1) {
					upd(dis[u][v], 0);
					upd(dis[v][u], 0);
				} else {
					upd(dis[u][v], -1);
					upd(dis[v][u], 1);
				}
			}
		}
	}
	for (int k = 0; k < n; ++k) {
		if (dis[k][k] < 0) {
			std::cout << "NO\n";
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int ans = -1, id = -1;
	for (int i = 0; i < n; ++i) {
		int mx = 2 * dis[i][i] + col[i], mn = mx;
		for (int j = 0; j < n; ++j) {
			mx = std::max(mx, 2 * dis[i][j] + col[j]);
			mn = std::min(mn, 2 * dis[i][j] + col[j]);
		}
		if (mn >= 0 && mx - mn > ans) {
			ans = mx - mn;
			id = i;
		}
	}
	if (ans == -1) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
		std::cout << ans << "\n";
		for (int i = 0; i < n; ++i) {
			std::cout << 2 * dis[id][i] + col[i] << " ";
		}
		std::cout << "\n";
	}
}