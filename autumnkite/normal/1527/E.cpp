#include <bits/stdc++.h>

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<long long> mn, tag;

	void up(int u) {
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}

	void add(int u, long long v) {
		mn[u] += v;
		tag[u] += v;
	}

	void down(int u) {
		add(u << 1, tag[u]);
		add(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}

	void build(int u, int l, int r, const std::vector<long long> &a) {
		if (l + 1 == r) {
			mn[u] = a[l];
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid, a);
		build(u << 1 | 1, mid, r, a);
		up(u);
	}

	void modify(int u, int l, int r, int L, int R, long long v) {
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

	long long query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return mn[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::min(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	SegmentTree(std::vector<long long> a) : n(a.size()), mn(enlarge(n) << 1), tag(enlarge(n) << 1) {
		build(1, 0, n, a);
	}

	void add(int l, int r, long long v) {
		modify(1, 0, n, l, r, v);
	}

	long long query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> lst(n, -1);
	std::vector<int> pre(n);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		--v;
		pre[i] = lst[v];
		lst[v] = i;
	}

	std::vector<long long> f(n + 1, INF);
	f[0] = 0;
	for (int j = 1; j <= k; ++j) {
		SegmentTree T(f);
		for (int i = 0; i < n; ++i) {
			if (pre[i] != -1) {
				T.add(0, pre[i] + 1, i - pre[i]);
			}
			f[i + 1] = T.query(0, i + 2);
		}
	}
	std::cout << f[n] << "\n";
}