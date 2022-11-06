#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<class V, class U> struct SegTree {
	int n;
	vector<V> st;
	vector<U> lazy;
	vector<int> leaves;

	SegTree(const int n) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si] = V(); // cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if internal nodes are V()
		}
	}

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = U(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = U();
	}

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r)
			return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const U u) {
		if (l <= r)
			update(l, r, u, 1, 0, n - 1);
	}
	void update(const int l, const int r, const U &u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		} else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo)
				return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}

	// ------------------------------------------| ________ |---------------------------------------------------------
	// ------------------------------------------| NON-LAZY |---------------------------------------------------------

	void update(const int i, U u) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		u.apply(st[si], i, i);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

	// ------------------------------------------| ________ |---------------------------------------------------------
	// ------------------------------------------| OPTIONAL |---------------------------------------------------------

	// remove and return all non-zero values in a range, assuming all values >= 0
	vector<int> remAll(const int l, const int r) {
		vector<int> res;
		remAll(l, r, 1, 0, n - 1, res);
		return res;
	}
	void remAll(const int l, const int r, const int si, const int lo, const int hi, vector<int> &res) {
		updateLazy(si, lo, hi);
		if (!st[si] || hi < l || r < lo)
			return;
		if (lo == hi) {
			res.push_back(lo);
			st[si] = 0;
		} else {
			const int mid = (lo + hi) >> 1;
			remAll(l, r, si << 1, lo, mid, res);
			remAll(l, r, si << 1 | 1, mid + 1, hi, res);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}

	void updateAllLazy() {
		updateAllLazy(1, 0, n - 1);
	}
	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<V> retreive() {
		updateAllLazy();
		vector<V> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]];
		return res;
	}
};

struct StVal { // define
	int x = 0; // optional
	StVal() {
	}
	StVal(const int _x) :
			x(_x) {
	} // optional
	StVal(const StVal &val1, const StVal &val2) {
		x = max(val1, val2);
	}
	operator int() const {
		return x;
	} // optional
};

struct StUpdate { // define
	int x = 0; // optional
	StUpdate() {
	}
	StUpdate(const int _x) :
			x(_x) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1 + u2;
	}
	operator int() const {
		return x;
	} // optional
	void apply(StVal &val, const int lo, const int hi) { // lo == hi if non-lazy segment tree
		val.x += x;
	}
};
typedef SegTree<StVal, StUpdate> MyST;
struct Point {
	int x, y;
};

const int Mx = (int) 4e6 + 999;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, R;
	cin >> n >> R;
	map<int, vector<int>> mp;

	for (int i = 0; i < n; ++i) {
		Point p;
		cin >> p.x >> p.y;
		p = {p.x - p.y, p.x + p.y};
		p.x += Mx / 2 - 9;
		p.y += Mx / 2 - 9;
		assert(p.x >= 0 && p.y >= 0);
		assert(p.x < Mx && p.y < Mx);
		mp[p.y].push_back(p.x);
	}

	MyST st(Mx + 9);
	queue<Point> q;

	int ans = 0;
	for (const auto &e : mp) {
		const int y = e.first;
		for (const int x : e.second) {
			st.update(x - R, x + R, 1);
			q.push( { x, y });
		}
		while (!q.empty() && q.front().y < y - 2 * R) {
			const int x = q.front().x;
			st.update(x - R, x + R, -1);
			q.pop();
		}
		ans = max(ans, st.query(0, st.n - 1).x);
	}
	cout << ans;
	return 0;
}