#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 5005
int n, m, ans, vis[N];
int edge, to[N], pr[N], hd[N], col[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
void dfs(int u){
	vis[u] = 2;
	for (register int i = hd[u], v; i; i = pr[i])
		if (!vis[v = to[i]]) dfs(v);
		else if (vis[v] == 2) ans = 2;
	vis[u] = 1;
}
int main(){
	n = read(), m = read();
	for (register int i = 1, u, v; i <= m; ++i)
		u = read(), v = read(), addedge(u, v);
	ans = 1;
	for (register int i = 1; i <= n; ++i) if (!vis[i]) dfs(i);
	for (register int u = 1; u <= n; ++u)
		for (register int j = hd[u]; j; j = pr[j])
			if (u < to[j]) col[j] = 1; else col[j] = ans;
	printf("%d\n", ans);
	for (register int i = 1; i <= m; ++i) printf("%d ", col[i]);
}