#include <bits/stdc++.h>

const long long INF = 1ll << 60;

struct line {
	long long k, b;

	line(long long _k, long long _b) : k(_k), b(_b) {}
	line() : k(0), b(0) {}

	long long get(long long x) const {
		return k * x + b;
	}

	void swap(line &a) {
		std::swap(k, a.k);
		std::swap(b, a.b);
	}
};

class segment_tree {
	const int LIM;
	
	struct node {
		node *ls, *rs;
		line v;

		node() : ls(NULL), rs(NULL) {}
	};

	node *rt;

	void insert(node *&u, int l, int r, line v) {
		if (u == NULL) {
			u = new node();
			u->v = v;
			return;
		}
		if (u->v.get(l) <= v.get(l) && u->v.get(r) <= v.get(r)) {
			return;
		}
		if (u->v.get(l) >= v.get(l) && u->v.get(r) >= v.get(r)) {
			u->v = v;
			return;
		}
		int mid = l + (r - l + 1) / 2;
		if (v.get(mid) < u->v.get(mid)) {
			v.swap(u->v);
		}
		if (v.get(l) < u->v.get(l)) {
			insert(u->ls, l, mid, v);
		} else {
			insert(u->rs, mid + 1, r, v);
		}
	}

	node *merge(node *u, node *v, int l, int r) {
		if (u == NULL) {
			return v;
		}
		if (v == NULL) {
			return u;
		}
		int mid = l + (r - l + 1) / 2;
		u->ls = merge(u->ls, v->ls, l, mid);
		u->rs = merge(u->rs, v->rs, mid + 1, r);
		insert(u, l, r, v->v);
		return u;
	}

	long long query(node *u, int l, int r, int x) {
		if (u == NULL) {
			return INF;
		}
		if (l == r) {
			return u->v.get(x);
		}
		int mid = l + (r - l + 1) / 2;
		if (x <= mid) {
			return std::min(u->v.get(x), query(u->ls, l, mid, x));
		} else {
			return std::min(u->v.get(x), query(u->rs, mid + 1, r, x));
		}
	}

public:
	segment_tree(int _LIM = 1000000000) : LIM(_LIM), rt(NULL) {}

	void insert(const line &v) {
		insert(rt, -LIM, LIM, v);
	}

	void merge(const segment_tree &v) {
		rt = merge(rt, v.rt, -LIM, LIM);
	}

	long long query(int x) {
		return query(rt, -LIM, LIM, x);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n), b(n);
	for (int &x : a) {
		std::cin >> x;
	}
	for (int &x : b) {
		std::cin >> x;
	}
	std::vector<std::vector<int>> E(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u, --v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	std::vector<segment_tree> T(n, 100000);
	std::vector<long long> f(n);
	std::function<void(int, int)> dfs = [&](int u, int fa) {
		int d = 0;
		for (int v : E[u]) {
			if (v != fa) {
				dfs(v, u);
				T[u].merge(T[v]);
				++d;
			}
		}
		f[u] = d ? T[u].query(a[u]) : 0;
		T[u].insert(line(b[u], f[u]));
	};
	dfs(0, -1);
	
	for (auto &x : f) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}