#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

struct V {
	int sum = 0;
	int mn = 0;
	// int mnI = 0;

	V() {
	}

	V(const int i, const int x) {
		sum = x;
		mn = x;
		// mnI = i;
	}

	V(const V &v1, const V &v2) {
		sum = v1.sum + v2.sum;
		if (v2.sum + v1.mn < v2.mn) {
			mn = v2.sum + v1.mn;
			// mnI = v1.mnI;
		} else {
			mn = v2.mn;
			// mnI = v2.mnI;
		}
	}
};

struct SegTree {
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
			st[si] = V(lo, 0); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) {
		assert(l <= r && l < n && r >= 0);
		return query(l, r, 1, 0, n - 1);
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

	void update(const int i, const int x) { // change !!
		int si = leaves[i];
		st[si] = V(i, st[si].sum + x);

		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

const int MxX = (int) 1e6 + 9;
const int MxN = (int) 3e5 + 9;
SegTree st(MxX + 9);
int a[MxN + 9];
int b[MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		st.update(a[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
		st.update(b[i], +1);
	}

	int Q;
	cin >> Q;
	while (Q--) {
		{
			int type, i, x;
			cin >> type >> i >> x;
			if (type == 1) {
				st.update(a[i], +1);
				a[i] = x;
				st.update(a[i], -1);
			} else {
				assert(type == 2);
				st.update(b[i], -1);
				b[i] = x;
				st.update(b[i], +1);
			}
		}

		int lo = -1, hi = MxX;
		while (lo < hi) {
			const int mid = (lo + hi + 1) >> 1;
			if (st.query(mid, st.n - 1).mn < 0)
				lo = mid;
			else
				hi = mid - 1;
		}
		cout << lo << '\n';
	}

	return 0;
}