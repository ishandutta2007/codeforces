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

	void update(const int i, V val) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		st[si] = val;
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}

};

struct StVal { // define
	int v = (int) 1e8; // optional
	StVal() {
	}
	StVal(const ll v) :
			v(v) {
	}
	StVal(const StVal &v1, const StVal &v2) {
		v = min(v1, v2);
	}
	operator int() const {
		return v;
	}
};

bool f() {

	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int &x : a)
		cin >> x;
	for (int &x : b)
		cin >> x;

	SegTree<StVal> st(n);

	map<int, vector<int>> pos;
	for (int i = 0; i < n; ++i) {
		pos[a[i]].push_back(i);
		st.update(i, a[i]);
	}

	for (auto&& e : pos)
		reverse(e.second.begin(), e.second.end());

	for (const int x : b) {
		vector<int> &positions = pos[x];
		if (positions.empty())
			return false;
		const int j = positions.back();
		positions.pop_back();
		const int resp = st.query(0, j - 1);
		assert(resp != x);
		if (resp < x)
			return false;
		st.update(j, StVal());
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int Q;
	cin >> Q;
	while (Q--)
		cout << (f() ? "YES\n" : "NO\n");
	return 0;
}