# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
struct Edge{
	int t;
	ll c;
	int nxt;
} g[MAXN * 3];
struct Node{
	int id;
	ll di;
	bool operator < (const Node &o) const{
		return di > o.di;
	}
};
int n, m, gsz;
int fte[MAXN];
ll dis[MAXN];
void addedge(int x, int y, ll z){
	g[++gsz] = (Edge){y, z, fte[x]};
	fte[x] = gsz;
}
void dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	priority_queue <Node> q;
	dis[0] = 0;
	q.push((Node){0, 0});
	while (!q.empty()){
		Node nw = q.top();
		q.pop();
		if (nw.di > dis[nw.id]) continue;
		for (int i = fte[nw.id]; i; i = g[i].nxt){
			Node nxtn = (Node){g[i].t, nw.di + g[i].c};
			if (nxtn.di >= dis[nxtn.id]) continue;
			dis[nxtn.id] = nxtn.di;
			q.push(nxtn);
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		addedge(u, v, w * 2);
		addedge(v, u, w * 2);
	}
	for (int i = 1; i <= n; i++){
		ll a;
		scanf("%lld", &a);
		addedge(0, i, a);
	}
	dijkstra();
	for (int i = 1; i <= n; i++) printf("%lld ", dis[i]);
	putchar('\n');
	return 0;
}