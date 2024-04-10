#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int N = 200015;
vector<pii> e[N];
ll dis[N];
bool vis[N];

void dij(int s) {
	memset(dis, 0x3f, sizeof dis);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
	dis[s] = 0;
	q.emplace(0, s);

	while (!q.empty()) {
		auto [d, u] = q.top();
		q.pop();

		if (vis[u]) continue;

		vis[u] = 1;
		d = dis[u];

		for (auto [v, w] : e[u]) {
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.emplace(dis[v], v);
			}
		}
	}
}

vector<int> g[N], rg[N], t[N];
int fa[N][18], dep[N], deg[N];

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);

	int t = dep[v] - dep[u];

	rep(i, 0, 17) if (t >> i & 1) v = fa[v][i];

	if (u == v) return u;

	per(i, 0, 17) {
		if (fa[u][i] ^ fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}

	return fa[u][0];
}

void topo(int s) {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int u = q.front();
		vis[u] = 1;
		q.pop();

		if (u != s) {
			int f = -1;

			for (int v : rg[u]) {
				if (f == -1) f = v;
				else f = lca(f, v);
			}

			dep[u] = dep[f] + 1;
			fa[u][0] = f;
			rep(j, 1, 17) fa[u][j] = fa[fa[u][j - 1]][j - 1];
			t[f].pb(u);
		}

		for (int v : g[u]) {
			if (--deg[v] == 0) {
				q.push(v);
			}
		}
	}
}

int ans;

int Dfs(int u, int pa) {
	int sz = 1;

	for (int v : t[u]) {
		if (v == pa) continue;

		int nsz = Dfs(v, u);
		sz += nsz;
		ans = max(ans, nsz);
	}

	return sz;
}

int n, m, s;

int main() {
#ifdef Asuka
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &m, &s);
	vector<tuple<int, int, int>> eds;

	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		eds.eb(u, v, w);
		eds.eb(v, u, w);
		e[u].eb(v, w);
		e[v].eb(u, w);
	}

	dij(s);
	memset(vis, 0, sizeof vis);

	for (auto [u, v, w] : eds) {
		if (dis[v] == dis[u] + w) {
			g[u].pb(v);
			rg[v].pb(u);
			deg[v]++;
		}
	}

	topo(s);
	Dfs(s, 0);
	printf("%d\n", ans);
	return 0;
}