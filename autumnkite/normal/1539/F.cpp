#include <bits/stdc++.h>

struct node {
	int mx, mn;

	node() : mx(0), mn(0) {}
	node(int _mx, int _mn) : mx(_mx), mn(_mn) {}

	node operator+(const node &rhs) const {
		return node(std::max(mx, rhs.mx), std::min(mn, rhs.mn));
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
	std::vector<node> a;
	std::vector<int> tag;

	void build(int u, int l, int r) {
		tag[u] = 0;
		if (l + 1 == r) {
			a[u] = node(l, l);
			return;
		}
		int mid = (l + r + 1) >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid, r);
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	void add(int u, int v) {
		a[u].mx += v, a[u].mn += v, tag[u] += v;
	}

	void down(int u) {
		if (tag[u]) {
			add(u << 1, tag[u]);
			add(u << 1 | 1, tag[u]);
			tag[u] = 0;
		}
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
		if (mid < R) {
			modify(u << 1 | 1, mid, r, L, R, v);
		}
		a[u] = a[u << 1] + a[u << 1 | 1];
	}

	node query(int u, int l, int r, int L, int R) {
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
			return query(u << 1, l, mid, L, R) + query(u << 1 | 1, mid, r, L, R);
		}
	}

public:
	segment_tree(int _n) : n(_n), a(enlarge(n) << 1), tag(enlarge(n) << 1) {
		build(1, 0, n);
	}

	void modify(int l, int r, int v) {
		modify(1, 0, n, l, r, v);
	}

	node query(int l, int r) {
		return query(1, 0, n, l, r);
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
	std::vector<int> ans(n);

	segment_tree T(n + 1);
	auto get_ans = [&](int x) {
		node tl = T.query(0, x + 1);
		node tr = T.query(x + 1, n + 1);
		return std::max((tr.mx - tl.mn) / 2, (tl.mx - tr.mn + 1) / 2);
	};
	for (int v = 0; v < n; ++v) {
		for (int i : pos[v]) {
			ans[i] = std::max(ans[i], get_ans(i));
		}
		for (int i : pos[v]) {
			T.modify(i + 1, n + 1, -2);
		}
		for (int i : pos[v]) {
			T.modify(i + 1, n + 1, 2);
			ans[i] = std::max(ans[i], get_ans(i));
			T.modify(i + 1, n + 1, -2);
		}
	}
	for (int x : ans) {
		std::cout << x << " ";
	}
	std::cout << "\n";
}