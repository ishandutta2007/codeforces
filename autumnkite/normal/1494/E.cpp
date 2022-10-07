#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::map<int, char>> E(n);
	std::set<std::pair<int, int>> S1, S2;
	while (m--) {
		char op;
		std::cin >> op;
		if (op == '+') {
			int u, v;
			char c;
			std::cin >> u >> v >> c;
			--u, --v;
			E[u][v] = c;
			if (E[v].count(u)) {
				S1.emplace(std::min(u, v), std::max(u, v));
				if (E[v][u] == c) {
					S2.emplace(std::min(u, v), std::max(u, v));
				}
			}
		} else if (op == '-') {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			E[u].erase(v);
			S1.erase(std::make_pair(std::min(u, v), std::max(u, v)));
			S2.erase(std::make_pair(std::min(u, v), std::max(u, v)));
		} else {
			int k;
			std::cin >> k;
			--k;
			if (!S2.empty() || (!(k & 1) && !S1.empty())) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
}