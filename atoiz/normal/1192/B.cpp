/*input
4 3 2000
1 2 100
2 3 1000
2 4 1000
2 1030
1 1020
1 890

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAXN = 200200;
const long long INF = 2e18;
int N, Q;
long long W;
struct Edge { int u, v; long long w; } edges[MAXN];
vector<int> G[MAXN];
int in[MAXN], out[MAXN], vertex[MAXN];
long long A[MAXN], dep[MAXN];

struct Node
{
	long long d1, d2, d12, d23, d123, inc;

	void update(long long d)
	{
		d1 += d, d2 += d, d12 -= d, d23 -= d, inc += d;
	}

	friend Node operator+ (Node n1, Node n2)
	{
		Node n;
		n.d1 = max(n1.d1, n2.d1);
		n.d2 = min(n1.d2, n2.d2);
		n.d12 = max(max(n1.d12, n2.d12), n1.d1 - 2 * n2.d2);
		n.d23 = max(max(n1.d23, n2.d23), -2 * n1.d2 + n2.d1);
		n.d123 = max(max(n1.d123, n2.d123), max(n1.d12 + n2.d1, n1.d1 + n2.d23));
		n.inc = 0;
		return n;
	}

	void push(Node &n1, Node &n2)
	{
		n1.update(inc); n2.update(inc); inc = 0;
	}
} tree[MAXN << 2];

void dfs(int u)
{
	static int timer = 0;
	in[u] = timer;
	for (int id : G[u]) if (vertex[id] != u) {
		int v = (edges[id].u == u ? edges[id].v : edges[id].u);
		vertex[id] = v;
		dep[v] = dep[u] + edges[id].w;

		A[timer++] = dep[u];
		dfs(v);
	}
	A[timer++] = dep[u];
	out[u] = timer;
}

#define MID ((lo + hi) >> 1)
#define ROOT1 (root << 1)
#define ROOT2 (root << 1 | 1)

void build(int root = 1, int lo = 0, int hi = 2 * N - 1)
{
	if (lo + 1 == hi) tree[root] = {A[lo], A[lo], -INF, -INF, 0, 0};
	else {
		build(ROOT1, lo, MID);
		build(ROOT2, MID, hi);
		tree[root] = tree[ROOT1] + tree[ROOT2];
	}
}

void update(long long d, int l, int r, int root = 1, int lo = 0, int hi = 2 * N - 1)
{
	if (l <= lo && hi <= r) {
		tree[root].update(d);
		return;
	}
	if (hi <= l || r <= lo) return;

	tree[root].push(tree[ROOT1], tree[ROOT2]);
	update(d, l, r, ROOT1, lo, MID);
	update(d, l, r, ROOT2, MID, hi);
	tree[root] = tree[ROOT1] + tree[ROOT2];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> Q >> W;
	for (int i = 0; i < N - 1; ++i) {
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
		G[edges[i].u].push_back(i);
		G[edges[i].v].push_back(i);
	}

	dfs(1);
	build();

	long long last = 0, d, e;
	int u;
	for (int q = 0; q < Q; ++q) {
		cin >> d >> e;
		d = (d + last) % (N - 1);
		e = (e + last) % W;
		u = vertex[d];
		update(e - edges[d].w, in[u], out[u]);
		edges[d].w = e;
		cout << (last = max(tree[1].d1, tree[1].d123)) << '\n';
	}
}