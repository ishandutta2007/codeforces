#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
const long long INF = 1e15;

int n, m, q;
vector<int> gr[N], girls[N];
int in[N], out[N], sz[N], c[N], nxt[N], pos[N], girl_at[N], par[N], ver[N], order[N];
long long w[N];

struct Node 
{ 
	long long w; int u, id;
	bool operator< (const Node &nd) const
	{
		if (w != nd.w) return w < nd.w;
		return u < nd.u;
	}
} cur_min[N << 2];
long long lazy[N << 2];

void push(int root, int lo, int hi)
{
	if (lo < hi) {
		cur_min[root << 1].w += lazy[root];
		cur_min[root << 1 | 1].w += lazy[root];
		lazy[root << 1] += lazy[root];
		lazy[root << 1 | 1] += lazy[root];
		lazy[root] = 0;
	}
}

void build(int root = 1, int lo = 1, int hi = m)
{
	if (lo == hi) {
		int g = girl_at[lo];
		cur_min[root] = {g, c[g], g};
		return;
	}
	int mid = (lo + hi) >> 1;
	build(root << 1, lo, mid);
	build(root << 1 | 1, mid + 1, hi);
	cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
}

void upd(int l, int r, long long x, int root = 1, int lo = 1, int hi = m)
{
//	if (root == 1) cerr << l << ' ' << r << ' ' << x << endl;
	if (hi < l || r < lo) return;
	if (l <= lo && hi <= r) {
		cur_min[root].w += x;
		lazy[root] += x;
		return;
	}
	
	push(root, lo, hi);
	int mid = (lo + hi) >> 1;
	upd(l, r, x, root << 1, lo, mid);
	upd(l, r, x, root << 1 | 1, mid + 1, hi);
	cur_min[root] = min(cur_min[root << 1], cur_min[root << 1 | 1]);
}

Node get(int l, int r, int root = 1, int lo = 1, int hi = m)
{
//	if (root == 1) cerr << l << ' ' << r << endl;
	if (hi < l || r < lo) return {INF, 0, 0};
	if (l <= lo && hi <= r) return cur_min[root];
	
	push(root, lo, hi);
	int mid = (lo + hi) >> 1;
	return min(get(l, r, root << 1, lo, mid), get(l, r, root << 1 | 1, mid + 1, hi));
}

void dfs1(int u)
{
	sz[u] = 1;
	for (int &v : gr[u]) {
		if (v == par[u]) swap(v, gr[u].back());
		if (v != par[u]) {
			par[v] = u;
			dfs1(v);
			sz[u] += sz[v];
			if (sz[v] > sz[gr[u][0]]) swap(v, gr[u][0]);
		}
	}
	if (u != 1) gr[u].pop_back();
}

void dfs2(int u)
{
	static int cur_time = 0;
	static int cur_order = 0;
	
	in[u] = cur_time + 1;
	order[u] = ++cur_order;
	for (int &i : girls[u]) {
		girl_at[pos[i] = ++cur_time] = i;
	}
	for (int &v : gr[u]) {
		nxt[v] = (v == gr[u][0] ? nxt[u] : v);
		dfs2(v);
	}
	out[u] = cur_time;
}

int get_hld(int u, int v)
{
	Node ans = {INF, 0, 0};
	while (true) {
		if (order[u] < order[v]) swap(u, v);
		if (nxt[u] == nxt[v]) {
			ans = min(ans, get(in[v], in[u] + (int) girls[u].size() - 1));
			break;
		}
		ans = min(ans, get(in[nxt[u]], in[u] + (int) girls[u].size() - 1));
		u = par[nxt[u]];
	}
	return (ans.w < INF ? ans.id : 0);
}

int main()
{
//	freopen("phamdangkhoa.inp", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &c[i]);
		girls[c[i]].push_back(i);
	}
	
	dfs1(1);
	nxt[1] = 1;
	dfs2(1);
	build();
	
//	for (int i = 1; i <= m; ++i) cerr << girl_at[i] << ' '; cerr << endl;
	
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int u, v, k;
			scanf("%d %d %d", &u, &v, &k);
			int sz;
			for (sz = 0; sz < k; ++sz) {
				if (!(ver[sz] = get_hld(u, v))) break;
				upd(pos[ver[sz]], pos[ver[sz]], INF);
			}
			printf("%d", sz);
			for (int i = 0; i < sz; ++i) printf(" %d", ver[i]);
			puts("");
		} else {
			int u, k;
			scanf("%d %d", &u, &k);
			upd(in[u], out[u], k);
		}
	}
}