#include <cstdio>
#define N 300005
#define P 998244353
int T, n, m, X[N], Y[N], Fa[N];
int edge, to[N << 1], pr[N << 1], hd[N];
int dep[N], cnt, num[N], ans;
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
int find(int x){
	return Fa[x] == x ? x : (Fa[x] = find(Fa[x]));
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if (fx != fy) Fa[fy] = fx, addedge(x, y), addedge(y, x);
}
void dfs(int u, int fa = 0){
	num[++cnt] = u;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) dep[v] = dep[u] + 1, dfs(v, u);
}
int calc(){
	int ans0 = 1, ans1 = 1;
	for (register int i = 1; i <= cnt; ++i)
		if (dep[num[i]] & 1) (ans1 <<= 1) %= P; else (ans0 <<= 1) %= P;
	return (ans0 + ans1) % P;
}
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		for (register int i = 1; i <= m; ++i) scanf("%d%d", X + i, Y + i);
		edge = 0, ans = 1;
		for (register int i = 1; i <= n; ++i) hd[i] = 0, Fa[i] = i, dep[i] = 0;
		for (register int i = 1; i <= m; ++i) merge(X[i], Y[i]);
		for (register int i = 1; i <= n; ++i)
			if (!dep[i]) dep[i] = 1, cnt = 0, dfs(i), ans = 1ll * ans * calc() % P;
		for (register int i = 1; i <= m; ++i)
			if ((dep[X[i]] & 1) == (dep[Y[i]] & 1)) { ans = 0; break; }
		printf("%d\n", ans);
	}
}