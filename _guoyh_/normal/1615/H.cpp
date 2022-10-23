# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1051;
const int MAXE = MAXN * 2;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m;
ll a[MAXN];
vector <int> adj[MAXN];
int vt[MAXN], vt1[MAXN];
ll ans[MAXN];
struct Edge{
	int t;
	ll c;
	int nxt;
	Edge(int t = 0, ll c = 0, int nxt = 0): t(t), c(c), nxt(nxt){}
} g[MAXE * 2];
int gsz = 1;
int fte[MAXN], curE[MAXN];
void addedge(int u, int v, ll c){
	g[++gsz] = Edge(v, c, fte[u]);
	fte[u] = gsz;
	g[++gsz] = Edge(u, 0, fte[v]);
	fte[v] = gsz;
}
int dep[MAXN];
int q[MAXN], ql, qr;
bool bfs(int S, int T, int vl, int vr){
	dep[S] = 0;
	dep[T] = -1;
	for (int i = vl; i <= vr; i++) dep[vt[i]] = -1;
	q[ql = qr = 1] = S;
	while (ql <= qr){
		int nw = q[ql++];
		for (int i = fte[nw]; i; i = g[i].nxt){
			int nxtn = g[i].t;
			if (g[i].c == 0 || dep[nxtn] != -1) continue;
			dep[nxtn] = dep[nw] + 1;
			q[++qr] = nxtn;
		}
		if (dep[T] != -1) return true;
	}
	return dep[T] != -1;
}
ll dfs(int nw, ll mxf, int T){
	if (nw == T) return mxf;
	if (!mxf) return 0;
	ll df = 0;
	for (int &i = curE[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		if (g[i].c == 0 || dep[nxtn] != dep[nw] + 1) continue;
		ll nwf = dfs(nxtn, min(mxf - df, g[i].c), T);
		if (!nwf) dep[nxtn] = -1;
		g[i].c -= nwf;
		g[i ^ 1].c += nwf;
		if ((df += nwf) == mxf) break;
	}
	return df;
}
ll dinic(int S, int T, int vl, int vr){
	ll ans = 0;
	while (bfs(S, T, vl, vr)){
		curE[S] = fte[S];
		curE[T] = fte[T];
		for (int i = vl; i <= vr; i++) curE[vt[i]] = fte[vt[i]];
		ans += dfs(S, INF, T);
	}
	return ans;
}
bool vis[MAXN];
void dfs1(int nw){
	vis[nw] = true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		if (!g[i].c) continue;
		int nxtn = g[i].t;
		if (!vis[nxtn]) dfs1(nxtn);
	}
}
bool flag[MAXN];
void solve(int vl, int vr, ll lft, ll rgt){
	if (vl > vr) return;
	// cout << "solve " << vl << ' ' << vr << ' ' << lft << ' ' << rgt << '\n';
	// for (int i = vl; i <= vr; i++) cout << vt[i] << ' ';
	// cout << '\n';
	if (lft == rgt){
		for (int i = vl; i <= vr; i++) ans[vt[i]] = lft;
		return;
	}
	for (int i = vl; i <= vr; i++) flag[vt[i]] = true;
	ll mid = (lft + rgt) >> 1;
	for (int i = vl; i <= vr; i++){
		int nw = vt[i];
		for (int j = 0; j < adj[nw].size(); j++) if (flag[adj[nw][j]]) addedge(nw, adj[nw][j], INF);
	}
	int S = n + 1, T = n + 2;
	for (int i = vl; i <= vr; i++){
		if (abs(a[vt[i]] - mid - 1) < abs(a[vt[i]] - mid)) addedge(S, vt[i], abs(a[vt[i]] - mid) - abs(a[vt[i]] - mid - 1));
		else addedge(vt[i], T, abs(a[vt[i]] - mid - 1) - abs(a[vt[i]] - mid));
	}
	dinic(S, T, vl, vr);
	int pl = vl - 1, pr = vr + 1;
	vis[S] = vis[T] = false;
	for (int i = vl; i <= vr; i++) vis[vt[i]] = false;
	dfs1(S);
	for (int i = vl; i <= vr; i++){
		if (vis[vt[i]]) vt1[--pr] = vt[i];
		else vt1[++pl] = vt[i];
	}
	gsz = 1;
	fte[S] = fte[T] = 0;
	for (int i = vl; i <= vr; i++) fte[vt[i]] = 0;
	memcpy(vt + vl, vt1 + vl, sizeof(int) * (vr - vl + 1));
	for (int i = vl; i <= vr; i++) flag[vt[i]] = false;
	solve(vl, pl, lft, mid);
	solve(pl + 1, vr, mid + 1, rgt);
}
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) vt[i] = i;
	solve(1, n, -1e15, 1e15);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}