#include <bits/stdc++.h>

const int K = 2;

struct Point {
	int a[2];

	Point() {
		a[0] = a[1] = 0;
	}
	
	Point(int x, int y) {
		a[0] = x, a[1] = y;
	}

	int &operator[](int x) {
		return a[x];
	}

	const int &operator[](int x) const {
		return a[x];
	}
};

class KD_Tree {
	static const int N = 400000;

	const int INF = 0x3f3f3f3f;
	const double alpha = 0.75;

	struct Node {
		Point v, mx, mn;
		int sz;
		long long sum;

		Node() : sz(0), sum(0) {}

		Node(const Point &a) : v(a), mx(a), mn(a), sz(1), sum(a[0] - a[1]) {}
	};

	int rt;

	int cnt;
	Node T[N];
	int ls[N], rs[N];

	int top, rub[N];

	int new_node(const Point &a) {
		int u = top ? rub[--top] : cnt++;
		T[u] = Node(a);
		ls[u] = rs[u] = -1;
		return u;
	}

	void up(int u) {
		T[u].mx = T[u].mn = T[u].v;
		T[u].sz = 1;
		T[u].sum = T[u].v[0] - T[u].v[1];
		if (ls[u] != -1) {
			T[u].sz += T[ls[u]].sz;
			T[u].sum += T[ls[u]].sum;
			for (int i = 0; i < K; ++i) {
				T[u].mx[i] = std::max(T[u].mx[i], T[ls[u]].mx[i]);
				T[u].mn[i] = std::min(T[u].mn[i], T[ls[u]].mn[i]);
			}
		}
		if (rs[u] != -1) {
			T[u].sz += T[rs[u]].sz;
			T[u].sum += T[rs[u]].sum;
			for (int i = 0; i < K; ++i) {
				T[u].mx[i] = std::max(T[u].mx[i], T[rs[u]].mx[i]);
				T[u].mn[i] = std::min(T[u].mn[i], T[rs[u]].mn[i]);
			}
		}
	}

	int build(Point *a, int l, int r, int d) {
		if (l >= r) {
			return -1;
		}
		int mid = (l + r) >> 1;
		std::nth_element(a + l, a + mid, a + r, [&](const Point &a, const Point &b) {
			return a[d] < b[d];
		});
		int u = new_node(a[mid]);
		int _ls = build(a, l, mid, (d + 1) % K);
		int _rs = build(a, mid + 1, r, (d + 1) % K);
		ls[u] = _ls, rs[u] = _rs;
		up(u);
		return u;
	}

	int __insert(int u, const Point &a, int d, int &lst, int &ld) {
		if (u == -1) {
			return new_node(a);
		}
		if (a[d] <= T[u].v[d]) {
			int _ls = __insert(ls[u], a, (d + 1) % K, lst, ld);
			ls[u] = _ls;
			up(u);
			if (T[ls[u]].sz > T[u].sz * alpha) {
				lst = u;
				ld = d;
			}
		} else {
			int _rs = __insert(rs[u], a, (d + 1) % K, lst, ld);
			rs[u] = _rs;
			up(u);
			if (T[rs[u]].sz > T[u].sz * alpha) {
				lst = u;
				ld = d;
			}
		}
		return u;
	}

	void get_points(int u, Point *res, int &n) {
		if (u == -1) {
			return;
		}
		res[n++] = T[u].v;
		get_points(ls[u], res, n);
		get_points(rs[u], res, n);
		rub[top++] = u;
	}

	bool inclusive(int u, const Point &mn, const Point &mx) {
		for (int i = 0; i < K; ++i) {
			if (T[u].mn[i] < mn[i] || T[u].mx[i] > mx[i]) {
				return false;
			}
		}
		return true;
	}

	bool intersect(int u, const Point &mn, const Point &mx) {
		for (int i = 0; i < K; ++i) {
			if (T[u].mx[i] < mn[i] || T[u].mn[i] > mx[i]) {
				return false;
			}
		}
		return true;
	}

	bool contain(int u, const Point &mn, const Point &mx) {
		for (int i = 0; i < K; ++i) {
			if (T[u].v[i] < mn[i] || T[u].v[i] > mx[i]) {
				return false;
			}
		}
		return true;
	}

	long long __query(int u, const Point &mn, const Point &mx) {
		if (u == -1 || !intersect(u, mn, mx)) {
			return 0;
		}
		if (inclusive(u, mn, mx)) {
			return T[u].sum;
		}
		long long ans = __query(ls[u], mn, mx) + __query(rs[u], mn, mx);
		if (contain(u, mn, mx)) {
			ans += T[u].v[0] - T[u].v[1];
		}
		return ans;
	}

public:
	KD_Tree() : rt(-1), cnt(0), top(0) {}

	void insert(const Point &a) {
		int lst = -1, ld = -1;
		rt = __insert(rt, a, 0, lst, ld);
		if (lst != -1) {
			static Point tmp[N];
			int n = 0;
			get_points(lst, tmp, n);
			assert(lst == build(tmp, 0, n, ld));
		}
	}

	long long query(const Point &mn, const Point &mx) {
		return __query(rt, mn, mx);
	}
} T, Te;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, q;
	std::cin >> n >> q;
	std::vector<std::set<int>> pos(n);
	for (int i = 0; i < n; ++i) {
		pos[i].insert(-1);
	}
	std::vector<int> pre(n);
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		int v;
		std::cin >> v;
		--v;
		a[i] = v;
		pre[i] = *(--pos[v].end());
		pos[v].insert(i);
	}

	auto insert = [&](KD_Tree &T, int i) {
		T.insert(Point(i, pre[i]));
	};

	auto update = [&](int i) {
		insert(Te, i);
		pre[i] = *(--pos[a[i]].lower_bound(i));
		insert(T, i);
	};

	for (int i = 0; i < n; ++i) {
		insert(T, i);
	}
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int x, v;
			std::cin >> x >> v;
			--x, --v;
			pos[a[x]].erase(x);
			auto it = pos[a[x]].upper_bound(x);
			if (it != pos[a[x]].end()) {
				update(*it);
			}
			a[x] = v;
			pos[a[x]].insert(x);
			update(x);
			it = pos[a[x]].upper_bound(x);
			if (it != pos[a[x]].end()) {
				update(*it);
			}
		} else {
			int l, r;
			std::cin >> l >> r;
			--l, --r;
			std::cout << T.query(Point(l, l), Point(r, r)) - Te.query(Point(l, l), Point(r, r)) << "\n";
		}
	}
}
/*
3 2
1 2 3
1 3 2
2 1 3
*/