# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MAXA = 45;
const ll INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
	int t;
	ll w;
	int nxt;
	Edge(int t = 0, ll w = 0, int nxt = 0): t(t), w(w), nxt(nxt){}
} g[MAXN * 2];
int n, m, q, asz, gsz;
int fte[MAXN];
void addedge(int u, int v, int w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
}
int p[MAXN];
int findroot(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = findroot(p[nw]);
}
int dep[MAXN];
int fa[MAXN][21];
ll fd[MAXN][21];
void dfs0(int nw){
	// printf("dfs0 %d %d\n", nw, fa[nw][0]);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		dep[nxtn] = dep[nw] + 1;
		fa[nxtn][0] = nw;
		fd[nxtn][0] = g[i].w;
		for (int j = 1; j <= 20; j++){
			fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
			fd[nxtn][j] = fd[nxtn][j - 1] + fd[fa[nxtn][j - 1]][j - 1];
		}
		dfs0(nxtn);
	}
}
ll getdis(int u, int v){
	if (dep[u] < dep[v]) swap(u, v);
	ll ans = 0;
	for (int i = 20; i >= 0; i--){
		if (dep[u] - (1 << i) >= dep[v]){
			ans += fd[u][i];
			u = fa[u][i];
		}
	}
	if (u == v) return ans;
	for (int i = 20; i >= 0; i--){
		if (fa[u][i] != fa[v][i]){
			ans += fd[u][i] + fd[v][i];
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return ans + fd[u][0] + fd[v][0];
}
int a[MAXA];
int b[MAXN];
ll f[MAXA][MAXA];
ll dis[MAXA][MAXN];
void dfs1(int nw, int rt, int fa = -1){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dis[rt][nxtn] = dis[rt][nw] + g[i].w;
		dfs1(nxtn, rt, nw);
	}
}
int main(){
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		int ru = findroot(u), rv = findroot(v);
		if (ru == rv){
			if (!b[u]){
				a[++asz] = u;
				b[u] = asz;
			}
			if (!b[v]){
				a[++asz] = v;
				b[v] = asz;
			}
			f[b[u]][b[v]] = f[b[v]][b[u]] = min(f[b[u]][b[v]], 1ll * w);
		} else {
			p[ru] = rv;
			addedge(u, v, w);
			addedge(v, u, w);
		}
	}
	dfs0(1);
	for (int i = 1; i <= asz; i++){
		for (int j = 1; j <= asz; j++){
			f[i][j] = min(f[i][j], getdis(a[i], a[j]));
		}
	}
	for (int k = 1; k <= asz; k++){
		for (int i = 1; i <= asz; i++){
			for (int j = 1; j <= asz; j++){
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= asz; i++) dfs1(a[i], i);
	scanf("%d", &q);
	while (q--){
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = getdis(u, v);
		// printf("ans %lld\n", ans);
		for (int i = 1; i <= asz; i++){
			for (int j = 1; j <= asz; j++){
				ans = min(ans, dis[i][u] + f[i][j] + dis[j][v]);
				// printf("ans %lld\n", ans);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}