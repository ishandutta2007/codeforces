#include <bits/stdc++.h>

const int P = 1000000007;

class segment_tree {
	struct node {
		node *ls, *rs;
		int v;

		node() : ls(NULL), rs(NULL), v(1) {}

		void up() {
			v = 1ll * (ls == NULL ? 1 : ls->v) * (rs == NULL ? 1 : rs->v) % P;
		}
	};

	int n;
	node *rt;

	void modify(node *&u, int l, int r, int x, int w) {
		node *v = u;
		u = new node();
		if (v != NULL) {
			*u = *v;
		}
		if (l + 1 == r) {
			u->v = 1ll * u->v * w % P;
			return;
		}
		int mid = (l + r + 1) >> 1;
		if (x < mid) {
			modify(u->ls, l, mid, x, w);
		} else {
			modify(u->rs, mid, r, x, w);
		}
		u->up();
	}

	int query(node *u, int l, int r, int L, int R) {
		if (u == NULL) {
			return 1;
		}
		if (L <= l && r <= R) {
			return u->v;
		}
		int mid = (l + r + 1) >> 1;
		if (R <= mid) {
			return query(u->ls, l, mid, L, R);
		} else if (L >= mid) {
			return query(u->rs, mid, r, L, R);
		} else {
			return 1ll * query(u->ls, l, mid, L, R) * query(u->rs, mid, r, L, R) % P;
		}
	}

public:
	segment_tree(int _n) : n(_n), rt(NULL) {}

	void modify(int x, int w) {
		modify(rt, 0, n, x, w);
	}

	int query(int l, int r) {
		return query(rt, 0, n, l, r);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	int m = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}
	std::vector<int> minp(m + 1), inv(m + 1);
	for (int i = 1; i <= m; ++i) {
		minp[i] = i;
	}
	for (int i = 2; i <= m; ++i) {
		if (minp[i] == i) {
			for (int j = i + i; j <= m; j += i) {
				minp[j] = std::min(minp[j], i);
			}
		}
	}
	inv[1] = 1;
	for (int i = 2; i <= m; ++i) {
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	}
	std::vector<segment_tree> T(n, n);
	std::vector<int> lst(m + 1, -1);
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			T[i] = T[i - 1];
		}
		int x = a[i];
		std::vector<std::pair<int, int>> op;
		while (minp[x] > 1) {
			int p = minp[x];
			int now = 1;
			while (x % p == 0) {
				now *= p;
				x /= p;
				if (lst[now] != -1) {
					op.emplace_back(lst[now], inv[p]);
				}
				lst[now] = i;
			}
			op.emplace_back(i, now);
		}
		std::sort(op.begin(), op.end());
		int now = 1;
		for (int j = 0; j < (int)op.size(); ++j) {
			now = 1ll * now * op[j].second % P;
			if (j + 1 == (int)op.size() || op[j].first != op[j + 1].first) {
				T[i].modify(op[j].first, now);
				now = 1;
			}
		}
	}

	int ans = 0;
	int q;
	std::cin >> q;
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		l = (l + ans) % n, r = (r + ans) % n;
		if (l > r) {
			std::swap(l, r);
		}
		std::cout << (ans = T[r].query(l, r + 1)) << "\n";
	}
}