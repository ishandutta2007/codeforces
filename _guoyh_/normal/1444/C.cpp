# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
# define fi first
# define se second
const int MAXN = 1000051;
int n, m, k;
int c[MAXN];
vector <int> adj[MAXN];
pii e[MAXN];
bool flag[MAXN];
struct Edge{
	int t, nxt;
	Edge(int t = 0, int nxt = 0): t(t), nxt(nxt){}
} g[MAXN * 2];
int gsz;
int fte[MAXN];
void addedge(int u, int v){
	// cout << "addedge " << u << ' ' << v << '\n';
	g[++gsz] = Edge(v, fte[u]);
	fte[u] = gsz;
	g[++gsz] = Edge(u, fte[v]);
	fte[v] = gsz;
}
bool vis[MAXN], dis[MAXN], col[MAXN];
bool dfs(int nw){
	// cout << "dfs " << nw << '\n';
	vis[nw] = true;
	for (int i = fte[nw]; i; i = g[i].nxt){
		int nxtn = g[i].t;
		// cout << "nxtn " << nw << ' ' << nxtn << '\n';
		if (vis[nxtn] && dis[nxtn] == dis[nw]) return true;
		if (vis[nxtn]) continue;
		dis[nxtn] = dis[nw] ^ 1;
		if (dfs(nxtn)) return true;
	}
	return false;
}
bool chk(){
	for (int i = 1; i <= gsz; i++) vis[g[i].t] = false;
	for (int i = 1; i <= gsz; i++) if (!vis[g[i].t] && dfs(g[i].t)) return false;
	return true;
}
int p[MAXN];
int fdrt(int nw){
	if (p[nw] == nw) return nw;
	else return p[nw] = fdrt(p[nw]);
}
bool wrk0(int u){
	// cout << "wrk0 " << u << endl;
	if (adj[u].empty()) return true;
	int pos = lower_bound(e + 1, e + m + 1, pii(adj[u][0], adj[u][0]), [&](pii u, pii v){
		if (c[u.fi] != c[v.fi]) return c[u.fi] < c[v.fi];
		else return c[u.se] < c[v.se];
	}) - e;
	// cout << "pos " << pos << '\n';
	for (int i = pos; i <= m && c[e[i].fi] == u && c[e[i].se] == u; i++){
		addedge(e[i].fi, e[i].se);
		p[fdrt(e[i].fi)] = fdrt(e[i].se);
	}
	bool ans = chk();
	gsz = 0;
	for (int i = pos; i <= m && c[e[i].fi] == u && c[e[i].se] == u; i++) fte[e[i].fi] = fte[e[i].se] = 0;
	return ans;
}
bool wrk(int u){
	// cout << "wrk " << e[u].fi << ' ' << e[u].se << endl;
	int nsz = n;
	for (int i = u; i <= m && c[e[i].fi] == c[e[u].fi] && c[e[i].se] == c[e[u].se]; i++){
		if (col[e[i].fi] == col[e[i].se]){
			addedge(fdrt(e[i].fi), fdrt(e[i].se));
		} else {
			nsz++;
			addedge(fdrt(e[i].fi), nsz);
			addedge(fdrt(e[i].se), nsz);
		}
	}
	bool ans = chk();
	// cout << "ans " << ans << '\n';
	gsz = 0;
	for (int i = u; i <= m && c[e[i].fi] == c[e[u].fi] && c[e[i].se] == c[e[u].se]; i++) fte[fdrt(e[i].fi)] = fte[fdrt(e[i].se)] = 0;
	for (int i = n + 1; i <= nsz; i++) fte[i] = 0;
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++){
		cin >> c[i];
		adj[c[i]].push_back(i);
	}
	for (int i = 1; i <= m; i++){
		cin >> e[i].fi >> e[i].se;
		if (c[e[i].fi] > c[e[i].se]) swap(e[i].fi, e[i].se);
	}
	sort(e + 1, e + m + 1, [&](pii u, pii v){
		if (c[u.fi] != c[v.fi]) return c[u.fi] < c[v.fi];
		else return c[u.se] < c[v.se];
	});
	for (int i = 1; i <= n; i++) p[i] = i;
	// for (int i = 1; i <= m; i++) cout << "e " << e[i].fi << ' ' << e[i].se << '\n';
	int cnt = 0;
	for (int i = 1; i <= k; i++) cnt += (flag[i] = wrk0(i));
	memcpy(col, dis, sizeof(dis));
	// for (int i = 1; i <= n; i++) cout << col[i] << ' ';
	// cout << '\n';
	ll ans = 1ll * cnt * (cnt - 1) / 2;
	for (int i = 1; i <= m; i++){
		if (c[e[i].fi] == c[e[i - 1].fi] && c[e[i].se] == c[e[i - 1].se]) continue;
		if (c[e[i].fi] == c[e[i].se]) continue;
		if (!flag[c[e[i].fi]] || !flag[c[e[i].se]]) continue;
		if (!wrk(i)) ans--;
	}
	cout << ans << '\n';
	return 0;
}