/*input
9
7 9
2 8
2 1
7 5
4 7
2 4
9 6
3 9
1 8
4 8
2 9
9 5
7 6
1 3
4 6
5 3


*/

// https://codeforces.com/contest/1284/submission/68228329

#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <cctype>

using namespace std;

const int MAXN = 250007;

// dsu
int dsu[MAXN];
void init_dsu() { memset(dsu, -1, sizeof dsu); }
int find_root(int x) { return (dsu[x] < 0 ? x : dsu[x] = find_root(dsu[x])); }
bool same(int x, int y) { return find_root(x) == find_root(y); }
void join(int x, int y)
{
	x = find_root(x), y = find_root(y);
	if (x == y) return;
	if (dsu[x] > dsu[y]) swap(x, y);
	dsu[x] += dsu[y];
	dsu[y] = x;
}

// link-cut
int ch[MAXN][2], par[MAXN], st[MAXN], rev[MAXN], top;

bool is_root(int u) { return ch[par[u]][0] != u && ch[par[u]][1] != u; }
bool dir(int u) { return ch[par[u]][1] == u; }

void push(int u)
{
	if (rev[u]) {
		rev[ch[u][0]] ^= 1;
		rev[ch[u][1]] ^= 1;
		swap(ch[u][0], ch[u][1]);
		rev[u] = 0;
	}
}

void rotate(int u)
{
	int p = par[u], g = par[p], d = dir(u);
	if (!is_root(p)) { ch[g][dir(p)] = u; } par[u] = g;
	par[ch[p][d] = ch[u][d ^ 1]] = p;
	par[ch[u][d ^ 1] = p] = u;
}

void splay(int u)
{
	st[top = 1] = u;
	for (int v = u; !is_root(v); v = par[v]) st[++top] = par[v];
	while (top) push(st[top--]);
	for (; !is_root(u); rotate(u)) if (!is_root(par[u])) rotate(dir(u) == dir(par[u]) ? par[u] : u);
}

void access(int u)
{
	for (int v = 0; u; v = u, u = par[v]) {
		splay(u);
		ch[u][1] = v;
	}
}

void make_root(int u)
{
	access(u); splay(u);
	assert(rev[u] == 0);
	rev[u] ^= 1;
}

void link(int u, int v)
{
	make_root(u);
	par[u] = v;
}

void cut(int u, int v)
{
	make_root(u); access(v); splay(v);
	assert(ch[v][0] == u);
	par[u] = ch[v][0] = 0;
}

pair<int, int> find_edge(int u, int v) // closer to v
{
	make_root(u); access(v); splay(v);
	int x = 0, y = v, last = v;
	for (int w = v; w;) {
		last = w;
		push(w);

		if (same(w, v)) {
			y = w;
			w = ch[w][0];
		} else {
			x = w;
			w = ch[w][1];
		}
	}
	splay(last);
	// cout << u << ' ' << v << ": " << x << ' ' << y << endl;
	return make_pair(x, y);
}

vector<int> adj[MAXN];
int n;

void read(int &ans)
{
	ans = 0;
	register char ch = getchar();
	for (; !isdigit(ch); ch = getchar());
	for (; isdigit(ch); ch = getchar()) ans = ans * 10 + ch - 48;
}

void print(int x)
{
	if (x) {
		print(x / 10);
		putchar(48 + x % 10);
	}
}

void dfs(int v, int u)
{
	for (int w : adj[v]) {
		if (w == u) continue;
		dfs(w, v);
	}

	if (u) {
		pair<int, int> e = find_edge(u, v);
		print(u); putchar(' ');
		print(v); putchar(' ');
		print(e.first); putchar(' ');
		print(e.second); putchar('\n');
		cut(e.first, e.second);
		link(u, v);
		join(u, v);
	}
}

int main()
{
	read(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v; 
		read(u), read(v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		read(u), read(v);
		link(u, v);
	}

	init_dsu();
	print(n - 1); putchar('\n');
	dfs(1, 0);
}