#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

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

	void update(const int i, V val) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si] = val;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

const int Inf = (int) 2e9 + 3;

struct StVal { // define
	int mn1[10], mn2[10];
	StVal() {
		for (int i = 0; i < 10; ++i)
			mn1[i] = mn2[i] = Inf;
	}
	StVal(const int x) {
		int y = x;
		for (int i = 0; i < 10; ++i, y /= 10) {
			mn1[i] = mn2[i] = Inf;
			if (y % 10)
				mn1[i] = x;
		}
		assert(!y);
	}

	StVal(const StVal &val1, const StVal &val2) {
		for (int i = 0; i < 10; ++i) {
			if (val1.mn1[i] == val2.mn1[i])
				mn1[i] = mn2[i] = val1.mn1[i];
			else if (val1.mn1[i] < val2.mn1[i]) {
				mn1[i] = val1.mn1[i];
				mn2[i] = min(val1.mn2[i], val2.mn1[i]);
			} else {
				mn1[i] = val2.mn1[i];
				mn2[i] = min(val2.mn2[i], val1.mn1[i]);
			}
		}
	}
	int query() const {
		int res = Inf;
		for (int i = 0; i < 10; ++i)
			if (mn2[i] < Inf)
				res = min(res, mn1[i] + mn2[i]);
		if (res >= Inf)
			res = -1;
		return res;
	}
};

struct StUpdate { // define
	StUpdate() {
	}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
	}
	void apply(StVal &val, const int lo, const int hi) {
	}
};
typedef SegTree<StVal, StUpdate> MyST;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	MyST st(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		st.update(i, StVal(x));
	}

	while (m--) {
		int type;
		cin >> type;
		if (type == 1) {
			int i, x;
			cin >> i >> x;
			st.update(i - 1, StVal(x));
		} else {
			assert(type == 2);
			int l, r;
			cin >> l >> r;
			cout << st.query(l - 1, r - 1).query() << '\n';
		}
	}
	return 0;
}