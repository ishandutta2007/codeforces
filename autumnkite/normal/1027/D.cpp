#include <algorithm>
#include <cstdio>
#define N 200005
int n, c[N], a[N];
int edge, to[N], pr[N], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int idx, dfn[N], low[N], vis[N], top, sta[N], cnt, col[N], mn[N], sz[N], cal[N];
void tarjan(int u){
	vis[sta[++top] = u] = 1, dfn[u] = low[u] = ++idx;
	for (register int i = hd[u]; i; i = pr[i]){
		int v = to[i];
		if (!dfn[v])tarjan(v), low[u] = std :: min(low[u], low[v]);
		else if (vis[v]) low[u] = std :: min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]){
		mn[++cnt] = 0x3f3f3f3f, sz[cnt] = 0;
		while (sta[top + 1] != u){
			col[sta[top]] = cnt;
			mn[cnt] = std :: min(mn[cnt], c[sta[top]]);
			++sz[cnt];
			vis[sta[top--]] = 0;
		}
	}
}
int main(){
	scanf("%d", &n);
	for (register int i = 1; i <= n; ++i) scanf("%d", c + i);
	for (register int i = 1; i <= n; ++i) scanf("%d", a + i), addedge(i, a[i]);
	cnt = 0;
	for (register int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
	int ans = 0;
	for (register int i = 1; i <= n; ++i)
		if (!cal[col[i]] && (sz[col[i]] > 1 || a[i] == i)) ans += mn[col[i]], cal[col[i]] = 1;
	printf("%d", ans);
	getchar(), getchar();
}