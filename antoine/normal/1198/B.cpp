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

	void update(const int l, const int r, const U u, bool point) {
		if (l <= r)
			update(l, r, u, 1, 0, n - 1, point);
	}
	void update(const int l, const int r, const U &u, const int si, const int lo, const int hi, bool point) {
		if (l <= lo && hi <= r) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
			if (point)
				st[si].x = u.x;
		} else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo)
				return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid, point);
			update(l, r, u, si << 1 | 1, mid + 1, hi, point);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}

};

struct StVal { // define
	ll x = 0; // optional
	StVal() {
	}
	StVal(const ll _x) :
			x(_x) {
	} // optional
	StVal(const StVal &val1, const StVal &val2) {
		x = min(val1, val2);
	}
	operator ll() const {
		return x;
	} // optional
};

struct StUpdate { // define
	ll x = 0; // optional
	StUpdate() {
	}
	StUpdate(const ll _x) :
			x(_x) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = max(u1, u2);
	}
	operator ll() const {
		return x;
	} // optional
	void apply(StVal &val, const int lo, const int hi) { // lo == hi if non-lazy segment tree
		val.x = max(val.x, x);
	}
};
typedef SegTree<StVal, StUpdate> MyST;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	MyST st(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		st.update(i, i, x, true);
	}

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int p, x;
			cin >> p >> x;
			--p;
			st.update(p, p, x, true);
		} else {
			assert(type == 2);
			int x;
			cin >> x;
			st.update(0, st.n - 1, x, false);
		}
	}

	for (int i = 0; i < n; ++i)
		cout << st.query(i, i) << ' ';
	return 0;
}