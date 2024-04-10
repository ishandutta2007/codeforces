#include <bits/stdc++.h>

const int N = 200005;

int n, q, a[N];

struct SegmentTree {
	static const int N = ::N << 2;

	long long sum[N];
	int mx[N], mn[N];
	int cov[N];
	
	void up(int u) {
		sum[u] = sum[u << 1] + sum[u << 1 | 1];
		mx[u] = std::max(mx[u << 1], mx[u << 1 | 1]);
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}
	
	void build(int u, int l, int r) {
		if (l == r) {
			sum[u] = a[l];
			mn[u] = a[l];
			mx[u] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		up(u);
	}
	
	void cover(int u, int l, int r, int v) {
		sum[u] = 1ll * (r - l + 1) * v;
		mn[u] = v;
		mx[u] = v;
		cov[u] = v;
	}
	
	void down(int u, int l, int mid, int r) {
		if (cov[u]) {
			cover(u << 1, l, mid, cov[u]);
			cover(u << 1 | 1, mid + 1, r, cov[u]);
			cov[u] = 0;
		}
	}
	
	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R && mx[u] <= v) {
			cover(u, l, r, v);
			return;
		}
		if (L <= l && r <= R && mn[u] >= v) {
			return;
		}
		int mid = (l + r) >> 1;
		down(u, l, mid, r);
		if (L <= mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid + 1, r, L, R, v);
		}
		up(u);
	}
	
	std::pair<int, int> query(int u, int l, int r, int L, int R, int now) {
		if (L <= l && r <= R && sum[u] <= now) {
			return {r - l + 1, sum[u]};
		}
		if (L <= l && r <= R && mn[u] > now) {
			return {0, 0};
		}
		int mid = (l + r) >> 1;
		down(u, l, mid, r);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R, now);
		} else if (L > mid) {
			return query(u << 1 | 1, mid + 1, r, L, R, now);
		} else {
			std::pair<int, int> tl = query(u << 1, l, mid, L, R, now);
			std::pair<int, int> tr = query(u << 1 | 1, mid + 1, r, L, R, now - tl.second);
			return {tl.first + tr.first, tl.second + tr.second};
		}
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}
	T.build(1, 1, n);
	while (q--) {
		int op, x, y;
		std::cin >> op >> x >> y;
		if (op == 1) {
			T.modify(1, 1, n, 1, x, y);
		} else {
			std::cout << T.query(1, 1, n, x, n, y).first << "\n";
		}
	}
}