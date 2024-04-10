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

const ll Inf = 1e11;

struct StVal {
	int i = -1;
	ll mn = Inf;

	StVal() {
	}
	StVal(const int i, const ll x) :
			i(i), mn(x) {
	}
	StVal(const StVal &val1, const StVal &val2) {
		if (val1.mn <= val2.mn) {
			*this = val1;
			if (val1.mn == val2.mn)
				i = max(i, val2.i);
		} else
			*this = val2;
	}
};

struct StUpdate { // define
	ll x = 0; // optional
	StUpdate() {
	}
	StUpdate(const ll _x) :
			x(_x) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1 + u2;
	}
	operator ll() const {
		return x;
	} // optional
	void apply(StVal &val, const int lo, const int hi) { // lo == hi if non-lazy segment tree
		val.mn += x;
	}
};
typedef SegTree<StVal, StUpdate> MyST;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	MyST st(n);
	set<int> s;
	vector<int> ans(n, -1);
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		st.update(i, StVal(i, x));
		s.insert(i);
	}

	for (int mn = 1; mn <= n; ++mn) {
		StVal val = st.query(0, n - 1);
		assert(val.mn == 0);
		const int i = val.i;

		st.update(i, i, 2 * Inf);
		st.update(i, n - 1, -mn);
		ans[i] = mn;
	}

	for (int x : ans)
		cout << x << ' ';

	return 0;
}