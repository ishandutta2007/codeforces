#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int m;
	std::cin >> m;
	std::vector<int> p(m);
	for (int &x : p) {
		std::cin >> x;
		--x;
	}

	std::vector<int> dis(n, n);
	auto bfs = [&]() {
		std::vector<int> Q;
		for (int x : p) {
			Q.push_back(x);
			dis[x] = 0;
		}
		for (int i = 0; i < (int)Q.size(); ++i) {
			int u = Q[i];
			for (int v : E[u]) {
				if (dis[v] == n) {
					dis[v] = dis[u] + 1;
					Q.push_back(v);
				}
			}
		}
	};
	bfs();

	std::vector<bool> vis(n);
	std::vector<int> sz(n);
	std::function<void(int, int, std::vector<int> &)> get_sz = [&](int u, int fa, std::vector<int> &id) {
		id.push_back(u);
		sz[u] = 1;
		for (int v : E[u]) {
			if (!vis[v] && v != fa) {
				get_sz(v, u, id);
				sz[u] += sz[v];
			}
		}
	};
	std::vector<int> dep(n);
	std::function<void(int, int)> get_dep = [&](int u, int fa) {
		for (int v : E[u]) {
			if (!vis[v] && v != fa) {
				dep[v] = dep[u] + 1;
				get_dep(v, u);
			}
		}
	};
	std::vector<int> ans(n);
	auto upd = [&](int &a, int b) {
		a = std::max(a, b);
	};
	std::function<void(int)> divide = [&](int rt) {
		std::vector<int> id;
		get_sz(rt, -1, id);
		int all = sz[rt], c = -1;
		for (int u : id) {
			int mx = 0;
			for (int v : E[u]) {
				if (!vis[v] && sz[v] < sz[u]) {
					mx = std::max(mx, sz[v]);
				}
			}
			mx = std::max(mx, all - sz[u]);
			if (mx <= all / 2) {
				c = u;
			}
		}
		dep[c] = 0, get_dep(c, -1);
		std::vector<int> mx(id.size() + 1);
		for (int u : id) {
			upd(mx[std::max(0, std::min(dis[u] - dep[u], (int)id.size()))], dis[u]);
		}
		for (int i = (int)id.size(); i >= 1; --i) {
			upd(mx[i - 1], mx[i]);
		}
		for (int u : id) {
			upd(ans[u], mx[dep[u] + 1]);
		}
		vis[c] = true;
		for (int u : E[c]) {
			if (!vis[u]) {
				divide(u);
			}
		}
	};
	divide(0);
	for (int x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}