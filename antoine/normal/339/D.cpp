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
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
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

	void update(const int i, const int x) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si].v = x;

		int rep = 0;
		for (si >>= 1; si; si >>= 1) {
			if (rep & 1)
				st[si].v = st[si << 1].v ^ st[si << 1 | 1].v;
			else

				st[si].v = st[si << 1].v | st[si << 1 | 1].v;
			rep++;
		}
	}
};

struct StVal { // define
	ll v = 0; // optional
	StVal() {
	}
	StVal(const ll v) :
			v(v) {
	} // optional
	operator ll() const {
		return v;
	} // optional
};

struct StUpdate { // define
	ll v = 0; // optional
	StUpdate() {
	}
	StUpdate(const ll v) :
			v(v) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		v = u1 + u2;
	}
	operator ll() const {
		return v;
	} // optional
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.v += this->v * (hi - lo + 1);
	}
};
typedef SegTree<StVal, StUpdate> MyST;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;

	MyST st(1 << n);

	for (int i = 0; i < (1 << n); ++i) {
		int x;
		cin >> x;
		st.update(i, x);
	}

	while (q--) {
		int i, x;
		cin >> i >> x;
		--i;
		st.update(i, x);
		cout << st.st[1].v << endl;
	}

	return 0;
}