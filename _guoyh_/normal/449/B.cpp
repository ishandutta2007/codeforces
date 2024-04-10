# include <queue>
# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
const int MAXM = 300051;
struct Edge{
	int t;
	ll c;
	int nxt;
} g1[MAXM * 2], g2[MAXN * 2];
struct Node{
	int id;
	ll di;
	bool operator < (const Node &o) const{
		return di > o.di;
	}
};
int n, m, k, gsz1 = 1, gsz2 = 1;
ll dis[MAXN];
bool flag[MAXN];
int fte1[MAXN], fte2[MAXN], pre[MAXN];
void addedge1(int x, int y, ll z){
	g1[++gsz1] = (Edge){y, z, fte1[x]};
	fte1[x] = gsz1;
}
void addedge2(int x, int y, ll z){
	g2[++gsz2] = (Edge){y, z, fte2[x]};
	fte2[x] = gsz2;
}
void dijkstra(){
	memset(dis, 0x3f, sizeof(dis));
	memset(pre, -1, sizeof(pre));
	priority_queue <Node> q;
	dis[1] = 0;
	q.push((Node){1, 0});
	while (!q.empty()){
		Node nw = q.top();
		q.pop();
		if (dis[nw.id] < nw.di) continue;
		// printf("nw %d %lld\n", nw.id, nw.di);
		if (pre[nw.id] != -1) flag[pre[nw.id]] = true;
		for (int i = fte1[nw.id]; i; i = g1[i].nxt){
			Node nxtn = (Node){g1[i].t, nw.di + g1[i].c};
			if (nxtn.di < dis[nxtn.id]){
				dis[nxtn.id] = nxtn.di;
				pre[nxtn.id] = -1;
				q.push(nxtn);
			} else if (nxtn.di == dis[nxtn.id]) pre[nxtn.id] = -1;
		}
		for (int i = fte2[nw.id]; i; i = g2[i].nxt){
			Node nxtn = (Node){g2[i].t, nw.di + g2[i].c};
			// printf("nxtn %d %lld\n", nxtn.id, nxtn.di);
			if (nxtn.di < dis[nxtn.id]){
				dis[nxtn.id] = nxtn.di;
				pre[nxtn.id] = i >> 1;
				q.push(nxtn);
			}
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++){
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		addedge1(u, v, w);
		addedge1(v, u, w);
	}
	for (int i = 1; i <= k; i++){
		int s;
		ll y;
		scanf("%d%lld", &s, &y);
		addedge2(1, s, y);
		addedge2(s, 1, y);
	}
	dijkstra();
	int cnt = 0;
	for (int i = 1; i <= k; i++) cnt += (!flag[i]);
	printf("%d\n", cnt);
	return 0;
}