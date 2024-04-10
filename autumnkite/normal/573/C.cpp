#include <cstdio>
#define N 100005
int n, a[N], bo[N];
int edge, to[N << 1], pr[N << 1], hd[N], dg[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge, ++dg[u];
}
void dfs(int u, int fa = 0){
	if (dg[u] > 2) return ++a[u], void(0);
	bo[u] = 1;
	for (register int i = hd[u]; i; i = pr[i])
		if (to[i] != fa) dfs(to[i], u);
}
int main(){
	scanf("%d", &n);
	for (register int i = 1, u, v; i < n; ++i)
		scanf("%d%d", &u, &v), addedge(u, v), addedge(v, u);
	for (register int i = 1; i <= n; ++i) if (dg[i] == 1) dfs(i);
	for (register int i = 1; i <= n; ++i) a[i] > 2 ? a[i] = 2 : 0;
	for (register int i = 1; i <= n; ++i)
		if (!bo[i]){
			int s = 0;
			for (register int j = hd[i]; j; j = pr[j])
				if (!bo[to[j]] && dg[to[j]] - a[to[j]] >= 2) ++s;
			if (s > 2) return printf("No"), 0;
		}
	printf("Yes\n");
}