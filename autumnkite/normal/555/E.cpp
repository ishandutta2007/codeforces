#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 500005
int n, m, q, x[N], y[N];
int edge = 1, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int idx, dfn[N], low[N], top, sta[N], nn, col[N];
void tarjan(int u, int fa = 0){
	dfn[u] = low[u] = ++idx, sta[++top] = u;
	for (register int i = hd[u], v; i; i = pr[i])
		if (!dfn[v = to[i]]) tarjan(v, i), low[u] = std :: min(low[u], low[v]);
		else if ((i ^ 1) != fa) low[u] = std :: min(low[u], dfn[v]);
	if (dfn[u] == low[u]){
		++nn;
		while (sta[top + 1] != u) col[sta[top--]] = nn;
	}
}
int fa[N][21], Rt[N], dep[N], up[N], down[N], vis[N];
void dfs(int u, int rt){
	Rt[u] = rt, dep[u] = dep[fa[u][0]] + 1;
	for (register int i = 1; i <= 20; ++i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u][0]) fa[v][0] = u, dfs(v, rt);
}
int lca(int u, int v){
	if (dep[u] < dep[v]) std :: swap(u, v);
	for (register int i = 20; ~i; --i)
		if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
	if (u == v) return u;
	for (register int i = 20; ~i; --i)
		if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}
void get(int u){
	vis[u] = 1;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u][0]) get(v), up[u] += up[v], down[u] += down[v];
}
int main(){
	n = read(), m = read(), q = read();
	for (register int i = 1; i <= m; ++i)
		x[i] = read(), y[i] = read(), addedge(x[i], y[i]), addedge(y[i], x[i]);
	for (register int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i);
	edge = 0, memset(hd, 0, sizeof hd), memset(pr, 0, sizeof pr);
	for (register int i = 1; i <= m; ++i)
		if (col[x[i]] != col[y[i]]) addedge(col[x[i]], col[y[i]]), addedge(col[y[i]], col[x[i]]);
	for (register int i = 1; i <= nn; ++i)
		if (!dep[i]) dfs(i, i);
	// for (register int i = 1; i <= nn; ++i) printf("%d %d\n", fa[i][0], dep[i]);
	while (q--){
		int u = col[read()], v = col[read()];
		if (Rt[u] != Rt[v]) return printf("No\n"), 0;
		int l = lca(u, v);
		// printf("%d %d %d\n", u, v, l);
		++up[u], --up[l], ++down[v], --down[l];
	}
	for (register int i = 1; i <= nn; ++i)
		if (!vis[i]) get(i);
	for (register int i = 1; i <= nn; ++i)
		if (up[i] && down[i]) return printf("No\n"), 0;
	printf("Yes\n");
}