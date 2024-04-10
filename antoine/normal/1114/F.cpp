#include<bits/stdc++.h>
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
			int x;
			cin >> x;
			st[si] = V(x); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
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
};

const int mod = (int) 1e9 + 7;
ll modPow(ll n, ll k) {
	ll res = 1;
	for (n %= mod; k; k >>= 1) {
		if (k & 1)
			res = res * n % mod;
		n = n * n % mod;
	}
	return res;
}

ll modInv(const ll x) {
	return modPow(x, mod - 2);
}

vector<int> primes; // 62 primes
vector<int> primesInv;
const int MxP = 64;

bitset<MxP> getBS(int x) {
	bitset<MxP> bs = 0;
	for (int i = 0; i < MxP; ++i)
		if (x % primes[i] == 0)
			bs[i] = 1;
	return bs;

}

struct StVal {
	ll product = 1;
	bitset<MxP> bs = 0;
	StVal() {
	}
	StVal(const ll x) {
		product = x;
		bs = getBS(x);
	}
	StVal(const StVal &v1, const StVal &v2) {
		product = v1.product * v2.product % mod;
		bs = v1.bs | v2.bs;
	}
};

struct StUpdate {
	ll x = 1;
	bitset<MxP> bs = 0;
	StUpdate() {
	}
	StUpdate(const int x) {
		this->x = x;
		bs = getBS(x);
	}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1.x * u2.x % mod;
		bs = u1.bs | u2.bs;
	}
	void apply(StVal &v, const int lo, const int hi) {
		v.product *= modPow(x, hi - lo + 1);
		v.product %= mod;
		v.bs |= bs;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= 300; ++i) {
		bool ok = true;
		for (int j = 2; j < i; ++j)
			if (i % j == 0)
				ok = false;
		if (ok) {
			primes.push_back(i);
			primesInv.push_back(modInv(i));
		}
	}

	int n, q;
	cin >> n >> q;

	SegTree<StVal, StUpdate> st(n);
	while (q--) {
		string type;
		int l, r;
		cin >> type >> l >> r;
		--l, --r;
		if (type[0] == 'T') {
			StVal res = st.query(l, r);
			ll ans = res.product;
			for (int i = 0; i < MxP; ++i)
				if (res.bs[i]) {
					ans *= 1 - primesInv[i];
					ans %= mod;
				}
			cout << ((ans % mod + mod) % mod) << '\n';
		} else {
			int x;
			cin >> x;
			st.update(l, r, x);
		}
	}
	return 0;
}