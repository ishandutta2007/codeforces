#include <bits/stdc++.h>

const int N = 200005;
const long long INF = 0x3f3f3f3f3f3f3f3fll;

int n, q, a[N];
long long s[N];

struct SegmentTree {
	static const int N = ::N << 2;

	long long mx[N], tag[N];
	
	void up(int u) {
		mx[u] = std::max(mx[u << 1], mx[u << 1 | 1]);
	}
	
	void build(int u, int l, int r) {
		if (l == r) {
			mx[u] = s[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		up(u);
	}
	
	void add(int u, long long v) {
		mx[u] += v;
		tag[u] += v;
	}
	
	void down(int u) {
		add(u << 1, tag[u]);
		add(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}
	
	void modify(int u, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {
			add(u, v);
			return;
		}
		int mid = (l + r) >> 1;
		down(u);
		if (L <= mid) {
			modify(u << 1, l, mid, L, R, v);
		}
		if (R > mid) {
			modify(u << 1 | 1, mid + 1, r, L, R, v);
		}
		up(u);
	}
	
	std::pair<int, long long> find(int u, int l, int r, long long v) {
		if (l == r) {
			if (mx[u] >= v) {
				return {l, mx[u]};
			} else {
				return {l + 1, INF};
			}
		}
		int mid = (l + r) >> 1;
		down(u);
		if (mx[u << 1] >= v) {
			return find(u << 1, l, mid, v);
		} else {
			return find(u << 1 | 1, mid + 1, r, v);
		}
	}

	int query(int u, int l, int r, int x) {
		if (l == r) {
			return mx[u];
		}
		int mid = (l + r) >> 1;
		down(u);
		if (x <= mid) {
			return query(u << 1, l, mid, x);
		} else {
			return query(u << 1 | 1, mid + 1, r, x);
		}
	}
} T;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	T.build(1, 1, n);
	while (q--) {
		int x, v;
		std::cin >> x >> v;
		v -= a[x];
		a[x] += v;
		T.modify(1, 1, n, x, n, v);
		long long now = 0;
		while (1) {
			std::pair<int, long long> tmp = T.find(1, 1, n, 2 * now);
//			std::cerr << tmp.first << " " << tmp.second << "\n";
			if (tmp.first > n) {
				std::cout << -1 << "\n";
				break;
			}
			if ((tmp.first == 1 && tmp.second == 0)
			  || tmp.second == 2 * T.query(1, 1, n, tmp.first - 1)) {
				std::cout << tmp.first << "\n";
				break;
			}
			now = tmp.second;
		}
	}
}