#include <bits/stdc++.h>

class binary_indexed_tree {
	int n;
	std::vector<int> c;

public:
	binary_indexed_tree(int _n) : n(_n), c(n + 1) {}

	void add(int x, int v) {
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int x) {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}

	int query(int l, int r) {
		return query(r) - query(l);
	}
};

const int P = 1000000007;

class tree {
	int n;
	std::vector<std::vector<int>> E;
	int idx;
	std::vector<int> fa, dep, sz, son, top, dfn;
	binary_indexed_tree T;

	void dfs(int u) {
		sz[u] = 1;
		son[u] = -1;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				dep[v] = dep[u] + 1;
				dfs(v);
				sz[u] += sz[v];
				if (son[u] == -1 || sz[v] > sz[son[u]]) {
					son[u] = v;
				}
			}
		}
	}

	void dfs(int u, int tp) {
		dfn[u] = idx++;
		top[u] = tp;
		if (son[u] != -1) {
			dfs(son[u], tp);
		}
		for (int v : E[u]) {
			if (v != fa[u] && v != son[u]) {
				dfs(v, v);
			}
		}
	}

	int query(int u, int v) {
		int s = 0;
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) {
				std::swap(u, v);
			}
			s += T.query(dfn[top[u]], dfn[u] + 1);
			u = fa[top[u]];
		}
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		s += T.query(dfn[v], dfn[u] + 1);
		return s;
	}

public:
	tree(std::vector<std::vector<int>> _E) : n(_E.size()), E(_E), idx(0), 
	                                         fa(n), dep(n), sz(n), son(n), top(n), dfn(n), T(n) {
		fa[0] = -1;
		dep[0] = 0;
		dfs(0);
		dfs(0, 0);
	}
	
	int get_ans(std::vector<int> S, int m, int r) {
		for (int x : S) {
			T.add(dfn[x], 1);
		}
		std::vector<int> c;
		for (int x : S) {
			c.push_back(query(x, r) - 1);
		}
		for (int x : S) {
			T.add(dfn[x], -1);
		}
		std::sort(c.begin(), c.end());
		std::vector<int> f(m + 1);
		f[0] = 1;
		for (int x : c) {
			std::vector<int> g(m + 1);
			for (int i = 1; i <= m; ++i) {
				g[i] = (1ll * std::max(i - x, 0) * f[i] + f[i - 1]) % P;
			}
			f.swap(g);
		}
		return std::accumulate(f.begin(), f.end(), 0ll) % P;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}
	tree T(E);
	while (q--) {
		int k, m, r;
		std::cin >> k >> m >> r;
		--r;
		std::vector<int> id(k);
		for (int &x : id) {
			std::cin >> x;
			--x;
		}
		std::cout << T.get_ans(id, m, r) << "\n";
	}
}