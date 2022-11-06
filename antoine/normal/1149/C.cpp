#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

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

	void update(const int i, const char c) {
		int si = leaves[i];
		st[si] = V(c);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal {
	int deepestL = 0, leastL = 0, vL = 0, sumL = 0;
	int deepestR = 0, leastR = 0, vR = 0, sumR = 0;
	int total = 0;

	StVal() {
	}

	StVal(const char c) {
		total = 1;

		deepestL = 1;
		leastL = 0;
		vL = 1;
		sumL = 1;

		deepestR = 0;
		leastR = -1;
		vR = 1; //////
		sumR = -1;

		if (c == '(') {
		} else {
			assert(c == ')');
			swap(deepestL, deepestR);
			swap(leastL, leastR);
			swap(vL, vR);
			swap(sumL, sumR);
		}
	}
	StVal(const StVal &v1, const StVal &v2) {
		deepestL = max(v1.deepestL, v1.sumL + v2.deepestL);
		leastL = min(v1.leastL, v1.sumL + v2.leastL);
		vL = max(v1.vL, -v1.sumL + v2.vL);
		vL = max(vL, -2 * v1.leastL + (v1.sumL + v2.deepestL));
		sumL = v1.sumL + v2.sumL;

		deepestR = max(v2.deepestR, v2.sumR + v1.deepestR);
		leastR = min(v2.leastR, v2.sumR + v1.leastR);
		vR = max(v2.vR, -v2.sumR + v1.vR);
		vR = max(vR, -2 * v2.leastR + (v2.sumR + v1.deepestR));
		sumR = v2.sumR + v1.sumR;

		total = max(v1.total, v2.total);
		total = max(total, (v1.deepestL - v1.sumL) + v2.vL);
		total = max(total, (v2.deepestR - v2.sumR) + v1.vR);
	}
};
typedef SegTree<StVal> MyST;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q;
	string s;
	cin >> n >> q >> s;

	n = 2 * (n - 1);
	assert(n == (int )s.size());

	MyST st(n);
	for (int i = 0; i < n; ++i)
		st.update(i, s[i]);

	for (;;) {
		cout << st.query(0, st.n - 1).total << '\n';
		if (q-- == 0)
			break;
		int l, r;
		cin >> l >> r;
		--l, --r;
		if (l != r) {
			assert(0 <= l && l < n);
			assert(0 <= r && r < n);
			swap(s[l], s[r]);
			st.update(l, s[l]);
			st.update(r, s[r]);
		}
	}

	return 0;
}