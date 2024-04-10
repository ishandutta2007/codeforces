/*input
6 8 2
1 3
1 5
1 6
2 5
2 6
3 4
3 5
5 6
4 8
4 7

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cassert>

using namespace std;

const int MAXN = 200006;

const int SIZE = MAXN * 3;
int par[SIZE], ch[SIZE][2], rev[SIZE], cost[SIZE], maxcost[SIZE], sz[SIZE];
int st[SIZE], top, counter;

int N, M, Q, E[MAXN][2], ans[MAXN];
bool used[MAXN];

void init() { counter = N; for (int i = 1; i <= N; ++i) sz[i] = 1; }
void update(int u) { maxcost[u] = max(cost[u], max(maxcost[ch[u][0]], maxcost[ch[u][1]])), sz[u] = (u <= N) + sz[ch[u][0]] + sz[ch[u][1]]; }
bool isroot(int u) { return u != ch[par[u]][0] && u != ch[par[u]][1]; }
bool dir(int u) { return u == ch[par[u]][1]; }
void reset(int u) { par[u] = ch[u][0] = ch[u][1] = 0; sz[u] = 1; }

void rotate(int u)
{
	int p = par[u], g = par[p], d = dir(u);
	if (!isroot(p)) { ch[g][dir(p)] = u; } par[u] = g;
	par[ch[p][d] = ch[u][!d]] = p;
	par[ch[u][!d] = p] = u;
	update(p), update(u);
}

void pushdown(int u)
{
	if (rev[u]) {
		rev[u] = 0;
		rev[ch[u][0]] ^= 1, rev[ch[u][1]] ^= 1;
		swap(ch[u][0], ch[u][1]);
	}
}

void splay(int u)
{
	st[top = 1] = u;
	for (int v = u; !isroot(v); v = par[v]) st[++top] = par[v];
	while (top) pushdown(st[top--]);
	for (; !isroot(u); rotate(u)) if (!isroot(par[u])) rotate(dir(u) == dir(par[u]) ? par[u] : u);
}

void access(int u)
{
	for (int v = 0; u; v = u, u = par[v]) {
		splay(u);
		ch[u][1] = v;
		update(u);
	}
}

void makeroot(int u)
{
	access(u), splay(u);
	rev[u] = 1;
}

void link(int u, int v, int c)
{
	// cout << "link " << u << ' ' << v << ' ' << c << endl;
	makeroot(v), makeroot(u);
	int w = ++counter;
	cost[w] = c;
	par[u] = par[v] = w;
}

bool same(int u, int v)
{
	makeroot(u), access(v), splay(v);
	return !isroot(u);
}

void cut(int u, int v)
{
	// cout << "cut " << u << ' ' << v << endl;
	makeroot(u), access(v);
	reset(u), reset(v);
}

void get(int u, int v, int &len, int &c)
{
	makeroot(u), access(v), splay(v);
	len = sz[v], c = maxcost[v];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> Q;
	init();

	for (int i = 1; i <= M; ++i) cin >> E[i][0] >> E[i][1];

	int r; // first to have odd cycle
	for (r = 1; r <= M; ++r) {
		int u = E[r][0], v = E[r][1], len, id;
		if (!same(u, v)) { used[r] = true, link(u, v, r); continue; }
		get(u, v, len, id);
		// cout << u << ' ' << v << ": " << len << ' ' << id << endl;
		if (len & 1) break;
	}
	// cout << r << endl;

	if (r > M) {
		while (Q--) puts("NO");
		return 0;
	}

	ans[M + 1] = r;
	for (int i = M; i >= 1; --i) {
		int u = E[i][0], v = E[i][1], len, id;
		if (same(u, v)) {
			get(u, v, len, id);
			// cout << u << ' ' << v << ": " << len << ' ' << id << endl;
			if (len & 1) {
				if (id == 0) {
					for (; i >= 1; --i) ans[i] = 0;
					break;
				}
				for (int j = r - 1; j >= id; --j) if (used[j]) used[j] = false, cut(E[j][0], E[j][1]);
				r = id;
				link(u, v, 0);
			} else {
				if (id != 0) {
					used[id] = false, cut(E[id][0], E[id][1]);
					link(u, v, 0);
				}
			}
		} else {
			link(u, v, 0);
		}

		// cout << i << ": " << u << ' ' << v << endl;
		ans[i] = r;
	}

	while (Q--) {
		int u, v;
		cin >> u >> v;
		puts(u > ans[v + 1] ? "YES" : "NO");
	}
}