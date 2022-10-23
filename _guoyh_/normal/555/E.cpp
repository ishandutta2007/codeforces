# include <stack>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int MAXM = 200051;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXM * 4];
int n, m, q, gsz = 1, cnt, dsz;
int fte[MAXN * 2];
stack <int> st;
bool inst[MAXN];
int dfn[MAXN], low[MAXN], dcc[MAXN];
bool vis[MAXN];
int dep[MAXN];
int fa[MAXN][21];
int f1[MAXN], f2[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
void tarjan(int nw, int pre){
	// printf("tarjan %d %d\n", nw, pre);
	st.push(nw);
	inst[nw] = true;
	low[nw] = dfn[nw] = ++cnt;
	int ans = 0;
	for (int i = fte[nw]; i; i = g[i].nxt){
		if ((i ^ 1) == pre) continue;
		int nxtn = g[i].t;
		if (!dfn[nxtn]){
			tarjan(nxtn, i);
			low[nw] = min(low[nw], low[nxtn]);
		} else if (inst[nxtn]) low[nw] = min(low[nw], dfn[nxtn]);
	}
	if (low[nw] == dfn[nw]){
		dsz++;
		int lst = 0;
		while (!st.empty() && lst != nw){
			lst = st.top();
			dcc[lst] = dsz;
			inst[lst] = false;
			st.pop();
		}
	}
}
void dfs(int nw){
	vis[nw] = true;
	for (int i = fte[nw + n]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		dep[nxtn] = dep[nw] + 1;
		fa[nxtn][0] = nw;
		for (int j = 1; j <= 20; j++) fa[nxtn][j] = fa[fa[nxtn][j - 1]][j - 1];
		dfs(nxtn);
	}
}
int lca(int u, int v){
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
bool dfs1(int nw){
	vis[nw] = true;
	for (int i = fte[nw + n]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw][0]) continue;
		if (!dfs1(nxtn)) return false;
		f1[nw] += f1[nxtn];
		f2[nw] += f2[nxtn];
	}
	// printf("dfs1 %d %d %d\n", nw, f1[nw], f2[nw]);
	return (f1[nw] == 0 || f2[nw] == 0);
}
int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	for (int i = 1; i <= n; i++){
		if (!dfn[i]) tarjan(i, -1);
	}
	// for (int i = 1; i <= n; i++) printf("dcc %d %d\n", i, dcc[i]);
	for (int i = 1; i <= n; i++){
		for (int j = fte[i]; j; j = g[j].nxt){
			int nxtn = g[j].t;
			if (dcc[i] != dcc[nxtn]) addedge(dcc[i] + n, dcc[nxtn]);
		}
	}
	for (int i = 1; i <= dsz; i++){
		if (!vis[i]) dfs(i);
	}
	for (int i = 1; i <= q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		u = dcc[u];
		v = dcc[v];
		if (u == v) continue;
		int l = lca(u, v);
		// printf("lca %d %d %d\n", u, v, l);
		f1[u]++;
		f1[l]--;
		f2[v]++;
		f2[l]--;
	}
	bool flag = true;
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= dsz; i++){
		if (vis[i]) continue;
		if (!dfs1(i)){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}