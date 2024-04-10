# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 300000;
int n;
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
ll c[MAXN];
ll f[MAXN][3], s[MAXN];
vector <int> adj[MAXN * 3];
void dfs(int nw, int fa){
	int mn = -1, cnt = 0;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		dfs(nxtn, nw);
		s[nw] += f[nxtn][0];
		if (mn == -1 || f[nxtn][0] - f[nxtn][1] > f[mn][0] - f[mn][1]){
			mn = nxtn;
			cnt = 1;
		} else if (f[nxtn][0] - f[nxtn][1] == f[mn][0] - f[mn][1]) cnt++;
	}
	if (mn == -1){
		f[nw][0] = c[nw];
		f[nw][1] = 0;
		f[nw][2] = c[nw];
		// printf("f %d %lld %lld\n", nw, f[nw][0], f[nw][1]);
		return;
	}
	f[nw][0] = min(s[nw], s[nw] - f[mn][0] + f[mn][1] + c[nw]);
	f[nw][1] = s[nw] - f[mn][0] + f[mn][1];
	f[nw][2] = s[nw] - f[mn][0] + f[mn][1] + c[nw];
	// printf("f %d %lld %lld\n", nw, f[nw][0], f[nw][1]);
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (nxtn == fa) continue;
		if (f[nw][0] == s[nw] - f[nxtn][0] + f[nxtn][1] + c[nw]) adj[nw].push_back(nxtn + MAXN);
		if (f[nw][0] == s[nw] || nxtn != mn || cnt > 1) adj[nw].push_back(nxtn);
		if ((f[nw][0] == s[nw] || nxtn != mn || cnt > 1) && f[nxtn][2] == f[nxtn][0]) adj[nw].push_back(nxtn + 2 * MAXN);
		if (f[nw][1] == s[nw] - f[nxtn][0] + f[nxtn][1]) adj[nw + MAXN].push_back(nxtn + MAXN);
		if (nxtn != mn || cnt > 1) adj[nw + MAXN].push_back(nxtn);
		if ((nxtn != mn || cnt > 1) && f[nxtn][2] == f[nxtn][0]) adj[nw + MAXN].push_back(nxtn + 2 * MAXN);
		if (f[nw][2] == s[nw] - f[nxtn][0] + f[nxtn][1] + c[nw]) adj[nw + 2 * MAXN].push_back(nxtn + MAXN);
		if (nxtn != mn || cnt > 1) adj[nw + 2 * MAXN].push_back(nxtn);
		if ((nxtn != mn || cnt > 1) && f[nxtn][2] == f[nxtn][0]) adj[nw + 2 * MAXN].push_back(nxtn + 2 * MAXN);
	}
}
bool vis[MAXN * 3];
void dfs2(int nw){
	// printf("dfs %d\n", nw);
	vis[nw] = true;
	for (int i = 0; i < adj[nw].size(); i++){
		int nxtn = adj[nw][i];
		if (vis[nxtn]) continue;
		dfs2(nxtn);
	}
}
vector <int> bdj;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", c + i);
	for (int i = 1; i <= n - 1; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
	}
	dfs(1, 0);
	ll ans = f[1][0];
	if (f[1][0] == ans) dfs2(1);
	if (f[1][2] == ans) dfs2(1 + 2 * MAXN);
	for (int i = 1; i <= n; i++) if (vis[i + 2 * MAXN]) bdj.push_back(i);
	printf("%lld %d\n", ans, int(bdj.size()));
	for (int i = 0; i < bdj.size(); i++) printf("%d ", bdj[i]);
	putchar('\n');
	return 0;
}