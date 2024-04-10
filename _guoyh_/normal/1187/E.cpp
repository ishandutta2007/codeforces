# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int n, gsz;
int fte[MAXN];
int fa[MAXN], sz[MAXN];
ll tol, ans = 0;
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
void dfs0(int nw){
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		fa[nxtn] = nw;
		dfs0(nxtn);
		sz[nw] += sz[nxtn];
	}
	tol += sz[nw];
}
void dfs(int nw){
	ans = max(ans, tol);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		tol -= sz[nxtn];
		tol += n - sz[nxtn];
		dfs(nxtn);
		tol += sz[nxtn];
		tol -= n - sz[nxtn];
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs0(1);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}