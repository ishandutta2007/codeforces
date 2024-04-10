#include <bits/stdc++.h>

struct segment {
	int l, r, c;

	bool operator<(const segment &rhs) const {
		return r < rhs.r;
	}
};

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	int n;
	std::vector<int> a, tag;

	void up(int u) {
		a[u] = std::max(a[u << 1], a[u << 1 | 1]);
	}
	
	void apply(int u, int v) {
		a[u] += v;
		tag[u] += v;
	}

	void down(int u) {
		apply(u << 1, tag[u]);
		apply(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}

	void insert(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u] = std::max(a[u], v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (x < mid) {
			insert(u << 1, l, mid, x, v);
		} else {
			insert(u << 1 | 1, mid, r, x, v);
		}
		up(u);
	}

	void range_add(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			apply(u, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (L < mid) {
			range_add(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			range_add(u << 1 | 1, mid, r, L, R, v);
		}
		up(u);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::max(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1), tag(enlarge(n) << 1) {}

	void insert(int x, int v) {
		insert(1, 0, n, x, v);
	}

	void range_add(int l, int r, int v) {
		if (l < r) {
			range_add(1, 0, n, l, r, v);
		}
	}

	int query(int l, int r) {
		return l < r ? query(1, 0, n, l, r) : 0;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<segment> a(n);
	std::vector<int> v;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].l >> a[i].r >> a[i].c;
		--a[i].l, --a[i].c;
		v.push_back(a[i].l), v.push_back(a[i].r);
	}
	std::sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i) {
		a[i].l = std::lower_bound(v.begin(), v.end(), a[i].l) - v.begin();
		a[i].r = std::lower_bound(v.begin(), v.end(), a[i].r) - v.begin();
	}
	std::sort(a.begin(), a.end());

	std::vector<segment_tree> Tl(2, v.size()), Tr(2, v.size());
	int ans = 0;
	for (auto [l, r, c] : a) {
		Tl[c].range_add(0, l, 1);
		Tr[c ^ 1].range_add(0, l + 1, 1);
		int s = std::max(Tl[c].query(0, l), Tr[c ^ 1].query(0, l + 1));
		ans = std::max(ans, s);
		Tl[c].insert(l, s);
		Tr[c].insert(r, s);
	}
	std::cout << ans << "\n";
}