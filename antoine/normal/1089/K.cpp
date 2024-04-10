#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<class V> struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n) : n(n) {
		leaves.resize(n);
		init(1, 0, n - 1);
	}

	void init(const int si, const int lo, const int hi) { // init st[] and leaves[]
		if (lo == hi) {
			if(si >= (int)st.size()) st.resize(si + 1);
			st[si] = V(lo, 0); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) { return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V(); }
	V query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}


	void update(const int i, V v) {
		int si = leaves[i];
		st[si] = v;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

};

struct StVal { // define
	ll t = 0, d = 0;
	StVal() {
	}

	StVal(const ll _t, const ll _d) :
			t(_t), d(_d) {
	}

	StVal(const StVal &v1, const StVal &v2) {
		d = v1.d + v2.d;
		t = max(v1.t, v2.t - v1.d);
	}
};

typedef SegTree<StVal> MyST;
struct Query {
	char type;
	int t, d;
};

Query queries[(int) 3e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;

	MyST st((int) 1e6 + 9);

	for (int i = 1; i <= q; ++i) {
		char &type = queries[i].type;
		cin >> type;
		if (type == '+') {
			int &t = queries[i].t;
			int &d = queries[i].d;
			cin >> t >> d;
			st.update(t, StVal(t, d));
		} else if (type == '-') {
			int j;
			cin >> j;
			const int t = queries[j].t;
			st.update(t, StVal(t, 0));
		} else {
			assert(type == '?');
			int t;
			cin >> t;
			StVal val = st.query(0, t);
			ll T = val.t + val.d;
			cout << max(0LL, T - t) << '\n';
		}
	}
	return 0;
}