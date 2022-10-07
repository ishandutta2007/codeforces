#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n, m;
	std::cin >> n >> m;
	std::vector<std::set<int>> S(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		S[u].insert(v);
		S[v].insert(u);
	}

	auto calc = [&](int u) {
		return !S[u].empty() && u < *S[u].rbegin();
	};

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += calc(i);
	}
	int q;
	std::cin >> q;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			ans -= calc(u) + calc(v);
			S[u].insert(v);
			S[v].insert(u);
			ans += calc(u) + calc(v);
		} else if (op == 2) {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			ans -= calc(u) + calc(v);
			S[u].erase(v);
			S[v].erase(u);
			ans += calc(u) + calc(v);
		} else {
			std::cout << n - ans << "\n";
		}
	}
}