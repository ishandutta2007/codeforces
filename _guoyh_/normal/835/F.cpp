# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
int n;
ll ans;
struct Edge{
	int t, w, nxt;
	Edge(int t = 0, int w = 0, int nxt = 0): t(t), w(w), nxt(nxt){}
} g[MAXN * 2];
int gsz = 1;
int fte[MAXN];
void addedge(int u, int v, int w){
	g[++gsz] = Edge(v, w, fte[u]);
	fte[u] = gsz;
}
bool vis[MAXN];
int dg[MAXN];
ll dis[MAXN];
void topo(){
	queue <int> q;
	for (int i = 1; i <= n; i++){
		if (dg[i] == 1) q.push(i);
	}
	while (!q.empty()){
		int nw = q.front();
		q.pop();
		vis[nw] = true;
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (vis[nxtn]) continue;
			ans = max(ans, dis[nxtn] + dis[nw] + g[i].w);
			// printf("nxtn %d %lld\n", nxtn, dis[nxtn] + dis[nw] + g[i].w);
			dis[nxtn] = max(dis[nxtn], dis[nw] + g[i].w);
			if (--dg[nxtn] == 1) q.push(nxtn);
		}
	}
}
int rsz;
int r[MAXN * 2];
ll d[MAXN * 2], s[MAXN * 2];
void dfs1(int nw, int pre){
	r[++rsz] = nw;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if ((i ^ 1) == pre) continue;
		if (vis[nxtn]) continue;
		d[rsz + 1] = g[i].w;
		if (nxtn == r[1]) continue;
		dfs1(nxtn, i);
		break;
	}
}
int q1[MAXN * 2], ql1 = 1, qr1;
int q2[MAXN * 2], ql2 = 1, qr2;
int q3[MAXN * 2], ql3 = 1, qr3;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dg[u]++;
		dg[v]++;
		addedge(u, v, w);
		addedge(v, u, w);
	}
	topo();
	dfs1(find(vis + 1, vis + n + 1, false) - vis, 0);
	memcpy(r + rsz + 1, r + 1, sizeof(int) * rsz);
	memcpy(d + rsz + 2, d + 2, sizeof(ll) * rsz);
	for (int i = 1; i <= rsz * 2; i++){
		s[i] = s[i - 1] + d[i];
	}
	ll ans1 = 1e18;
	for (int i = 1; i <= rsz * 2; i++){
		while (ql2 <= qr2 && q2[ql2] <= i - rsz) ql2++;
		for (int j = q3[qr3] + 1; j <= q2[ql2] - 1; j++){
			while (ql3 <= qr3 && dis[r[q3[qr3]]] - s[q3[qr3]] <= dis[r[j]] - s[j]) qr3--;
			q3[++qr3] = j;
		}
		while (ql3 <= qr3 && q3[ql3] <= i - rsz) ql3++;
		while (ql1 <= qr1 && q1[ql1] <= q2[ql2]) ql1++;
		while (ql1 <= qr1 && dis[r[q1[qr1]]] + s[q1[qr1]] <= dis[r[i]] + s[i]) qr1--;
		q1[++qr1] = i;
		// printf("r %d %d %d %d %lld %lld %lld\n", i, r[i], q1[ql1], q2[ql2], dis[r[i]], s[i], dis[r[q1[ql1]]] + dis[r[q2[ql2]]] + s[q1[ql1]] - s[q2[ql2]]);
		ll nw = 0;
		if (ql1 <= qr1 && ql2 <= qr2) nw = max(nw, dis[r[q1[ql1]]] + dis[r[q2[ql2]]] + s[q1[ql1]] - s[q2[ql2]]);
		if (ql2 <= qr2 && ql3 <= qr3) nw = max(nw, dis[r[q2[ql2]]] + s[q2[ql2]] + dis[r[q3[ql3]]] - s[q3[ql3]]);
		if (i > rsz) ans1 = min(ans1, nw);
		while (ql2 <= qr2 && dis[r[q2[qr2]]] - s[q2[qr2]] < dis[r[i]] - s[i]) qr2--;
		q2[++qr2] = i;
	}
	printf("%lld\n", max(ans, ans1));
	return 0;
}