#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	auto solve = [&](int c) {
		std::array<std::queue<int>, 2> Q;
		std::vector<int> deg(n);
		std::vector<int> col(a);
		for (int i = 0; i < n; ++i) {
			deg[i] = E[i].size();
			if (deg[i] <= 1) {
				if (col[i] == -1) {
					col[i] = c;
				}
				Q[col[i]].push(i);
			}
		}
		int ans = 0;
		while (!Q[0].empty() || !Q[1].empty()) {
			while (!Q[c].empty()) {
				int u = Q[c].front();
				Q[c].pop();
				for (int v : E[u]) {
					--deg[v];
					if (deg[v] == 1) {
						if (col[v] == -1) {
							col[v] = col[u];
						}
						Q[col[v]].push(v);
					}
				}
			}
			c ^= 1;
			++ans;
		}
		return ans;
	};

	std::cout << std::min(solve(0), solve(1)) << "\n";
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