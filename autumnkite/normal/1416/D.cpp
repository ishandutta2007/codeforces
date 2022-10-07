#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	int n;
	std::vector<std::pair<int, int>> a;

	void build(int u, int l, int r) {
		if (l + 1 == r) {
			a[u] = std::make_pair(-1, l);
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid, r);
		a[u] = std::max(a[u << 1], a[u << 1 | 1]);
	}

	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u].first = v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		a[u] = std::max(a[u << 1], a[u << 1 | 1]);
	}

	std::pair<int, int> query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::max(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1) {
		build(1, 0, n);
	}

	void modify(int x, int v) {
		modify(1, 0, n, x, v);
	}

	std::pair<int, int> query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

class tree {
	int n;
	std::vector<int> a;
	std::vector<std::vector<int>> E;
	std::vector<int> fa;
	segment_tree T;

	int idx;
	std::vector<int> dfn, sz;

	void dfs(int u) {
		if (E[u].empty()) {
			dfn[u] = idx++;
			sz[u] = 1;
			T.modify(dfn[u], a[u]);
			return;
		}
		dfn[u] = idx;
		sz[u] = 0;
		for (int v : E[u]) {
			dfs(v);
			sz[u] += sz[v];
		}
	}

public:
	tree(std::vector<int> _a) : n(_a.size()), a(_a), E(n), fa(n), T(n) {
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
		E.push_back({x, y});
		fa.push_back(n);
		fa[x] = fa[y] = n++;
		return true;
	}

	void build() {
		dfn.resize(n), sz.resize(n);
		idx = 0;
		for (int i = 0; i < n; ++i) {
			if (find(i) == i) {
				dfs(i);
			}
		}
	}

	int get_ans(int u) {
		auto tmp = T.query(dfn[u], dfn[u] + sz[u]);
		if (tmp.first != -1) {
			T.modify(tmp.second, -1);
		}
		return tmp.first;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	std::vector<std::pair<int, int>> E(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> E[i].first >> E[i].second;
		--E[i].first, --E[i].second;
	}
	std::vector<bool> ex(m, true);

	std::vector<std::pair<int, int>> Q(q);
	for (int i = 0; i < q; ++i) {
		std::cin >> Q[i].first >> Q[i].second;
		--Q[i].second;
		if (Q[i].first == 2) {
			ex[Q[i].second] = false;
		}
	}

	tree T(a);
	for (int i = 0; i < m; ++i) {
		if (ex[i]) {
			T.merge(E[i].first, E[i].second);
		}
	}
	std::vector<int> nd;
	for (int i = q - 1; i >= 0; --i) {
		if (Q[i].first == 1) {
			nd.push_back(T.find(Q[i].second));
		} else {
			T.merge(E[Q[i].second].first, E[Q[i].second].second);
		}
	}

	T.build();
	std::reverse(nd.begin(), nd.end());
	for (int x : nd) {
		std::cout << T.get_ans(x) + 1 << "\n";
	}
}