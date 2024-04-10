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

	// ------------------------------------------| ________ |---------------------------------------------------------
	// ------------------------------------------| NON-LAZY |---------------------------------------------------------

	void update(const int i, U u) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		u.apply(st[si]);
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
	ll v = 0; // optional
	StVal() {
	}
	StVal(const ll v) :
			v(v) {
	} // optional
	StVal(const StVal &v1, const StVal &v2) {
		v = v1 + v2;
	}
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

const int mod = (int) 1e9 + 7;
const int Mx = (int) 5e5 + 9;
int a[Mx + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<int> perm(n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		perm[i - 1] = i;
	}

	sort(perm.begin(), perm.end(), [](const int i, const int j) {
		return a[i] < a[j];
	});

	MyST preSums(n + 1), suffSums(n + 1);

	ll ans = 0;
	for (const int i : perm) {
		ll temp = i * (n - i + 1LL);
		temp += 1LL * i * (preSums.query(i, n) - (n - i + 1LL) * preSums.query(i, i));
		temp += (n - i + 1LL) * (suffSums.query(1, i) - i * suffSums.query(i, i));
		temp = temp % mod * a[i];
		ans = (ans + temp) % mod;

		preSums.update(i, n, 1);
		suffSums.update(1, i, 1);
	}
	cout << (ans % mod + mod) % mod;
	return 0;
}