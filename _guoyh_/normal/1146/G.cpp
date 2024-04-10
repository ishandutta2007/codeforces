# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 55;
const int MAXV = MAXN * MAXN + MAXN + 2;
const int MAXE = MAXN * MAXN * 3 + MAXN;
int n, h, m;
struct Edge{
	int t, c, nxt;
	Edge(int t = 0, int c = 0, int nxt = 0): t(t), c(c), nxt(nxt){}
} g[MAXE * 2];
int gsz = 1;
int fte[MAXV];
void addedge(int u, int v, int c){
	g[++gsz] = Edge(v, c, fte[u]);
	fte[u] = gsz;
	g[++gsz] = Edge(u, 0, fte[v]);
	fte[v] = gsz;
}
int q[MAXV], ql, qr;
int dep[MAXV];
bool bfs(int S, int T){
	memset(dep, -1, sizeof(dep));
	q[ql = qr = 1] = S;
	dep[S] = 0;
	while (ql <= qr){
		int nw = q[ql++];
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (!g[i].c || ~dep[nxtn]) continue;
			dep[nxtn] = dep[nw] + 1;
			q[++qr] = nxtn;
		}
	}
	return dep[T] != -1;
}
int curE[MAXV];
int dfs(int nw, int mxf, int T){
	if (nw == T) return mxf;
	int df = 0;
	for (int &i = curE[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (!g[i].c || dep[nxtn] != dep[nw] + 1) continue;
		int nwf = dfs(nxtn, min(mxf - df, g[i].c), T);
		if (!nwf) dep[nxtn] = -1;
		g[i].c -= nwf;
		g[i ^ 1].c += nwf;
		if ((df += nwf) == mxf) break;
	}
	return df;
}
int dinic(int S, int T){
	int ans = 0;
	while (bfs(S, T)){
		memcpy(curE, fte, sizeof(fte));
		ans += dfs(S, INF, T);
	}
	return ans;
}
int main(){
	scanf("%d%d%d", &n, &h, &m);
	int S = n * h + m + 1, T = n * h + m + 2;
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= h; j++){
			if (j > 1) addedge((i - 1) * h + j, (i - 1) * h + j - 1, INF);
			ans += j * j - (j - 1) * (j - 1);
			addedge(S, (i - 1) * h + j, j * j - (j - 1) * (j - 1));
		}
	}
	for (int i = 1; i <= m; i++){
		int l, r, x, c;
		scanf("%d%d%d%d", &l, &r, &x, &c);
		if (++x > h) continue;
		for (int j = l; j <= r; j++) addedge((j - 1) * h + x, n * h + i, INF);
		addedge(n * h + i, T, c);
	}
	printf("%d", ans - dinic(S, T));
	return 0;
}