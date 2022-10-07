#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		if (u == v) {
			continue;
		}
		E[u].push_back(v);
	}

	int idx = 0;
	std::vector<int> dfn(n, -1), low(n);
	std::vector<bool> vis(n);
	std::vector<int> sta;
	bool flag = true;
	std::vector<bool> col(n);

	std::function<void(int)> tarjan = [&](int u) {
		dfn[u] = low[u] = idx++;
		vis[u] = true, sta.push_back(u);
		for (int v : E[u]) {
			if (dfn[v] == -1) {
				tarjan(v);
				low[u] = std::min(low[u], low[v]);
			} else if (vis[v]) {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
		if (dfn[u] == low[u]) {
			int v;
			do {
				v = sta.back();
				col[v] = flag;
				sta.pop_back();
			} while (v != u);
			flag = false;
		}
	};

	for (int i = 0; i < n; ++i) {
		if (dfn[i] == -1) {
			tarjan(i);
		}
	}
	std::vector<int> X, Y;
	for (int i = 0; i < n; ++i) {
		if (col[i]) {
			X.push_back(i);
		} else {
			Y.push_back(i);
		}
	}

	if (X.empty() || Y.empty()) {
		std::cout << "No\n";
	} else {
		std::cout << "Yes\n";
		std::cout << X.size() << " " << Y.size() << "\n";
		for (int u : X) {
			std::cout << u + 1 << " ";
		}
		std::cout << "\n";
		for (int u : Y) {
			std::cout << u + 1 << " ";
		}
		std::cout << "\n";
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