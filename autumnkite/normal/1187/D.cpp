#include <bits/stdc++.h>

int enlarge(int n) {
	int res = 1;
	while (res < n) {
		res <<= 1;
	}
	return res;
}

class segment_tree {
	int n;
	std::vector<int> mn;

	void modify(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			mn[u] = v;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u << 1, l, mid, x, v);
		} else {
			modify(u << 1 | 1, mid, r, x, v);
		}
		mn[u] = std::min(mn[u << 1], mn[u << 1 | 1]);
	}

	int query(int u, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return mn[u];
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
	segment_tree(int _n) : n(_n), mn(enlarge(n) << 1) {}

	void modify(int x, int v) {
		modify(1, 0, n, x, v);
	}

	int query(int l, int r) {
		return query(1, 0, n, l, r);
	}
};

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<std::queue<int>> pos(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		--a[i];
		pos[a[i]].push(i);
	}
	std::vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> b[i];
		--b[i];
	}

	std::vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		if (pos[b[i]].empty()) {
			std::cout << "NO\n";
			return;
		}
		p[i] = pos[b[i]].front();
		pos[b[i]].pop();
	}

	segment_tree T(n);
	for (int i = 0; i < n; ++i) {
		T.modify(i, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (T.query(0, p[i] + 1) != b[i]) {
			std::cout << "NO\n";
			return;
		}
		T.modify(p[i], n);
	}
	std::cout << "YES\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}