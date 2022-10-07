#include <bits/stdc++.h>

int enlarge_to_pow2(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class SegmentTree {
	int n;
	std::vector<long long> mxa, tag, mxb, mn;

	void add(int u, long long v) {
		mxa[u] += v;
		tag[u] += v;
	}

	void down(int u) {
		add(u << 1, tag[u]);
		add(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}

	long long calc(int u, int l, int r, long long mx) {
		if (l + 1 == r) {
			return std::max(mxa[u], mx) - mxb[u];
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		if (mxa[u] > mx) {
			return std::min(calc(u << 1, l, mid, mx), mn[u]);
		} else {
			return std::min(mx - mxb[u << 1], calc(u << 1 | 1, mid, r, mx));
		}
	}

	void up(int u, int mid, int r) {
		mxa[u] = std::max(mxa[u << 1], mxa[u << 1 | 1]);
		mn[u] = calc(u << 1 | 1, mid, r, mxa[u << 1]);
	}

	void build(int u, int l, int r, const std::vector<long long> &a, const std::vector<long long> &b) {
		tag[u] = 0;
		if (l + 1 == r) {
			mxa[u] = a[l];
			mxb[u] = b[l];
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid, a, b);
		build(u << 1 | 1, mid, r, a, b);
		mxb[u] = std::max(mxb[u << 1], mxb[u << 1 | 1]);
		up(u, mid, r);
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
		up(u, mid, r);
	}

	int query(int u, int l, int r, int L, int R, long long mx, long long lim) {
		if (R <= l || L >= r || calc(u, l, r, mx) > lim) {
			return -1;
		}
		if (l + 1 == r) {
			return l;
		}
		int mid = (l + r + 1) >> 1;
		down(u);
		int p = query(u << 1 | 1, mid, r, L, R, std::max(mx, mxa[u << 1]), lim);
		if (p == -1) {
			return query(u << 1, l, mid, L, R, mx, lim);
		} else {
			return p;
		}
	}

public:
	SegmentTree(int _n) : n(enlarge_to_pow2(_n)), mxa(n * 2), tag(n * 2), mxb(n * 2), mn(n * 2) {
		n = _n;
	}

	void build(std::vector<long long> a, std::vector<long long> b) {
		build(1, 0, n, a, b);
	}

	void modify(int l, int r, long long v) {
		modify(1, 0, n, l, r, v);
	}

	int query(int l, int r, long long mx, long long lim) {
		return query(1, 0, n, l, r, mx, lim);
	}
};

const long long INF = 0x3f3f3f3f3f3f3f3fll;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<long long> w(n);
	for (int i = 0; i < n - 1; ++i) {
		int v;
		std::cin >> v;
		w[i + 1] = w[i] + v;
	}
	std::vector<long long> g(n + 1);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		g[i + 1] = g[i] + v;
	}

	std::vector<long long> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = w[i] - g[i];
		b[i] = g[i + 1] - w[i];
	}

	SegmentTree T(n);
	T.build(std::vector<long long>(n, -INF), b);

	int ans = 0;
	std::vector<int> sta;
	sta.push_back(n);
	for (int l = n - 1; l >= 0; --l) {
		while ((int)sta.size() > 1 && a[l] >= a[sta.back()]) {
			T.modify(sta.back(), sta[sta.size() - 2], a[l] - a[sta.back()]);
			sta.pop_back();
		}
		sta.push_back(l);
		int p = std::lower_bound(sta.begin(), sta.end(), a[l] + m, [&](int x, long long val) {
			return x == n || a[x] > val;
		}) - sta.begin() - 1;
		int r = T.query(l, sta[p], -INF, m + a[l]);
		ans = std::max(ans, r - l + 1);
		if (l > 0) {
			T.modify(l, l + 1, INF + a[l] + b[l - 1]);
		}
	}
	std::cout << ans << "\n";
}