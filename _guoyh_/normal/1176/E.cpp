# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 200051;
const int MAXV = MAXN * 2;
const int MAXE = MAXN * 2;
int t, n, m;
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXE];
int gsz;
int fte[MAXV];
void addedge(int u, int v){
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
}
bool vis[MAXN];
int dep[MAXN];
vector <int> adj[2];
vector <int> ans;
void dfs(int nw){
	adj[dep[nw] & 1].push_back(nw);
	vis[nw] = true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (vis[nxtn]) continue;
		dep[nxtn] = dep[nw] + 1;
		dfs(nxtn);
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d", &n, &m);
		gsz = 0;
		memset(fte + 1, 0, sizeof(int) * n);
		memset(vis + 1, false, sizeof(bool) * n);
		ans.clear();
		for (int i = 1; i <= m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			addedge(u, v);
			addedge(v, u);
		}
		for (int i = 1; i <= n; i++){
			if (vis[i]) continue;
			adj[0].clear();
			adj[1].clear();
			dep[i] = 0;
			dfs(i);
			int id = adj[0].size() < adj[1].size() ? 0 : 1;
			for (int j = 0; j < adj[id].size(); j++) ans.push_back(adj[id][j]);
		}
		printf("%d\n", int(ans.size()));
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
		putchar('\n');
	}
	return 0;
}