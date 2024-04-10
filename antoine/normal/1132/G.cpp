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
			st[si] = V(); // cin >> ??
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if internal nodes are V()
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

struct StVal { // define
	int x = 0;
	StVal() {
	}
	StVal(const int _x) :
			x(_x) {
	} // optional
	StVal(const StVal &val1, const StVal &val2) {
		x = max(val1, val2);
	}
	operator int() const {
		return x;
	} // optional
};

struct StUpdate { // define
	int x = 0; // optional
	StUpdate() {
	}
	StUpdate(const int _x) :
			x(_x) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1 + u2;
	}
	operator int() const {
		return x;
	} // optional
	void apply(StVal &val, const int lo, const int hi) { // lo == hi if non-lazy segment tree
		val.x += x;
	}
};
typedef SegTree<StVal, StUpdate> MyST;

const int MxN = (int) 1e6 + 9;
vector<int> adj[MxN + 9];
int start[MxN + 9];
int fin[MxN + 9];

void dfs(const int u, const int parent, int &t) {
	start[u] = t++;
	for (const int v : adj[u])
		if (v != parent)
			dfs(v, u, t);
	fin[u] = t - 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	{
		stack<int> st;
		for (int i = n - 1; i >= 0; --i) {
			while (!st.empty() && a[st.top()] <= a[i])
				st.pop();
			if (!st.empty())
				adj[st.top()].push_back(i);
			st.push(i);
		}
	}

	{
		memset(fin, -1, sizeof fin);
		int t = 0;
		for (int i = n - 1; i >= 0; --i)
			if (fin[i] == -1)
				dfs(i, -1, t);
		assert(t == n);
	}

	MyST st(n);
	for (int i = 0; i < n; ++i) {
		if (i - k >= 0)
			st.update(start[i - k], start[i - k], -(int) 1e7);
		st.update(start[i], fin[i], 1);
		if (i >= k - 1)
			cout << st.query(0, st.n - 1) << ' ';
	}
	return 0;
}