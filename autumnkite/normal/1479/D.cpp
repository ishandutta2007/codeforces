#include <bits/stdc++.h>

std::mt19937_64 rnd(time(0));

class Tree {
	int n;
	std::vector<int> a;
	std::vector<std::vector<int>> E;
	std::vector<unsigned long long> val;

	std::vector<int> fa, dep, sz, son, top;

	struct Node {
		Node *ls, *rs;
		unsigned long long sum;

		Node() : ls(NULL), rs(NULL), sum(0) {}

		void up() {
			sum = 0;
			if (ls != NULL) {
				sum ^= ls->sum;
			}
			if (rs != NULL) {
				sum ^= rs->sum;
			}
		}
	};

	Node get(Node *u) {
		if (u == NULL) {
			return Node();
		} else {
			return *u;
		}
	}

	void modify(Node *&u, Node *_u, int l, int r, int x, unsigned long long v) {
		Node t = get(_u);
		u = new Node(t);
		if (l + 1 == r) {
			u->sum ^= v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u->ls, t.ls, l, mid, x, v);
		} else {
			modify(u->rs, t.rs, mid, r, x, v);
		}
		u->up();
	}

	int query(Node *u1, Node *u2, Node *u3, Node *u4, int l, int r, int L, int R) {
		Node s1 = get(u1), s2 = get(u2), s3 = get(u3), s4 = get(u4);
		if (L <= l && r <= R && (s1.sum ^ s2.sum ^ s3.sum ^ s4.sum) == 0) {
			return -1;
		}
		if (l + 1 == r) {
			return l;
		}
		int mid = (l + r + 1) >> 1;
		int res = -1;
		if (L < mid && res == -1) {
			res = query(s1.ls, s2.ls, s3.ls, s4.ls, l, mid, L, R);
		}
		if (R > mid && res == -1) {
			res = query(s1.rs, s2.rs, s3.rs, s4.rs, mid, r, L, R);
		}
		return res;
	}

	std::vector<Node *> rt;

	void dfs(int u) {
		modify(rt[u], rt[u], 0, n, a[u], val[a[u]]);
		sz[u] = 1;
		son[u] = -1;
		for (int v : E[u]) {
			if (v != fa[u]) {
				rt[v] = rt[u];
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

	void get_top(int u, int tp) {
		top[u] = tp;
		if (son[u] != -1) {
			get_top(son[u], tp);
		}
		for (int v : E[u]) {
			if (v != fa[u] && v != son[u]) {
				get_top(v, v);
			}
		}
	}

	int LCA(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] > dep[top[v]]) {
				u = fa[top[u]];
			} else {
				v = fa[top[v]];
			}
		}
		return dep[u] < dep[v] ? u : v;
	}

public:
	Tree(std::vector<int> _a, std::vector<std::vector<int>> _E) :
	  n(_a.size()), a(_a), E(_E), val(n), fa(n), dep(n), sz(n), son(n), top(n), rt(n) {
		for (auto &v : val) {
			v = rnd();
		}
		fa[0] = -1, dfs(0);
		get_top(0, 0);
	}

	int get_ans(int u, int v, int l, int r) {
		int z = LCA(u, v);
		return query(rt[u], rt[v], rt[z], fa[z] == -1 ? NULL : rt[fa[z]], 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (int &v : a) {
		std::cin >> v;
		--v;
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	Tree T(a, E);
	while (q--) {
		int u, v, l, r;
		std::cin >> u >> v >> l >> r;
		--u, --v, --l;
		int ans = T.get_ans(u, v, l, r);
		if (ans == -1) {
			std::cout << -1 << "\n";
		} else {
			std::cout << ans + 1 << "\n";
		}
	}
}