# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 1000051;
struct Edge{
	int t, nxt;
} g[MAXN << 1];
int n, gsz, cnt;
int fte[MAXN];
int dfn[MAXN], sz[MAXN];
int dep[MAXN], hgt[MAXN];
int fa[MAXN], hs[MAXN], top[MAXN];
int f[MAXN], ans[MAXN];
void addedge(int u, int v){
	g[++gsz] = (Edge){v, fte[u]};
	fte[u] = gsz;
}
void dfs0(int nw){
	sz[nw] = 1;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		fa[nxtn] = nw;
		dep[nxtn] = dep[nw] + 1;
		dfs0(nxtn);
		if (hgt[nxtn] + 1 > hgt[nw]){
			hgt[nw] = hgt[nxtn] + 1;
			hs[nw] = nxtn;
		}
		sz[nw] += sz[nxtn];
	}
}
void dfs1(int nw){
	dfn[nw] = ++cnt;
	if (hs[nw]){
		top[hs[nw]] = top[nw];
		dfs1(hs[nw]);
	}
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw] || nxtn == hs[nw]) continue;
		top[nxtn] = nxtn;
		dfs1(nxtn);
	}
}
void dfs3(int nw){
	if (hs[nw]){
		dfs3(hs[nw]);
		ans[nw] = ans[hs[nw]] + 1;
	}
	f[dfn[nw]] = 1;
	if (f[dfn[nw] + ans[nw]] <= 1) ans[nw] = 0;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw] || nxtn == hs[nw]) continue;
		dfs3(nxtn);
		for (int j = 0; j <= hgt[nxtn]; j++){
			f[dfn[nw] + j + 1] += f[dfn[nxtn] + j];
			if (f[dfn[nw] + j + 1] > f[dfn[nw] + ans[nw]]) ans[nw] = j + 1;
			if (f[dfn[nw] + j + 1] == f[dfn[nw] + ans[nw]] && j + 1 < ans[nw]) ans[nw] = j + 1;
		}
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(v, u);
		addedge(u, v);
	}
	dfs0(1);
	dfs1(1);
	dfs3(1);
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}