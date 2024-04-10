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
	std::vector<int> a;

	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u] = v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		a[u] = std::min(a[u << 1], a[u << 1 | 1]);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return a[u];
		}
		int mid = (l + r + 1) >> 1;
		if (R <= mid) {
			return query(u << 1, l, mid, L, R);
		} else if (L >= mid) {
			return query(u << 1 | 1, mid, r, L, R);
		} else {
			return std::min(query(u << 1, l, mid, L, R), query(u << 1 | 1, mid, r, L, R));
		}
	}

public:
	SegmentTree(int _n) : n(_n), a(enlarge(n) << 1, -1) {}

	void modify(int x, int v) {
		modify(1, 0, n, x, v);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
	}
	
	SegmentTree T(n);
	std::vector<int> lst(n + 1, -1);
	std::vector<bool> vis(n + 1);
	for (int i = 0; i < n; ++i) {
		int pos = !a[i] ? i - 1 : T.query(0, a[i]);
		if (lst[a[i]] < pos) {
			vis[a[i]] = true;
		}
		lst[a[i]] = i;
		T.modify(a[i], i);
	}
	for (int i = 0; i <= n; ++i) {
		int pos = !i ? n - 1 : T.query(0, i);
		if (lst[i] < pos) {
			vis[i] = true;
		}
	}
	int ans = 0;
	while (ans <= n && vis[ans]) {
		++ans;
	}
	std::cout << ans + 1 << "\n";
}