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
#define N 200005
int k, n;
int mx[N], cmx[N];
int rt, ed, dep[N], fa[N], cnt, p[N], on[N], col[N];
int edge, to[N << 1], pr[N << 1], hd[N];
void addedge(int u, int v){
	to[++edge] = v, pr[edge] = hd[u], hd[u] = edge;
}
std :: pair<int, int> dfs1(int u, int fa = 0){
	std :: pair<int, int> res(0, u), tmp;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa) tmp = dfs1(v, u), ++tmp.first, res = std :: max(res, tmp);
	return res;
}
void dfs2(int u){
	dep[u] = dep[fa[u]] + 1, mx[u] = cmx[u] = 0;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u]){
			fa[v] = u, dfs2(v);
			if (mx[v] + 1 > mx[u]) cmx[u] = mx[u], mx[u] = mx[v] + 1;
			else if (mx[v] + 1 > cmx[u]) cmx[u] = mx[v] + 1;
		}
}
void dfs3(int u, int c, int d){
	c = (c + d + k - 1) % k + 1, col[u] = c;
	for (register int i = hd[u], v; i; i = pr[i])
		if ((v = to[i]) != fa[u] && !on[v]) dfs3(v, c, d);
}
int main(){
	n = read(), k = read();
	for (register int i = 1, u, v; i < n; ++i)
		u = read(), v = read(), addedge(u, v), addedge(v, u);
	dfs2(rt = dfs1(1).second);
	for (register int i = 1; i <= n; ++i)
		if (cmx[i])
			if (mx[i] + 1 > dep[i]) if (dep[i] + cmx[i] >= k && k > 2) return printf("No\n"), 0; else continue;
			else if (mx[i] + cmx[i] + 1 >= k && k > 2) return printf("No\n"), 0; else continue;
	for (register int i = 1; i <= n; ++i)
		if (!ed || dep[i] > dep[ed]) ed = i;
	cnt = dep[ed];
	for (register int i = ed; i; i = fa[i]) p[dep[i]] = i, on[i] = 1, col[i] = (dep[i] - 1) % k + 1;
	for (register int i = 1; i <= cnt; ++i)
		for (register int j = hd[p[i]]; j; j = pr[j])
			if (!on[to[j]]) dfs3(to[j], col[p[i]], i <= cnt / 2 ? -1 : 1);
	printf("Yes\n");
	for (register int i = 1; i <= n; ++i) printf("%d ", col[i]); putchar('\n');
}