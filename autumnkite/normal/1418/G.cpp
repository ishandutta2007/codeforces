#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<int> mn;
	std::vector<int> c;
	std::vector<int> tag;

	void up(int u) {
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
		c[u] = (mn[u] == mn[u << 1] ? c[u << 1] : 0) +
		       (mn[u] == mn[u << 1 | 1] ? c[u << 1 | 1] : 0);
	}

	void add(int u, int v) {
		mn[u] += v;
		tag[u] += v;
	}

	void down(int u) {
		add(u << 1, tag[u]);
		add(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}

	void build(int u, int l, int r) {
		if (l + 1 == r) {
			mn[u] = 0;
			c[u] = 1;
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid, r);
		up(u);
	}

	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			add(u, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (L < mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid, r, L, R, v);
		}
		up(u);
	}

public:
	SegmentTree(int _n) : n(_n), mn(enlarge(n) << 1), c(enlarge(n) << 1), tag(enlarge(n) << 1) {
		build(1, 0, n);
	}

	void range_add(int l, int r, int v) {
		if (l < r) {
			modify(1, 0, n, l, r, v);
		}
	}

	int blank_number() {
		return mn[1] == 0 ? c[1] : 0;
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::vector<int>> pos(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		pos[a[i]].push_back(i);
	}
	std::vector<std::vector<std::tuple<int, int, int>>> op(n + 1);
	auto add = [&](int sx, int sy, int tx, int ty) {
		op[sx].emplace_back(sy, ty, 1);
		op[tx].emplace_back(sy, ty, -1);
	};
	for (int i = 0; i < n; ++i) {
		add(i, 0, n, i);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j + 3 < (int)pos[i].size(); ++j) {
			add(0, pos[i][j + 3], pos[i][j] + 1, n);
		}
		for (int j = 0; j < (int)pos[i].size(); ++j) {
			add(j ? pos[i][j - 1] + 1 : 0, pos[i][j], pos[i][j] + 1, j + 2 < (int)pos[i].size() ? pos[i][j + 2] : n);
		}
	}
	SegmentTree T(n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		for (auto [l, r, v] : op[i]) {
			T.range_add(l, r, v);
		}
		ans += T.blank_number();
	}
	std::cout << ans << "\n";
}