#include <bits/stdc++.h>

using namespace std;

struct DSU {
	std::vector<int> e;

	void init(int n) {
		e = std::vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

template <class T> struct SegmentTree {
	const T ID = 0;

	T comb(T a, T b) {
		return a ^ b;
	}

	int n;
	std::vector<T> seg;

	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) {
		seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	void add(int p, T val) {
		seg[p += n] += val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

const bool VALUES_IN_VERTICES = false;

template <class T> struct HeavyLight {
	std::vector<int> parent, heavy, depth, root, tree_pos;
	SegmentTree<T> tree;

	template <class G> int dfs(const G &graph, int v) {
		int size = 1, max_subtree = 0;
		for (int u : graph[v]) if (u != parent[v]) {
			parent[u] = v;
			depth[u] = depth[v] + 1;
			int subtree = dfs(graph, u);
			if (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;
			size += subtree;
		}
		return size;
	}

	template <class B> void process_path(int u, int v, B op) {
		for (; root[u] != root[v]; v = parent[root[v]]) {
			if (depth[root[u]] > depth[root[v]]) std::swap(u, v);
			op(tree_pos[root[v]], tree_pos[v]);
		}
		if (depth[u] > depth[v]) std::swap(u, v);
		op(tree_pos[u] + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);
	}

	template <class G>
	void init(const G &graph, vector<int> roots) {
		int n = (int)graph.size();
		heavy.assign(n, -1);
		parent.assign(n, 0);
		depth.assign(n, 0);
		root.assign(n, 0);
		tree_pos.assign(n, 0);
		tree.init(n);
		for (int r : roots) {
			parent[r] = -1;
			depth[r] = 0;
			dfs(graph, r);
		}
		for (int i = 0, current_pos = 0; i < n; ++i)
			if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int j = i; j != -1; j = heavy[j]) {
				root[j] = i;
				tree_pos[j] = current_pos++;
			}
	}

	void modify_path(int u, int v, const T &value) {
		process_path(u, v, [this, &value](int l, int r) { if (l == r) tree.add(l, value); });
	}
	
	T query_path(int u, int v) {
		T res = 0;
		process_path(u, v, [this, &res](int l, int r) { res = res ^ tree.query(l, r); });
		return res;
	}
};

/**
 * To support forest, just change 
 * init to take in a vector of roots, and DFS each of them
 */


template <class T> struct LazySeg2 {
	std::vector<T> sum, lazy;
	int sz;

	void init(int sz_) {
		sz = 1;
		while (sz < sz_) sz *= 2;
		sum.assign(2 * sz, 0);
		lazy.assign(2 * sz, 0);
	}

	void push(int ind, int L, int R) {
		sum[ind] = sum[ind] + lazy[ind];
		if (L != R) {
			lazy[2 * ind] = lazy[2 * ind] | lazy[ind];
			lazy[2 * ind + 1] = lazy[2 * ind + 1] | lazy[ind];
		}
		lazy[ind] = 0;
	}

	void pull(int ind) {
		sum[ind] = sum[2 * ind] | sum[2 * ind + 1];
	}

	void build() {
		for (int i = sz - 1; i >= 1; i--) {
			pull(i);
		}
	}

	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind, L, R);
			return;
		}
		int M = (L + R) / 2;
		upd(lo, hi, inc, 2 * ind, L, M);
		upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}

	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
			int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) | qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};

template <class T> struct HeavyLight2 {
	std::vector<int> parent, heavy, depth, root, tree_pos;
	LazySeg2<T> tree;

	template <class G> int dfs(const G &graph, int v) {
		int size = 1, max_subtree = 0;
		for (int u : graph[v]) if (u != parent[v]) {
			parent[u] = v;
			depth[u] = depth[v] + 1;
			int subtree = dfs(graph, u);
			if (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;
			size += subtree;
		}
		return size;
	}

	template <class B> void process_path(int u, int v, B op) {
		for (; root[u] != root[v]; v = parent[root[v]]) {
			if (depth[root[u]] > depth[root[v]]) std::swap(u, v);
			op(tree_pos[root[v]], tree_pos[v]);
		}
		if (depth[u] > depth[v]) std::swap(u, v);
		op(tree_pos[u] + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);
	}

	template <class G>
	void init(const G &graph, vector<int> roots) {
		int n = (int)graph.size();
		heavy.assign(n, -1);
		parent.assign(n, 0);
		depth.assign(n, 0);
		root.assign(n, 0);
		tree_pos.assign(n, 0);
		tree.init(n);
		for (int r : roots) {
			parent[r] = -1;
			depth[r] = 0;
			dfs(graph, r);
		}
		for (int i = 0, current_pos = 0; i < n; ++i)
			if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int j = i; j != -1; j = heavy[j]) {
				root[j] = i;
				tree_pos[j] = current_pos++;
			}
	}

	void modify_path(int u, int v, const T &value) {
		process_path(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
	}
	
	T query_path(int u, int v) {
		T res = 0;
		process_path(u, v, [this, &res](int l, int r) { res = res | tree.qsum(l, r); });
		return res;
	}
};

inline char gc() { // like getchar()
	static char buf[1 << 16];
	static size_t bc, be;
	if (bc >= be) {
		buf[0] = 0, bc = 0;
		be = fread(buf, 1, sizeof(buf), stdin);
	}
	return buf[bc++]; // returns 0 on EOF
}

int read_int() {
	int a, c;
	while ((a = gc()) < 40);
	if (a == '-') return -read_int();
	while ((c = gc()) >= 48) a = a * 10 + c - 480;
	return a - 48;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n = read_int();
	int q = read_int();
	vector<array<int, 3>> edges;
	DSU dsu;
	dsu.init(n);
	vector<vector<int>> g(n);
	for (int i = 0; i < q; ++i) {
		int u = read_int();
		int v = read_int();	
		int w = read_int();
		--u, --v;
		if (dsu.unite(u, v)) {
			g[u].push_back(v);
			g[v].push_back(u);
		}
		edges.push_back({u, v, w});
	}
	vector<int> roots;
	for (int i = 0; i < n; ++i) {
		if (dsu.get(i) == i) {
			roots.push_back(i);
		}
	}
	HeavyLight<int> heavy;
	HeavyLight2<bool> heavy2;
	heavy.init(g, roots);
	heavy2.init(g, roots);
	dsu.init(n);
	vector<int> ans;
	for (auto [u, v, w] : edges) {
		if (dsu.unite(u, v)) {
			cout << "YES" << '\n';
			heavy.modify_path(u, v, w);
			continue;
		}
		int res = heavy.query_path(u, v);
		int amt = heavy2.query_path(u, v);
		if (res == (w ^ 1) && amt == 0) {
			cout << "YES" << '\n';
			heavy2.modify_path(u, v, 1);
		} else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}