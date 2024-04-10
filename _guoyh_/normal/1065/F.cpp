# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 1000051;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int n, k, gsz;
int fa[MAXN];
int fte[MAXN * 2];
bool lf[MAXN];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
int vt[MAXN];
int dep[MAXN];
void dfs0(int nw){
	vt[dep[nw]] = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		dep[nxtn] = dep[nw] + 1;
		dfs0(nxtn);
	}
	if (lf[nw]) addedge(nw, vt[max(0, dep[nw] - k)]);
}
int cnt, ssz;
int st[MAXN], tp;
int dfn[MAXN], low[MAXN], scc[MAXN];
bool inst[MAXN];
int w[MAXN];
void tarjan(int nw){
	// printf("tarjan %d\n", nw);
	dfn[nw] = low[nw] = ++cnt;
	st[++tp] = nw;
	inst[nw] = true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (!dfn[nxtn]){
			tarjan(nxtn);
			low[nw] = min(low[nw], low[nxtn]);
		} else if (inst[nxtn]) low[nw] = min(low[nw], dfn[nxtn]);
	}
	if (dfn[nw] == low[nw]){
		ssz++;
		while (st[tp] != nw){
			scc[st[tp]] = ssz;
			w[ssz] += lf[st[tp]];
			inst[st[tp]] = false;
			tp--;
		}
		scc[nw] = ssz;
		w[ssz] += lf[nw];
		inst[nw] = false;
		tp--;
	}
}
int f[MAXN];
int dfs1(int nw){
	// printf("dfs1 %d\n", nw);
	if (f[nw] != -1) return f[nw];
	int mx = 0;
	for (int i = fte[nw + n]; i; i = g[i].nxt){
		int nxtn = g[i].t - n;
		mx = max(mx, dfs1(nxtn));
	}
	return f[nw] = w[nw] + mx;
}
int main(){
	memset(lf, true, sizeof(lf));
	scanf("%d%d", &n, &k);
	for (int i = 2; i <= n; i++){
		scanf("%d", fa + i);
		addedge(fa[i], i);
		lf[fa[i]] = false;
	}
	dfs0(1);
	tarjan(1);
	for (int i = 1; i <= n; i++){
		// printf("scc %d %d\n", i, scc[i]);
		for (int j = fte[i]; j; j = g[j].nxt){
			int nxtn = g[j].t;
			if (scc[i] != scc[nxtn]) addedge(scc[i] + n, scc[nxtn] + n);
		}
	}
	memset(f, -1, sizeof(f));
	printf("%d\n", dfs1(scc[1]));
	return 0;
}