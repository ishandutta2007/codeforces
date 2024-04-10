# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 605;
struct Node{
	int di, id;
	Node(int di = 0, int id = 0): di(di), id(id){}
	bool operator < (const Node &o) const{
		return di > o.di;
	}
};
struct Edge{
	int t, w;
	Edge(int t = 0, int w = 0): t(t), w(w){}
};
int n, m;
int dis[MAXN];
vector <Edge> g[MAXN];
void dijkstra(int S){
	memset(dis, 0x3f, sizeof(dis));
	priority_queue <Node> q;
	int ssz = g[S].size();
	for (int i = 0; i < ssz; i++){
		int nxtn = g[S][i].t;
		if (dis[nxtn] <= g[S][i].w) continue;
		dis[nxtn] = g[S][i].w;
		q.push(Node(dis[nxtn], nxtn));
	}
	while (!q.empty()){
		Node nw = q.top();
		q.pop();
		if (dis[nw.id] < nw.di) continue;
		int sz = g[nw.id].size();
		for (int i = 0; i < sz; i++){
			int nxtn = (g[nw.id][i].t + dis[nw.id]) % n;
			if (dis[nxtn] <= dis[nw.id] + g[nw.id][i].w) continue;
			dis[nxtn] = dis[nw.id] + g[nw.id][i].w;
			q.push(Node(dis[nxtn], nxtn));
		}
		int nxtn = (nw.id + 1) % n;
		if (dis[nxtn] <= dis[nw.id] + 1) continue;
		dis[nxtn] = dis[nw.id] + 1;
		q.push(Node(dis[nxtn], nxtn));
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(Edge(v, w));
	}
	for (int i = 0; i < n; i++){
		dijkstra(i);
		for (int j = 0; j < n; j++) printf("%d ", i == j ? 0 : dis[j]);
		putchar('\n');
	}
	return 0;
}