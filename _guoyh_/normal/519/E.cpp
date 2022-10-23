# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
struct Edge{
	int t, nxt;
} g[MAXN * 2];
int n, m, gsz;
int sz[MAXN], dep[MAXN], fte[MAXN];
int fa[MAXN][21];
void addedge(int x, int y){
	g[++gsz] = (Edge){y, fte[x]};
	fte[x] = gsz;
}
void dfs(int nw){
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		fa[nxtn][0] = nw;
		dep[nxtn] = dep[nw] + 1;
		for (int j = 1; j <= 20; j++) fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
		dfs(nxtn);
		sz[nw] += sz[nxtn];
	}
}
int findAnc(int x, int k){
	for (int i = 20; i >= 0; i--){
		if ((k >> i) & 1) x = fa[x][i];
	}
	return x;
}
int lca(int x, int y){
	if (dep[x] < dep[y]) swap(x, y);
	x = findAnc(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = 20; i >= 0; i--){
		if (fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		int l = lca(u, v);
		int ans;
		if (dep[u] % 2 != dep[v] % 2) ans = 0;
		else if (dep[u] == dep[v]){
			if (u == v) ans = n;
			else ans = n - sz[findAnc(u, dep[u] - dep[l] - 1)] - sz[findAnc(v, dep[v] - dep[l] - 1)];
		} else {
			if (dep[u] < dep[v]) swap(u, v);
			int ns = findAnc(u, (dep[u] + dep[v]) / 2 - dep[l] - 1);
			ans = sz[fa[ns][0]] - sz[ns];
		}
		printf("%d\n", ans);
	}
	return 0;
}