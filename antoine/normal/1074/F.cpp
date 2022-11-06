#undef NDEBUG
#include <bits/stdc++.h>

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
			st[si] = V(); // optional if V(V(), V()) = V() ---- | ---- cin >> ??
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

struct StVal {
	int mn = 0, occ = 1;

	StVal() {
	}

	StVal(const StVal &v1, const StVal &v2) {
		if (v1.mn <= v2.mn) {
			*this = v1;
			if (mn == v2.mn)
				occ += v2.occ;
		} else
			*this = v2;
	}
};

struct StUpdate { // define
	int inc = 0;
	StUpdate() {
	}
	StUpdate(const int v) :
			inc(v) {
	}
	StUpdate(const StUpdate &u1, const StUpdate &u2) {
		inc = u1 + u2;
	}
	operator int() const {
		return inc;
	}
	void apply(StVal &v, const int lo, const int hi) {
		v.mn += inc;
	}
};

typedef SegTree<StVal, StUpdate> MyST;

const int MaxN = (int) 2e5 + 9;
vector<int> adj[MaxN + 9];
pair<int, int> range[MaxN + 9];
vector<int> parent[MaxN + 9];
int depth[MaxN + 9];

void dfs(const int u, const int p, int &t) {
	range[u].first = t++;
	for (auto &&v : adj[u])
		if (v != p) {
			depth[v] = depth[u] + 1;
			parent[v] = {u};
			for (int i = 0; i < (int) parent[parent[v][i]].size(); ++i)
				parent[v].push_back(parent[parent[v][i]][i]);
			dfs(v, u, t);
		}
	range[u].second = t - 1;
}

int lca(int u, int v) {
	int diff = depth[u] - depth[v];
	if (diff < 0) {
		swap(u, v);
		diff = -diff;
	}
	for (int i = 0; diff; ++i)
		if (diff & (1 << i)) {
			diff ^= 1 << i;
			u = parent[u][i];
		}

	if (u == v)
		return u;

	for (int i = (int) parent[u].size() - 1; i >= 0; --i)
		if (parent[u][i] != parent[v][i]) {
			u = parent[u][i];
			v = parent[v][i];
			i = min(i, (int) parent[u].size());
		}

	return parent[u][0];
}

int lcaCh(int u, int v) {
	int diff = depth[u] - depth[v];
	if (diff < 0) {
		swap(u, v);
		diff = -diff;
	}
	assert(--diff >= 0);

	for (int i = 0; diff; ++i)
		if (diff & (1 << i)) {
			diff ^= 1 << i;
			u = parent[u][i];
		}
	assert(parent[u][0] == v);
	assert(depth[u] == depth[v] + 1);
	return u;
}

bool covers(const int u, const int v) {
	return range[u].first <= range[v].first && range[v].second <= range[u].second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	{
		int t = 0;
		dfs(1, -1, t);
		assert(t == n);
	}

	set<pair<int, int>> edges;

	MyST st(n);

	while (q--) {
		int u, v, w;
		cin >> u >> v;
		if (depth[u] > depth[v] || (depth[u] == depth[v] && u > v))
			swap(u, v);
		if (edges.count( { u, v })) {
			edges.erase( { u, v });
			w = -1;
		} else {
			edges.insert( { u, v });
			w = 1;
		}

		assert(!covers(v, u));

		if (covers(u, v)) {
			const int c = lcaCh(u, v);
			st.update(range[c].first, range[c].second, +w);
			st.update(range[v].first, range[v].second, -w);
		} else {
			const int l = lca(u, v);
			st.update(0, n - 1, +w);
			st.update(range[u].first, range[u].second, -w);
			st.update(range[v].first, range[v].second, -w);
		}

		const StVal res = st.query(0, n - 1);
		assert(res.mn >= 0);
		cout << (res.mn ? 0 : res.occ) << '\n';

	}
	return 0;
}