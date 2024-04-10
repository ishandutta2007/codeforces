#include <bits/stdc++.h>

const int P = 998244353;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> fa(n, -1);
	std::vector<std::vector<int>> E(n);
	for (int i = 1; i < n; ++i) {
		std::cin >> fa[i];
		--fa[i];
		E[fa[i]].push_back(i);
	}
	
	std::vector<int> f0(n), f1(n), f2(n);
	std::function<void(int)> dfs = [&](int u) {
		if (E[u].empty()) {
			f2[u] = 1;
			return;
		}
		f0[u] = 1;
		for (int v : E[u]) {
			dfs(v);
			f2[u] = (1ll * f2[u] * (f0[v] + f1[v] + 2ll * f2[v]) + 1ll * f1[u] * (f1[v] + f2[v])) % P;
			f1[u] = (1ll * f1[u] * (f0[v] + f2[v]) + 1ll * f0[u] * (f1[v] + f2[v])) % P;
			f0[u] = 1ll * f0[u] * (f0[v] + f2[v]) % P;
		}
	};
	dfs(0);
	std::cout << (f0[0] + f2[0]) % P << "\n";
}