#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

template<class V, class U> struct SegTree {
	int n;
	vector<V> st;
	vector<U> lazy;

	SegTree(const int n) :
			n(n) {
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			cin >> st[si].v; //  = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
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
			const int mid = (lo + hi) >> 1;
			lazy[si << 1] = U(lazy[si << 1], lazy[si].left());
			lazy[si << 1 | 1] = U(lazy[si << 1 | 1], lazy[si].right(mid - lo + 1));
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

	void update(const int l, const int r, U u) {
		assert(l <= r);
		update(l, r, u, 1, 0, n - 1);
	}

	void update(const int l, const int r, U &u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
			u = u.right(hi - lo + 1);
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
};

const int mod = (int) 1e9 + 9;
const int MxN = 300000 + 9;
pair<ll, ll> dp[MxN + 9];
pair<ll, ll> cs[MxN + 9];

struct StVal {
	ll v = 0;
	StVal() {
	}
	StVal(const ll v) :
			v(v) {
	}
	StVal(const StVal &v1, const StVal &v2) {
		v = (v1 + v2) % mod;
	}
	operator ll() const {
		return v;
	}
};

struct StUpdate { // define
	ll x = 0, y = 0;
	StUpdate() {
	}
	StUpdate(const ll x, const ll y) :
			x(x), y(y) {
	}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = (u1.x + u2.x) % mod;
		y = (u1.y + u2.y) % mod;
	}

	StUpdate left() const {
		return *this;
	}

	StUpdate right(const int leftSz) const {
		ll res[2];
		for (int i = 0; i < 2; ++i)
			res[i] = (x * dp[leftSz + i].first + y * dp[leftSz + i].second) % mod;
		return StUpdate(res[0], res[1]);
	}

	void apply(StVal &v, const int lo, const int hi) const {
		// cerr << "apply " << x << ' ' << y << ' ' << lo << ' ' << hi << ' ' << (x * cs[hi - lo].first + y * cs[hi - lo].second) << endl;
		v.v += (x * cs[hi - lo].first + y * cs[hi - lo].second) % mod;
		v.v %= mod;
	}
};

typedef SegTree<StVal, StUpdate> MyST;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	dp[0].first = dp[1].second = 1;
	for (int i = 2; i <= MxN; ++i) {
		dp[i].first = (dp[i - 1].first + dp[i - 2].first) % mod;
		dp[i].second = (dp[i - 1].second + dp[i - 2].second) % mod;
	}

	for (int i = 0; i <= MxN; ++i) {
		cs[i].first = (dp[i].first + (i ? cs[i - 1].first : 0)) % mod;
		cs[i].second = (dp[i].second + (i ? cs[i - 1].second : 0)) % mod;
	}

	int n, q;
	cin >> n >> q;
	MyST st(n);
	while (q--) {
		int type, l, r;
		cin >> type >> l >> r;
		--l, --r;
		assert(0 <= l && l <= r && r < n);
		if (type == 1) {
			st.update(l, r, StUpdate(1, 1));
		} else {
			assert(type == 2);
			cout << st.query(l, r) << '\n';
		}
	}
	return 0;
}