#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

template<class V, class U> struct SegTree {
	int n;
	vector<V> st;
	vector<U> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
		lazy.resize(st.size());
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= st.size()) st.resize(si + 1);
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		}
		else {
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

	V query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V(); }
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


	void update(const int l, const int r, const U u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const U &u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = U(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]);
		}
	}

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si >> 1, lo, mid);
			updateAllLazy(si >> 1 | 1, mid + 1, hi);
		}
	}

	vector<int> retreive() {
		updateAllLazy();
		vector<int> res(n);
		for (int i = 0; i < n; ++i) {
			res[i] = st[leaves[i]];
		}
		return res;
	}
};

struct StVal { // define
	ll v = 0; // optional
	StVal() {}
	StVal(const ll v) : v(v) {} // optional
	StVal(const StVal &v1, const StVal &v2) { v = v1 + v2; }
	operator ll() const { return v; } // optional
};

struct StUpdate { // define
	ll v = 0; // optional
	StUpdate() {}
	StUpdate(const ll v) : v(v) {} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) { v = max(u1, u2); }
	operator ll() const { return v; } // optional
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.v = max(v.v, this->v);
	}
};

typedef SegTree<StVal, StUpdate> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	if (find(a.begin(), a.end(), q) == a.end()) {
		auto it = find(a.begin(), a.end(), 0);
		if (it == a.end()) {
			cout << "NO\n";
			return 0;
		}
		*it = q;
	}
	const int qIdx = find(a.begin(), a.end(), q) - a.begin();
	assert(qIdx >= 0 && qIdx < n);

	vector<int> firstOcc(q + 1, n + 999), lastOcc(q + 1, -1);
	for (int i = 0; i < a.size(); ++i) {
		if (a[i]) {
			firstOcc[a[i]] = min(firstOcc[a[i]], i);
			lastOcc[a[i]] = max(lastOcc[a[i]], i);
		}
	}

	MyST st(n);
	for (int i = 1; i <= q; ++i) {
		if (lastOcc[i] >= 0) {
			st.update(firstOcc[i], lastOcc[i], i);
		}
	}

	for (int i = 0; i < n; ++i) {
		int x = st.query(i, i);
		if (x == 0)
			assert(a[i] == 0);
		else if (a[i] != 0 && a[i] != x) {
			cout << "NO\n";
			return 0;
		}
		a[i] = x;
	}

	for (int i = 1; i < n; ++i)
		if (a[i] == 0)
			a[i] = a[i - 1];
	for (int i = n - 2; i >= 0; --i)
		if (a[i] == 0)
			a[i] = a[i + 1];
	cout << "YES\n";
	for (auto &&x : a)
		cout << x << ' ';
	return 0;
}