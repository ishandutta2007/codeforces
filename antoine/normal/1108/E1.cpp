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

struct StVal {
	int mn = 0, mx = 0;
	StVal() {
	}
	StVal(const int x) :
			mn(x), mx(x) {
	}
	StVal(const StVal &v1, const StVal &v2) {
		mn = min(v1.mn, v2.mn);
		mx = max(v1.mx, v2.mx);
	}

	int diff() const {
		return mx - mn;
	}
};

struct StUpdate { // define
	int x = 0;
	StUpdate() {
	}
	StUpdate(const int x) :
			x(x) {
	}

	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1.x + u2.x;
	}
	void apply(StVal &v, const int lo, const int hi) { // omit last 2 arguments if non-lazy segment tree
		v.mn += x;
		v.mx += x;
	}
};

typedef SegTree<StVal, StUpdate> MyST;

struct Event {
	int id, type;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	MyST st(n);
	vector<int> l(m), r(m);
	vector<vector<Event>> events(n + 1);

	for (int i = 0; i < m; ++i) {
		cin >> l[i] >> r[i];
		--l[i], --r[i];
		events[l[i]].push_back( { i, 1 });
		events[r[i] + 1].push_back( { i, -1 });
		st.update(l[i], r[i], -1);
	}

	pair<int, int> res = { -1, 0 };
	for (int i = 0; i < n; ++i) {
		for (const Event &e : events[i])
			st.update(l[e.id], r[e.id], e.type);
		res = max(res, { st.query(0, n - 1).diff(), i });
	}
	cout << res.first << endl;

	set<int> s;
	for (int i = 0; i < m; ++i)
		s.insert(i);

	for (int i = 0; i <= res.second; ++i) {
		for (const Event &e : events[i]) {
			if (e.type == 1) {
				assert(s.count(e.id));
				s.erase(e.id);
			} else {
				assert(!s.count(e.id));
				s.insert(e.id);
			}
		}
	}
	cout << s.size() << endl;
	for(int x : s)
		cout << x + 1 << ' ';
	return 0;
}