#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::vector<std::vector<int>> f(n, std::vector<int>(2 * k, 0));
	std::function<void(int, int)> get_f = [&](int u, int fa) {
		f[u][0] = a[u];
		for (int v : E[u]) {
			if (v != fa) {
				get_f(v, u);
				for (int i = 0; i < 2 * k; ++i) {
					f[u][(i + 1) % (2 * k)] ^= f[v][i];
				}
			}
		}
	};

	get_f(0, -1);

	std::vector<std::vector<int>> g(n, std::vector<int>(2 * k, 0));
	std::function<void(int, int)> get_g = [&](int u, int fa) {
		for (int v : E[u]) {
			if (v != fa) {
				for (int i = 0; i < 2 * k; ++i) {
					g[v][(i + 1) % (2 * k)] ^= f[u][i] ^ f[v][(i + 2 * k - 1) % (2 * k)] ^ g[u][i];
				}
				get_g(v, u);
			}
		}
	};

	get_g(0, -1);

	for (int u = 0; u < n; ++u) {
		int ans = 0;
		for (int i = k; i < 2 * k; ++i) {
			ans ^= f[u][i] ^ g[u][i];
		}
		std::cout << (ans > 0) << " ";
	}
	std::cout << "\n";
}