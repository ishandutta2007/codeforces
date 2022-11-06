#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct V {
	pair<int, int> min1 = { +(int) 1e6, -2 }, min2 = { +(int) 1e7, -1 };
	pair<int, int> max1 = { -(int) 1e6, -2 }, max2 = { -(int) 1e7, -1 };

	V() {
	}

	V(const int u, const int p) {
		min1 = max1 = {p, u};
		assert(p >= 0);
	}

	V(const V &v1, const V &v2) {
		min1 = min(v1.min1, v2.min1);
		min2 = min(max(v1.min1, v2.min1), min(v1.min2, v2.min2));
		assert(min2.second != -1);

		max1 = max(v1.max1, v2.max1);
		max2 = max(min(v1.max1, v2.max1), max(v1.max2, v2.max2));
		assert(max2.second != -1);
	}
};

struct SegTree {
	int n;
	vector<V> st;
	vector<int> leaves;

	SegTree(const int n, int * pos) :
			n(n) {
		leaves.resize(n);
		init(1, 0, n - 1, pos);
	}

	void init(const int si, const int lo, const int hi, int * pos) { // init st[] and leaves[]
		if (lo == hi) {
			if (si >= (int) st.size())
				st.resize(si + 1);
			st[si] = V(lo, pos[lo]);
			leaves[lo] = si;
		} else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid, pos);
			init(si << 1 | 1, mid + 1, hi, pos);
			st[si] = V(st[si << 1], st[si << 1 | 1]); // optional if T(T(), T()) = T()
		}
	}

	V query(const int l, const int r) {
		return (l <= r && l < n && r >= 0) ? query(l, r, 1, 0, n - 1) : V();
	}
	V query(const int l, const int r, const int si, const int lo,
			const int hi) {
		if (l <= lo && hi <= r)
			return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid)
			return query(l, r, si << 1, lo, mid);
		if (mid < l)
			return query(l, r, si << 1 | 1, mid + 1, hi);
		return V(query(l, r, si << 1, lo, mid),
				query(l, r, si << 1 | 1, mid + 1, hi));
	}
};

const int MaxN = (int) 1e5 + 9;
vector<int> adj[MaxN + 9];
vector<int> parent[MaxN + 9];
int pos[MaxN + 9];
int depth[MaxN + 9];

void dfs(const int u, int &t) {
	pos[u] = t++;
	for (const int &v : adj[u]) {
		depth[v] = depth[u] + 1;
		parent[v] = {u};
		for (int i = 0; i < (int) parent[parent[v][i]].size(); ++i)
			parent[v].push_back(parent[parent[v][i]][i]);
		dfs(v, t);
	}
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, Q;
	cin >> n >> Q;
	for (int i = 2; i <= n; ++i) {
		int p;
		cin >> p;
		adj[p - 1].push_back(i - 1);
	}

	{
		int t = 0;
		dfs(0, t);
		assert(t == n);
	}

	SegTree st(n, pos);

	while (Q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		V res = st.query(l, r);

		const int u = lca(res.min2.second, res.max1.second);
		const int v = lca(res.min1.second, res.max2.second);
		if(depth[u] > depth[v])
			cout << res.min1.second + 1 << ' ' << depth[u] << '\n';
		else
			cout << res.max1.second  + 1<< ' ' << depth[v] << '\n';
	}
	return 0;
}