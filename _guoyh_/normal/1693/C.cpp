# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
# define fi first
# define se second
const int MAXN = 200051;
int n, m;
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
int dg[MAXN];
priority_queue<pii> q;
int dis[MAXN];
void dij(){
	memset(dis, 0x3f, sizeof(dis));
	dis[n] = 0;
	q.push(pii(-0, n));
	while (!q.empty()){
		pii nw = q.top();
		q.pop();
		if (dis[nw.se] < -nw.fi) continue;
		for (int i = fte[nw.se]; i; i = g[i].nxt){
			pii nxtn = pii(-(-nw.fi + dg[g[i].t]), g[i].t);
			dg[nxtn.se]--;
			if (dis[nxtn.se] <= -nxtn.fi) continue;
			dis[nxtn.se] = -nxtn.fi;
			q.push(nxtn);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		addedge(v, u);
		dg[u]++;
	}
	dij();
	cout << dis[1] << '\n';
	return 0;
}