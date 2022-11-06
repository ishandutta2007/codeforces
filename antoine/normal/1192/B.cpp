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

	V query() const {
		return st[1];
	}

	void update(const int i, U u) { // single index update, [!!!] NON-LAZY SEGMENT TREE ONLY !!!
		int si = leaves[i];
		u.apply(st[si], i, i);
		for (si >>= 1; si; si >>= 1)
			st[si] = V(st[si << 1], st[si << 1 | 1]);
	}
};

struct StVal { // define
	ll sum = 0;
	ll mi = 0, mj = 0, mk = 0;
	ll mij = 0, mjk = 0, mijk = 0;
	StVal() {
	}
	StVal(const ll sum) :
			sum(sum) {
		mi = mk = max(0LL, sum);
		mj = max(0LL, -2 * sum);
		mij = max(0LL, -2 * sum);
		mjk = max(-sum, sum);
		mijk = max(-sum, sum);
	}

	StVal(const StVal &val1, StVal val2) {
		sum = val1.sum + val2.sum;

		val2.mi += val1.sum;
		val2.mj -= 2 * val1.sum;
		val2.mk += val1.sum;
		val2.mij -= val1.sum;
		val2.mjk -= val1.sum;

		mi = max(val1.mi, val2.mi);
		mj = max(val1.mj, val2.mj);
		mk = max(val1.mk, val2.mk);
		mij = max(val1.mi + val2.mj, max(val1.mij, val2.mij));
		mjk = max(val1.mj + val2.mk, max(val1.mjk, val2.mjk));
		mijk = max(max(val1.mijk, val2.mijk), max(val1.mij + val2.mk, val1.mi + val2.mjk));
	}
};

struct StUpdate { // define
	ll x = 0; // optional
	StUpdate() {
	}
	StUpdate(const ll _x) :
			x(_x) {
	} // optional
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		x = u1 + u2;
	}
	operator ll() const {
		return x;
	} // optional
	void apply(StVal &val, const int lo, const int hi) { // lo == hi if non-lazy segment tree
		if (x) {
			assert(lo == hi);
			val = StVal(x);
		}
	}
};

typedef SegTree<StVal, StUpdate> MyST;

const int MxN = (int) 1e5 + 9;
vector<int> adj[MxN + 9];
int parent[MxN + 9];
int start[MxN + 9];
int fin[MxN + 9];

void dfs(const int u, int &t) {
	start[u] = fin[u] = t++;
	for (const int v : adj[u]) {
		if (v == parent[u])
			continue;
		parent[v] = u;
		dfs(v, t);
		fin[u] = t++;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, Q;
	ll W;
	cin >> n >> Q >> W;
	vector<pair<pair<int, int>, ll>> edges(n - 1);
	for (pair<pair<int, int>, ll> &edge : edges) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edge = { {u, v}, w};
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	{
		int t = 0;
		dfs(1, t);
		assert(t == 2 * n - 1);
	}

	MyST st(2 * n - 2);

	auto update = [&](const pair<pair<int, int>, ll> &edge) {
		int u = edge.first.first;
		int v = edge.first.second;
		if (parent[v] != u)
		swap(u, v);
		assert(parent[v] == u);
		const ll w = edge.second;
		st.update(start[v] - 1, w);
		st.update(fin[v], -w);
	};

	for (const auto &e : edges)
		update(e);

	ll last = 0;
	while (Q--) {
		ll i, w;
		cin >> i >> w;
		(i += last) %= (n - 1);
		(w += last) %= W;
		edges[i].second = w;
		update(edges[i]);
		last = st.query().mijk;
		cout << last << '\n';
	}
	return 0;
}