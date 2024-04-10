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
	std::vector<long long> sum;
	std::vector<int> tag;

	void up(int u) {
		sum[u] = sum[u << 1] + sum[u << 1 | 1];
	}

	void add(int u, int l, int r, int v) {
		sum[u] += 1ll * (r - l) * v;
		tag[u] += v;
	}

	void down(int u, int l, int mid, int r) {
		if (tag[u]) {
			add(u << 1, l, mid, tag[u]);
			add(u << 1 | 1, mid, r, tag[u]);
			tag[u] = 0;
		}
	}

	void add(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			add(u, l, r, v);
			return;
		}
		int mid = (l + r + 1) >> 1;
		down(u, l, mid, r);
		if (L < mid) {
			add(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			add(u << 1 | 1, mid, r, L, R, v);
		}
		up(u);
	}

	int find(int u, int l, int r, long long v) {
		if (l + 1 == r) {
			return l;
		}
		int mid = (l + r + 1) >> 1;
		down(u, l, mid, r);
		if (sum[u << 1] > v) {
			return find(u << 1, l, mid, v);
		} else {
			return find(u << 1 | 1, mid, r, v - sum[u << 1]);
		}
	}

	int query(int u, int l, int r, int x) {
		if (l + 1 == r) {
			return sum[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u, l, mid, r);
		if (x < mid) {
			return query(u << 1, l, mid, x);
		} else {
			return query(u << 1 | 1, mid, r, x);
		}
	}

public:
	SegmentTree(int _n) : n(_n), sum(enlarge(n) << 1), tag(enlarge(n) << 1) {}

	void add(int l, int r, int v) {
		add(1, 0, n, l, r, v);
	}

	int find(long long v) {
		return find(1, 0, n, v);
	}

	int query(int x) {
		return query(1, 0, n, x);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end(), std::greater<int>());

	SegmentTree T(n + a[0] + 1);
	T.add(0, 1, 1);
	long long now = 1;
	int p = 0;
	int ans = n + a[0] + 1;
	for (int i = 0; i < n; ++i) {
		while (!T.query(p)) {
			++p;
		}
		now += a[i] - 2;
		T.add(p, p + 1, -1);
		T.add(p + 2, p + 2 + (a[i] - 1) / 2, 1);
		T.add(p + 2, p + 2 + a[i] / 2, 1);
		if (now >= k) {
			ans = std::min(ans, T.find(k - 1));
		}
	}
	if (now < k) {
		std::cout << -1 << "\n";
	} else {
		std::cout << ans << "\n";
	}
}