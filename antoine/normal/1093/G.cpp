#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
	int c[5];
	Point() {}
	Point(const int k) {
		memset(c, 0, sizeof c);
		for (int i = 0; i < k; ++i)
			cin >> c[i];
	}
};

struct V {
	Point pts[1 << 5];
	V() {}
	V(const Point p) {
		for (Point &x : pts)
			x = p;
	}

	V(const V &v1, const V &v2) {
		for (int m = (1 << 5) - 1; m >= 0; --m) {
			pts[m] = max(v1.pts[m], v2.pts[m], [&m](const Point &p1, const Point &p2) {
				int diff = 0;
				for(int i = 0; i < 5; ++i)
					diff += ((m & (1 << i)) ? 1 : -1) * (p1.c[i] - p2.c[i]);
				return diff > 0;
			});
		}
	}

	int query() {
		int res = 0;
		for (int i = (1 << 5) - 1; i >= 0; --i)
			for (int j = (1 << 5) - 1; j >= 0; --j) {
				int curr = 0;
				for (int k = 0; k < 5; ++k)
					curr += abs(pts[i].c[k] - pts[j].c[k]);
				res = max(res, curr);
			}
		return res;
	}
};

struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n, const int k) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1, k);
	}

	void init(const int si, const int lo, const int hi, const int k) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si] = V(Point(k));
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, k);
			init(si << 1 | 1, mid + 1, hi, k);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r)
			return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, V v) {
		int si = leaves[i];
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, k;
	cin >> n >> k;

	SegTree st(n, k);

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i;
			cin >> i;
			--i;
			st.update(i, V(Point(k)));
		} else {
			assert(type == 2);
			int l, r;
			cin >> l >> r;
			--l, --r;
			cout << st.query(l, r).query() << '\n';
		}
	}
	return 0;
}