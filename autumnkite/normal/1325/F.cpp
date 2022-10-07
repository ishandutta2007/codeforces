#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> G(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		G[u].push_back(v), G[v].push_back(u);
	}

	const int B = sqrt(n) + 1 - 1e-9;

	std::vector<int> fa(n, -1), dep(n, -1);
	std::vector<int> cyc;
	std::function<void(int)> dfs = [&](int u) {
		for (int v : G[u]) {
			if (dep[v] == -1) {
				fa[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
			} else if (dep[u] - dep[v] >= B - 1 && cyc.empty()) {
				for (int i = u; i != v; i = fa[i]) {
					cyc.push_back(i);
				}
				cyc.push_back(v);
			}
		}
	};

	for (int i = 0; i < n; ++i) {
		if (dep[i] == -1) {
			dep[i] = 0;
			dfs(i);
		}
	}

	if (!cyc.empty()) {
		std::cout << 2 << "\n";
		std::cout << cyc.size() << "\n";
		for (int v : cyc) {
			std::cout << v + 1 << " ";
		}
		std::cout << "\n";
		return 0;
	}

	std::vector<std::vector<int>> ind(B - 1);
	for (int i = 0; i < n; ++i) {
		ind[dep[i] % (B - 1)].push_back(i);
	}
	for (int i = 0; i < B - 1; ++i) {
		if ((int)ind[i].size() >= B) {
			std::cout << 1 << "\n";
			ind[i].resize(B);
			for (int v : ind[i]) {
				std::cout << v + 1 << " ";
			}
			std::cout << "\n";
			return 0;
		}
	}
}