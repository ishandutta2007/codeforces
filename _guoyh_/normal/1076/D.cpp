# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
struct Edge{
	int t;
	ll c;
	int nxt;
} g[MAXN * 2];
struct Node{
	int id;
	ll di;
	bool operator < (const Node &o) const{
		return di > o.di;
	}
};
int n, m, k, gsz = 1, cnt;
int fte[MAXN];
bool vis[MAXN];
ll dis[MAXN];
int ans[MAXN];
void addedge(int x, int y, ll z){
	g[++gsz] = (Edge){y, z, fte[x]};
	fte[x] = gsz;
}
void dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	priority_queue <Node> q;
	dis[1] = 0;
	q.push((Node){1, 0});
	while (!q.empty()){
		Node nw = q.top();
		q.pop();
		if (nw.di > dis[nw.id]) continue;
		for (int i = fte[nw.id]; i; i = g[i].nxt){
			Node nxtn = (Node){g[i].t, nw.di + g[i].c};
			if (nxtn.di < dis[nxtn.id]){
				dis[nxtn.id] = nxtn.di;
				q.push(nxtn);
			}
		}
	}
}
bool dfs(int nw){
	vis[nw] = true;
	if (cnt >= k) return true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (vis[nxtn]) continue;
		if (dis[nxtn] < dis[nw] + g[i].c) continue;
		ans[++cnt] = (i >> 1);
		if (cnt >= k) return true;
		if (dfs(nxtn)) return true;
	}
	return false;
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dijkstra();
	dfs(1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++) printf("%d ", ans[i]);
	putchar('\n');
	return 0;
}