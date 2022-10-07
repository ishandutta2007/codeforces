#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa;

public:
	DSU(int n) : fa(n) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : (fa[x] = find(fa[x]));
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		fa[y] = x;
		return true;
	}
};

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::set<int>> G(n);
	std::vector<int> deg(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		G[u].insert(v);
		G[v].insert(u);
		++deg[u], ++deg[v];
	}
	
	DSU D(n);
	std::vector<std::vector<int>> E(n);
	
	auto add = [&](int u) {
		for (int i = 0; i < n; ++i) {
			if (!G[u].count(i) && D.merge(u, i)) {
				E[u].push_back(i);
				E[i].push_back(u);
			}
		}
	};

	int mn = std::min_element(deg.begin(), deg.end()) - deg.begin();
	add(mn);
	for (int x : G[mn]) {
		add(x);
	}

	std::vector<int> p(n, -1), q(n, -1);
	int idx = 0;

	std::function<void(int, int, bool)> dfs = [&](int u, int fa, bool flag) {
		if (flag) {
			p[u] = idx;
			q[fa] = idx, p[fa] = ++idx;
		}
		for (int v : E[u]) {
			if (v != fa) {
				if ((int)E[v].size() == 1) {
					if (!flag) {
						p[u] = idx;
						flag = true;
					}
					q[v] = idx, p[v] = ++idx;
				}
			}
		}
		if (flag) {
			q[u] = idx;
			++idx;
		}
		for (int v : E[u]) {
			if (v != fa && (int)E[v].size() > 1) {
				dfs(v, u, !flag);
				flag = true;
			}
		}
		if (!flag) {
			p[u] = q[u] = idx;
			++idx;
		}
	};

	for (int i = 0; i < n; ++i) {
		if (p[i] == -1) {
			dfs(i, -1, false);
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << p[i] + 1 << " ";
	}
	std::cout << "\n";
	for (int i = 0; i < n; ++i) {
		std::cout << q[i] + 1 << " ";
	}
	std::cout << "\n";
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