#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
int T, n, fa[N], d[N], f[N], mx[N], cmx[N], g[N];
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
void get_f(int u){
	d[u] = mx[u] = cmx[u] = 0;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u]){
			fa[v] = u, get_f(v), ++d[u];
			if (f[v] > mx[u]) cmx[u] = mx[u], mx[u] = f[v];
			else if (f[v] > cmx[u]) cmx[u] = f[v];
		}
	f[u] = mx[u] + d[u] + (!mx[u]);
	// printf("f[%d]=%d\n", u, f[u]);
}
void get_g(int u){
	// printf("g[%d]=%d\n", u, g[u]);
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u]){
			if (f[v] != mx[u]) g[v] = std :: max(g[u], mx[u]) + d[u] - (fa[u] == 0) + (!std :: max(g[u], mx[u]));
			else g[v] = std :: max(g[u], cmx[u]) + d[u] - (fa[u] == 0) + (!std :: max(g[u], cmx[u]));
			get_g(v);
		}
}
void solve(){
	n = read();
	edge = 0;
	for (register int i = 1; i <= n; ++i) hd[i] = 0;
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	get_f(1), get_g(1);
	int ans = 0;
	for (register int u = 1; u <= n; ++u){
		int d = (fa[u] != 0), mx = g[u], cmx = 0;
		for (register int i = hd[u], v; i; i = pr[i])
			if ((v = to[i]) != fa[u]){
				++d;
				if (f[v] > mx) cmx = mx, mx = f[v];
				else if (f[v] > cmx) cmx = f[v];
			}
		ans = std :: max(ans, d + mx + cmx - 1 + (!mx) + (!cmx));
	}
	printf("%d\n", ans);
}
int main(){
	T = read();
	while (T--) solve();
}