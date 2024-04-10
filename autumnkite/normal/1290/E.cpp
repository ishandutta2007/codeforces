#include <bits/stdc++.h>

struct node {
	int mx, se, cmx;
	int cnt;
	long long sum;

	node() : mx(0), se(-1), cmx(0), cnt(0), sum(0) {}
	node(int v) : mx(v), se(-1), cmx(1), cnt(1), sum(v) {}
};

node operator+(const node &a, const node &b) {
	node res;
	if (a.mx == b.mx) {
		res.mx = a.mx;
		res.se = std::max(a.se, b.se);
		res.cmx = a.cmx + b.cmx;
	} else if (a.mx > b.mx) {
		res.mx = a.mx;
		res.se = std::max(a.se, b.mx);
		res.cmx = a.cmx;
	} else {
		res.mx = b.mx;
		res.se = std::max(a.mx, b.se);
		res.cmx = b.cmx;
	}
	res.cnt = a.cnt + b.cnt;
	res.sum = a.sum + b.sum;
	return res;
}

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	int n;
	std::vector<node> a;
	std::vector<int> tag, mxtag;

	void node_add(int u, int v) {
		a[u].mx += v;
		a[u].se += v;
		a[u].sum += 1ll * v * a[u].cnt;
		tag[u] += v;
	}

	void node_add_mx(int u, int v) {
		a[u].mx += v;
		a[u].sum += 1ll * v * a[u].cmx;
		mxtag[u] += v;
	}

	void down(int u) {
		if (tag[u]) {
			node_add(u << 1, tag[u]);
			node_add(u << 1 | 1, tag[u]);
			tag[u] = 0;
		}
		if (mxtag[u]) {
			int lmx = a[u << 1].mx, rmx = a[u << 1 | 1].mx;
			if (lmx >= rmx) {
				node_add_mx(u << 1, mxtag[u]);
			}
			if (rmx >= lmx) {
				node_add_mx(u << 1 | 1, mxtag[u]);
			}
			mxtag[u] = 0;
		}
	}

	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u] = node(v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void add(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			node_add(u, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (L < mid) {
			add(u << 1, l, mid, L, R, v);
		}
		if (mid < R) {
			add(u << 1 | 1, mid, r, L, R, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void chmin(int u, int l, int r, int L, int R, int v) {
		if (a[u].mx <= v) {
			return;
		}
		if (L <= l && r <= R && a[u].se < v) {
			node_add_mx(u, v - a[u].mx);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (L < mid) {
			chmin(u << 1, l, mid, L, R, v);
		}
		if (mid < R) {
			chmin(u << 1 | 1, mid, r, L, R, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	int get_cnt(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u].cnt;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (R <= mid) {
			return get_cnt(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return get_cnt(u << 1 | 1, mid, r, L, R);
		} else {
			return get_cnt(u << 1, l, mid, L, R) + get_cnt(u << 1 | 1, mid, r, L, R);
		}
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1), tag(enlarge(n) << 1), mxtag(enlarge(n) << 1) {}

	void modify(int x, int v) {
		modify(1, 0, n, x, v);
	}

	void add(int l, int r, int v) {
		if (l >= r) {
			return;
		}
		add(1, 0, n, l, r, v);
	}

	void chmin(int l, int r, int v) {
		if (l >= r) {
			return;
		}
		chmin(1, 0, n, l, r, v);
	}

	int get_cnt(int l, int r) {
		if (l >= r) {
			return 0;
		}
		return get_cnt(1, 0, n, l, r);
	}

	long long get_sum() {
		return a[1].sum;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		--v;
		p[v] = i;
	}
	
	std::vector<long long> ans(n);
	for (int _ = 0; _ < 2; ++_) {
		segment_tree T(n);
		for (int i = 0; i < n; ++i) {
			T.modify(p[i], i + 1);
			T.chmin(0, p[i], T.get_cnt(0, p[i]));
			T.add(p[i] + 1, n, 1);
			ans[i] += T.get_sum() - 1ll * i * (i + 1) / 2;
		}
		for (int i = 0; i < n; ++i) {
			p[i] = n - 1 - p[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << ans[i] - i - 1 << "\n";
	}
}