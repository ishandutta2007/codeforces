#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 100015;
int n, m, _q, U[N], V[N], _W[N], dep[N], fa[N][21];
ll dis[2][21][N], Dep[N], W[21];
vector<array<int, 3>> e[N];
bool vis[N], istree[N];
void dfs(int u, int pa) {
	vis[u] = 1;
	fa[u][0] = pa;
	dep[u] = dep[pa] + 1;
	rep(j, 1, 19) fa[u][j] = fa[fa[u][j - 1]][j - 1];
	for(auto V : e[u]) {
		int v = V[0], w = V[1], id = V[2];
		if(vis[v]) continue;
		Dep[v] = Dep[u] + w;
		dfs(v, u);
		istree[id] = 1;
	}
}
int lca(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int dt = dep[u] - dep[v];
	rep(j, 0, 19) if(dt >> j & 1) u = fa[u][j];
	if(u == v) return u;
	per(j, 0, 19) {
		if(fa[u][j] != fa[v][j]) {
			u = fa[u][j];
			v = fa[v][j];
		}
	}
	return fa[u][0];
}
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
void dij(int s, ll d[]) {
	rep(i, 1, n) d[i] = infll;
	q.push(mp(0, s));
	d[s] = 0;
	while(SZ(q)) {
		int u = q.top().se; q.pop();
		for(auto V : e[u]) {
			int v = V[0], w = V[1];
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				q.push(mp(d[v], v));
			}
		}
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		U[i] = u; V[i] = v; _W[i] = w;
		e[u].pb({v, w, i});
		e[v].pb({u, w, i});
	}
	dfs(1, 0);
	int tot = 0;
	rep(i, 1, m) if(!istree[i]) {
		int u = U[i], v = V[i];
		W[tot] = _W[i];
		rep(_, 0, 1) {
			dij(u, dis[_][tot]);
			swap(u, v);
		}
		tot++;
	}
	scanf("%d", &_q);
	rep(__, 1, _q) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = Dep[u] + Dep[v] - 2 * Dep[lca(u, v)];
		rep(_, 0, tot - 1) {
			rep(p, 0, 1) ans = min(ans, dis[p][_][u] + dis[p ^ 1][_][v] + W[_]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}