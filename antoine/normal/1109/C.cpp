#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct IdGen {
	map<int, int> mp;
	vector<int> lazy;

	void insert(int x) {
		assert(mp.empty());
		lazy.push_back(x);
	}
	void process() {
		assert(mp.empty());
		sort(lazy.begin(), lazy.end());
		lazy.erase(unique(lazy.begin(), lazy.end()), lazy.end());
		for (int i = 0; i < (int) lazy.size(); ++i)
			mp[lazy[i]] = i;
		lazy.clear();
	}
	int getId(int x) const {
		assert(lazy.empty());
		return mp.at(x);
	}
	int size() const {
		assert(lazy.empty());
		return mp.size();
	}
} idGen;

template<class V> struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
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

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r)
			return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int i, V v) {
		// cerr << "update " << i << ' ' << v.empty << ' ' << v.t1 << ' ' << v.s2 << endl;
		int si = leaves[i];
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

};

struct StVal { // define
	bool empty = true;
	ll t1 = 0, t2 = 0, s2 = 0;
	ll mn = 0, diff = 0;

	StVal() {
	}
	StVal(const ll t, const ll s) :
			empty(false), t1(t), t2(t), s2(s) {
	}

	StVal(const bool empty) :
			empty(empty) {
		assert(empty == true);
	}

	StVal(const StVal &v1, const StVal &v2) {
		if (v1.empty || v2.empty) {
			*this = v1.empty ? v2 : v1;
			return;
		}
		const ll midDiff = v1.s2 * (v2.t1 - v1.t2);
		diff = v1.diff + midDiff + v2.diff;
		mn = min(v1.mn, v1.diff + midDiff + v2.mn);
		t1 = v1.t1;
		t2 = v2.t2;
		s2 = v2.s2;
		empty = false;
	}
};

typedef SegTree<StVal> MyST;

struct Query {
	ll type, t, s, l, r, v;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(10);

	vector<Query> queries;

	{
		int Q;
		cin >> Q;
		queries.resize(Q);
	}

	for (Query &query : queries) {
		cin >> query.type;
		if (query.type == 1)
			cin >> query.t >> query.s;
		else if (query.type == 2)
			cin >> query.t;
		else if (query.type == 3)
			cin >> query.l >> query.r >> query.v;
		else
			assert(0);
	}

	for (const Query &query : queries)
		if (query.type == 1) {
			idGen.insert(query.t);
		}

	const int LastStEntry = (int) 1e9 + 9;

	idGen.insert(0);
	idGen.insert(LastStEntry);
	idGen.process();

	MyST st(idGen.size());
	st.update(idGen.getId(0), StVal(0, 0));
	st.update(idGen.getId(LastStEntry), StVal(LastStEntry, 0));

	for (const Query &query : queries) {
		if (query.type == 1) {
			st.update(idGen.getId(query.t), StVal(query.t, query.s));
		} else if (query.type == 2)
			st.update(idGen.getId(query.t), StVal(true));
		else {
			assert(query.type == 3);
			ll l = query.l;
			const ll r = query.r;
			const ll v = query.v;
			if (v == 0) {
				cout << l << '\n';
				continue;
			}
			const int lIdx = idGen.mp.lower_bound(l)->second;
			int lo = lIdx;
			int hi = st.n;
			while (lo < hi) {
				const int mid = (lo + hi) / 2;
				if (st.query(lIdx, mid).mn + v <= 0) {
					hi = mid;
				} else
					lo = mid + 1;
			}
			if (lo == st.n) {
				cout << -1 << '\n';
				// cerr << "case 1 " << endl;
				continue;
			}
			const StVal stVal = st.query(lIdx, lo - 1);
			if (stVal.empty) {
				cout << -1 << '\n';
				// cerr << "case 2 " << endl;
				continue;
			}
			const ll f_t2 = v + stVal.diff;
			assert(f_t2 > 0);
			if (stVal.s2 >= 0) {
				cout << -1 << '\n';
				// cerr << "case 3 " << endl;
				continue;
			}
			const long double x = -(long double) (f_t2) / stVal.s2;
			const long double ans = stVal.t2 + x;
			if (ans > r) {
				cout << -1 << '\n';
				// cerr << "case 4 " << ' ' << ans << endl;
				continue;
			}
			cout << ans << '\n';

		}
	}
	return 0;
}