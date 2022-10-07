#include <bits/stdc++.h>

class DSU {
	std::vector<int> fa, sz;
	std::vector<int> sta;

public:
	DSU(int n) : fa(n), sz(n), sta(0) {
		for (int i = 0; i < n; ++i) {
			fa[i] = i;
			sz[i] = 1;
		}
	}

	int find(int x) {
		return fa[x] == x ? x : find(fa[x]);
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			std::swap(x, y);
		}
		fa[y] = x;
		sz[x] += sz[y];
		sta.push_back(y);
		return true;
	}

	void undo() {
		assert(!sta.empty());
		int y = sta.back(), x = fa[sta.back()];
		sz[x] -= sz[y];
		fa[y] = y;
		sta.pop_back();
	}

	int get_size(int u) {
		return sz[find(u)];
	}
};

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<std::vector<std::pair<int, int>>> a;
	std::vector<int> Q;

	void modify(int u, int l, int r, int L, int R, int x, int y) {
		if (L <= l && r <= R) {
			a[u].emplace_back(x, y);
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (L < mid) {
			modify(u << 1, l, mid, L, R, x, y);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid, r, L, R, x, y);
		}
	}

	void get_ans(int u, int l, int r, std::vector<int> &ans, DSU &D) {
		int cnt = 0;
		for (auto [x, y] : a[u]) {
			cnt += D.merge(x, y);
		}
		if (l + 1 == r) {
			ans[l] = D.get_size(Q[l]);
		} else {
			int mid = (l + r + 1) >> 1;
			get_ans(u << 1, l, mid, ans, D);
			get_ans(u << 1 | 1, mid, r, ans, D);
		}
		for (int i = 0; i < cnt; ++i) {
			D.undo();
		}
	}

public:
	SegmentTree(std::vector<int> _Q) : n(_Q.size()), a(enlarge(n) << 1), Q(_Q) {}

	void add_edge(int l, int r, int x, int y) {
		if (l <= r) {
			modify(1, 0, n, l, r, x, y);
		}
	}

	std::vector<int> get_ans(int all) {
		DSU D(all);
		std::vector<int> ans(n);
		get_ans(1, 0, n, ans, D);
		return ans;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q, k;
	std::cin >> n >> q >> k;
	std::vector<int> Q;
	std::vector<int> D;
	std::vector<std::vector<std::tuple<int, int, int>>> E(1);
	int day = 0;
	for (int i = 0; i < q; ++i) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x, y;
			std::cin >> x >> y;
			--x, --y;
			E.back().emplace_back(x, y, day);
		} else if (op == 2) {
			int x;
			std::cin >> x;
			--x;
			Q.push_back(x);
			D.push_back(day);
			E.emplace_back();
		} else {
			++day;
		}
	}
	SegmentTree T(Q);
	for (int i = 0; i <= (int)Q.size(); ++i) {
		for (auto [x, y, d] : E[i]) {
			T.add_edge(i, std::lower_bound(D.begin(), D.end(), d + k) - D.begin(), x, y);
		}
	}
	std::vector<int> ans = T.get_ans(n);
	for (int v : ans) {
		std::cout << v << "\n";
	}
}