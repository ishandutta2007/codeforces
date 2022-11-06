#include <bits/stdc++.h>
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
using std::vector; using std::min; using std::max;
const int N = 5e5 + 5;
int n, m, a[N], b[N], out[N];
struct node { int x, y; } c[N];
vector<node> itv;
int ID(int x, int y) { return x * m + y; }
char gc() {
	char c;
	while (c = getchar(), c != '.' && c != '#');
	return c;
}
vector<int> G[N], H[N];
void addG(int u, int v) { G[u].push_back(v); }
void addH(int u, int v) { H[u].push_back(v); }
int dfn[N], low[N], scc[N], st[N], top = 0, cnt = 0, dfs_clock = 0;
void tarjan(int u) {
	dfn[u] = low[u] = ++dfs_clock;
	st[++top] = u;
	for (int v : G[u]) {
		if (!dfn[v]) tarjan(v), chkmin(low[u], low[v]);
		else if (!scc[v]) chkmin(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		cnt++;
		for (;;) {
			int x = st[top--];
			scc[x] = cnt;
			if (x == u) break;
		}
	}
}
int vis[N];
void dfs(int u) {
	if (vis[u]) return;
	vis[u] = 1;
	for (int v : H[u])
		dfs(v), chkmin(c[u].x, c[v].x), chkmax(c[u].y, c[v].y);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j < m; j++) {
			char c = gc();
			a[ID(i, j)] = c == '#';
		}
	for (int j = 0; j < m; j++)
		for (int i = 0, x = -1, y = -1, z = -1; i < n; i++) {
			if (j && a[ID(i, j - 1)]) x = i;
			if (j < m - 1 && a[ID(i, j + 1)]) z = i;
			if (a[ID(i, j)]) {
				if (x != -1) addG(ID(x, j - 1), ID(i, j));
				if (y != -1) addG(ID(y, j), ID(i, j));
				if (z != -1) addG(ID(z, j + 1), ID(i, j));
				if (i < n - 1 && a[ID(i + 1, j)]) addG(ID(i + 1, j), ID(i, j));
				y = i;
			}
		}
	for (int j = 0; j < m; j++) scanf("%d", &b[j]);
	for (int i = 0; i < n * m; i++)
		if (!dfn[i] && a[i]) tarjan(i);
	for (int i = 0; i < n * m; i++) {
		if (!a[i]) continue;
		for (int j : G[i]) {
			int u = scc[i], v = scc[j];
			if (u != v) addH(u, v), out[u] = 1;
		}
	}
	for (int i = 1; i <= cnt; i++) c[i] = {1 << 30, 0};
	for (int i = 0; i < n * m; i++) {
		int u = scc[i];
		if (a[i] && !out[u])
			chkmin(c[u].x, i % m), chkmax(c[u].y, i % m), vis[u] = 1;
	}
	for (int i = 1; i <= cnt; i++) dfs(i);
	for (int j = 0; j < m; j++)
		if (b[j])
			for (int i = 0, t = 0; i < n; i++)
				if (a[ID(i, j)]) {
					t++;
					if (t == b[j]) { itv.push_back(c[scc[ID(i, j)]]); break; }
				}
	std::sort(itv.begin(), itv.end(), [](node a, node b) { return a.y < b.y; });
	int ans = 0, now = -1;
	for (auto tmp : itv) 
		if (tmp.x > now) ans++, now = tmp.y;
	printf("%d\n", ans);
	return 0;
}