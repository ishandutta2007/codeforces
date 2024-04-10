#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<std::pair<int, int>>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		std::cin >> u >> v >> c;
		--u, --v;
		E[v].emplace_back(u, c);
	}

	std::vector<int> dis(n, n);
	std::vector<int> col(n, -1);
	std::vector<int> Q;
	col[n - 1] = 0, dis[n - 1] = 0;
	Q.push_back(n - 1);
	for (int i = 0; i < (int)Q.size(); ++i) {
		int u = Q[i];
		for (auto [v, c] : E[u]) {
			if (dis[v] == n) {
				if (col[v] == -1) {
					col[v] = !c;
				} else if (col[v] == c) {
					dis[v] = dis[u] + 1;
					Q.push_back(v);
				}
			}
		}
	}
	if (dis[0] == n) {
		std::cout << -1 << "\n";
	} else {
		std::cout << dis[0] << "\n";
	}
	for (int i = 0; i < n; ++i) {
		if (col[i] == -1) {
			col[i] = 0;
		}
		std::cout << col[i];
	}
	std::cout << "\n";
}