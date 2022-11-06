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
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
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

struct StVal {
	bool val = 0;

	StVal() {
	}

	StVal(const StVal &v1, const StVal &v2) {
	}
};

struct StUpdate { // define
	bool flip = false;
	bool change = false;
	bool changeVal = 0;

	StUpdate() {
	}
	StUpdate(bool flip) :
			flip(flip) {
		assert(flip);
	}

	StUpdate(bool change, bool changeVal) :
			change(change), changeVal(changeVal) {
		assert(change);
	}

	bool empty() const {
		return !flip && !change;
	}

	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		if (u1.empty())
			*this = u2;
		else if (u2.empty())
			*this = u1;
		else if (u2.change)
			*this = u2;
		else {
			assert(u2.flip);
			if (u1.change) {
				change = true;
				changeVal = !u1.changeVal;
			} else
				assert(u1.flip);
		}
	}

	void apply(StVal &v, const int lo, const int hi) {
		if (lo == hi) {
			if (flip)
				v.val ^= 1;
			else if (change)
				v.val = changeVal;
		}
	}
};

typedef SegTree<StVal, StUpdate> MyST;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, Q;
	cin >> n >> Q;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	vector<int> indexes(n);
	iota(indexes.begin(), indexes.end(), 0);
	sort(indexes.begin(), indexes.end(), [&a](const int i, const int j) {
		return abs(a[i]) < abs(a[j]);
	});

	vector<int> b(n);
	MyST st(n);

	for (int i = 0; i < n; ++i) {
		if (a[indexes[i]] < 0)
			st.update(i, i, StUpdate(true));
		b[i] = abs(a[indexes[i]]);
	}

	assert(is_sorted(b.begin(), b.end()));

	while (Q--) {
		char symb;
		int x;
		cin >> symb >> x;

		if (symb == '<') {
			if (x > 0) {
				const int i = lower_bound(b.begin(), b.end(), x) - b.begin();
				st.update(0, i - 1, StUpdate(true));
				x = -x + 1;
			}
			assert(x <= 0);
			const int i = lower_bound(b.begin(), b.end(), -x + 1) - b.begin();
			st.update(i, n - 1, StUpdate(true, 0));
		} else {
			assert(symb == '>');
			if (x < 0) {
				const int i = upper_bound(b.begin(), b.end(), -x - 1) - b.begin();
				st.update(0, i - 1, StUpdate(true));
				x = -x - 1;
			}
			assert(x >= 0);
			const int i = upper_bound(b.begin(), b.end(), x) - b.begin();
			st.update(i, n - 1, StUpdate(true, 1));
		}
	}

	vector<StVal> vals = st.retreive();
	for (int i = 0; i < n; ++i)
		a[indexes[i]] = b[i] * (vals[i].val ? -1 : 1);
	for (int x : a)
		cout << x << ' ';
	return 0;
}