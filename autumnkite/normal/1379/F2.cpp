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
	std::vector<int> a, b;
	std::vector<bool> s;

	void modify_a(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			a[u] = v;
			s[u] = b[u] >= a[u];
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify_a(u << 1, l, mid, x, v);
		} else {
			modify_a(u << 1 | 1, mid, r, x, v);
		}
		a[u] = std::max(a[u << 1], a[u << 1 | 1]);
		s[u] = s[u << 1] && s[u << 1 | 1] && b[u << 1] >= a[u << 1 | 1];
	}

	void modify_b(int u, int l, int r, int x, int v) {
		if (l + 1 == r) {
			b[u] = v;
			s[u] = b[u] >= a[u];
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify_b(u << 1, l, mid, x, v);
		} else {
			modify_b(u << 1 | 1, mid, r, x, v);
		}
		b[u] = std::min(b[u << 1], b[u << 1 | 1]);
		s[u] = s[u << 1] && s[u << 1 | 1] && b[u << 1] >= a[u << 1 | 1];
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1), b(enlarge(n) << 1), s(enlarge(n) << 1, true) {}

	void modify_a(int x, int v) {
		modify_a(1, 0, n, x, v);
	}

	void modify_b(int x, int v) {
		modify_b(1, 0, n, x, v);
	}

	bool get_ans() {
		return s[1];
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<std::set<int>> Sl(n), Sr(n);
	segment_tree T(n);
	for (int i = 0; i < n; ++i) {
		Sl[i].insert(0);
		Sr[i].insert(m);
		T.modify_b(i, m);
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		bool op = x & 1;
		x /= 2, y /= 2;
		y += op;
		if (op) {
			if (Sl[x].count(y)) {
				Sl[x].erase(y);
			} else {
				Sl[x].insert(y);
			}
			T.modify_a(x, *Sl[x].rbegin());
		} else {
			if (Sr[x].count(y)) {
				Sr[x].erase(y);
			} else {
				Sr[x].insert(y);
			}
			T.modify_b(x, *Sr[x].begin());
		}
		std::cout << (T.get_ans() ? "YES\n" : "NO\n");
	}
}