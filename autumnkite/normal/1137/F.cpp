#include <bits/stdc++.h>

class BIT {
	int n;
	std::vector<int> c;

	int query(int x) const {
		int s = 0;
		for (; x; x ^= x & -x) {
			s += c[x];
		}
		return s;
	}

public:
	BIT(int _n) : n(_n), c(n + 1) {}

	void add(int x, int v) {
		for (++x; x <= n; x += x & -x) {
			c[x] += v;
		}
	}

	int query(int l, int r) const {
		return query(r) - query(l);
	}
};

class LinkCutTree {
	struct Sons {
		int ls, rs;

		Sons() : ls(-1), rs(-1) {}
		Sons(int _ls, int _rs) : ls(_ls), rs(_rs) {}

		int &operator[](int k) {
			if (k == 0) {
				return ls;
			} else {
				return rs;
			}
		}

		const int &operator[](int k) const {
			if (k == 0) {
				return ls;
			} else {
				return rs;
			}
		}
	};

	int n;
	std::vector<int> fa;
	std::vector<Sons> son;
	std::vector<int> sz;
	std::vector<bool> rev;
	std::vector<int> val, tag;

	bool is_root(int u) {
		return fa[u] == -1 || (son[fa[u]].ls != u && son[fa[u]].rs != u);
	}

	void up(int u) {
		sz[u] = 1;
		if (son[u].ls != -1) {
			sz[u] += sz[son[u].ls];
		}
		if (son[u].rs != -1) {
			sz[u] += sz[son[u].rs];
		}
	}

	int dir(int u) {
		return son[fa[u]].rs == u;
	}

	void change(int u, int k, int v) {
		son[u][k] = v;
		if (v != -1) {
			fa[v] = u;
		}
	}

	void rotate(int u) {
		int v = fa[u], k = dir(u);
		change(v, k, son[u][k ^ 1]);
		if (!is_root(v)) {
			change(fa[v], dir(v), u);
		} else {
			fa[u] = fa[v];
		}
		change(u, k ^ 1, v);
		up(v), up(u);
	}

	void reverse(int u) {
		if (u != -1) {
			std::swap(son[u].ls, son[u].rs);
			rev[u] = !rev[u];
		}
	}

	void modify(int u, int v) {
		if (u != -1) {
			val[u] = tag[u] = v;
		}
	}

	void down(int u) {
		if (rev[u]) {
			reverse(son[u].ls);
			reverse(son[u].rs);
			rev[u] = false;
		}
		if (tag[u] != -1) {
			modify(son[u].ls, tag[u]);
			modify(son[u].rs, tag[u]);
			tag[u] = -1;
		}
	}

	void splay(int u) {
		static std::vector<int> sta;
		sta.push_back(u);
		for (int i = u; !is_root(i); i = fa[i]) {
			sta.push_back(fa[i]);
		}
		while (!sta.empty()) {
			down(sta.back());
			sta.pop_back();
		}
		while (!is_root(u)) {
			int v = fa[u];
			if (is_root(v)) {
				rotate(u);
				break;
			}
			if (dir(u) == dir(v)) {
				rotate(v);
			} else {
				rotate(u);
			}
			rotate(u);
		}
	}

public:
	LinkCutTree(std::vector<int> v)
	  : n(v.size()), fa(n, -1), son(n), sz(n, 1), rev(n), val(v), tag(n, -1) {}

	void link(int u, int v) {
		fa[u] = v;
	}

	void access(int u) {
		int v = -1;
		while (u != -1) {
			splay(u);
			son[u].rs = v;
			up(u);
			v = u, u = fa[u];
		}
	}

	void make_root(int u, int nw, BIT &T) {
		int v = -1;
		while (u != -1) {
			splay(u);
			T.add(val[u], -(son[u].ls != -1 ? sz[son[u].ls] : 0) - 1);
			son[u].rs = v;
			up(u);
			v = u, u = fa[u];
		}
		T.add(nw, sz[v]);
		modify(v, nw);
		reverse(v);
	}

	int query(int u, const BIT &T) {
		splay(u);
		return T.query(0, val[u] + 1) - (son[u].ls != -1 ? sz[son[u].ls] : 0);
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

	std::vector<int> mx(n), fa(n, -1);
	std::function<void(int)> dfs = [&](int u) {
		mx[u] = u;
		for (int v : E[u]) {
			if (v != fa[u]) {
				fa[v] = u;
				dfs(v);
				mx[u] = std::max(mx[u], mx[v]);
			}
		}
	};
	dfs(n - 1);
	
	LinkCutTree T(mx);
	BIT S(n + q);
	for (int i = 0; i < n; ++i) {
		S.add(mx[i], 1);
		if (fa[i] != -1) {
			T.link(i, fa[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		T.access(i);
	}

	int now = n - 1;
	while (q--) {
		std::string op;
		std::cin >> op;
		if (op == "up") {
			int u;
			std::cin >> u;
			--u;
			T.make_root(u, now++, S);
		} else if (op == "when") {
			int u;
			std::cin >> u;
			--u;
			std::cout << T.query(u, S) << "\n";
		} else {
			int u, v;
			std::cin >> u >> v;
			--u, --v;
			std::cout << (T.query(u, S) < T.query(v, S) ? u + 1 : v + 1) << "\n";
		}
	}
}