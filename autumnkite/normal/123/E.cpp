#include <cstdio>
#include <cctype>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
int n, x[N], y[N], sx, sy, sz[N];
int edge, to[N << 1], pr[N << 1], hd[N];
long long ans;
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
void dfs(int u, int fa = 0){
	sz[u] = 1;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa){
			dfs(v, u);
			sz[u] += sz[v], x[u] += x[v];
			ans += 1ll * y[u] * sz[v] * x[v];
		}
	ans += 1ll * y[u] * (n - sz[u]) * (sx - x[u]);
}
int main(){
	n = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	for (register int i = 1; i <= n; ++i)
		sx += x[i] = read(), sy += y[i] = read();
	dfs(1);
	printf("%.20lf", 1.0 * ans / sx / sy);
}