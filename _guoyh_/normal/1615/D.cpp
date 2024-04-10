# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int t;
int n, m;
int eu[MAXN], ev[MAXN], ew[MAXN];
struct Edge{
	int t, w, nxt;
	Edge(int t = 0, int w = 0, int nxt = 0): t(t), w(w), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v, int w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
}
int p[MAXN * 2];
int findroot(int nw){
	if (!p[nw]) return nw;
	else return p[nw] = findroot(p[nw]);
}
void mrg(int u, int v){
	// printf("mrg %d %d\n", u, v);
	u = findroot(u);
	v = findroot(v);
	if (u == v) return;
	p[u] = v;
}
int fa[MAXN];
void dfs(int nw){
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa[nw]) continue;
		fa[nxtn] = nw;
		// printf("nxtn %d %d %d\n", nw, nxtn, g[i].w);
		if (g[i].w != -1){
			if (__builtin_popcount(g[i].w) & 1){
				mrg(nw + n, nxtn);
				mrg(nw, nxtn + n);
			} else {
				mrg(nw, nxtn);
				mrg(nw + n, nxtn + n);
			}
		}
		dfs(nxtn);
	}
}
bool check(){
	for (int i = 1; i <= n; i++) if (findroot(i) == findroot(i + n)) return false;
	return true;
}
int cl[MAXN * 2];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		gsz = 0;
		for (int i = 1; i <= n; i++) fte[i] = 0;
		for (int i = 1; i <= n; i++) fa[i] = 0;
		for (int i = 1; i <= 2 * n; i++) p[i] = 0;
		for (int i = 1; i <= 2 * n; i++) cl[i] = -1;
		for (int i = 1; i <= n - 1; i++){
			scanf("%d%d%d", eu + i, ev + i, ew + i);
			addedge(eu[i], ev[i], ew[i]);
			addedge(ev[i], eu[i], ew[i]);
		}
		dfs(1);
		for (int i = 1; i <= m; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			for (int j = 0; j < 2; j++) mrg(u + j * n, v + (j ^ w) * n);
		}
		if (!check()){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for (int i = 1; i <= n; i++){
			if (cl[findroot(i)] == -1){
				cl[findroot(i)] = 0;
				cl[findroot(i + n)] = 1;
			}
		}
		for (int i = 1; i <= n - 1; i++){
			if (ew[i] != -1) printf("%d %d %d\n", eu[i], ev[i], ew[i]);
			else printf("%d %d %d\n", eu[i], ev[i], (cl[findroot(eu[i])] ^ cl[findroot(ev[i])]));
		}
	}
	return 0;
}