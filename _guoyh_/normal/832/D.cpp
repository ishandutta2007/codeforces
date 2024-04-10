# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 100051;
int n, q;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int dep[MAXN];
int fa[MAXN][21];
void dfs(int nw){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		dep[nxtn] = dep[nw] + 1;
		fa[nxtn][0] = nw;
		dfs(nxtn);
	}
}
int getlca(int u, int v){
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 20; i >= 0; i--){
		if (dep[v] - (1 << i) >= dep[u]) v = fa[v][i];
	}
	if (u == v) return u;
	for (int i = 20; i >= 0; i--){
		if (fa[u][i] != fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int getdis(int u, int v){
	return dep[u] + dep[v] - 2 * dep[getlca(u, v)];
}
int main(){
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++){
		int u;
		scanf("%d", &u);
		addedge(u, i);
		addedge(i, u);
	}
	dfs(1);
	for (int j = 1; j <= 20; j++){
		for (int i = 1; i <= n; i++){
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
	while (q--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		int dab = getdis(a, b), dbc = getdis(b, c), dca = getdis(c, a);
		int ans = (dab + dbc + dca - 2 * min(dab, min(dbc, dca))) / 2;
		printf("%d\n", ans + 1);
	}
	return 0;
}