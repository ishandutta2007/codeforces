#include <iostream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const int N = 100001;
const int M = 1000001;
const int LG = 21;

struct DSU {
	vi p, s;
	DSU(int n) : p(n), s(n, 1) { iota(all(p), 0); }
	int get(int v) { return p[v] == v ? v : p[v] = get(p[v]); }
	void unite(int u, int v) {
		if ((u = get(u)) != (v = get(v))) {
			if (s[u] < s[v]) swap(u, v);
			s[u] += s[v]; p[v] = u;
		}
	}
};

struct edge {
	int u, v, w, id;
	bool operator < (const edge& him) const { return w < him.w; }
};

int n, m;
edge a[M];
vector<pii> g[N];
vi ids[N];
int tin[N], tout[N], tik_tak;
int up[LG][N], cup[LG][N];
int ans[M];

void dfs(int v, int p, int w) {
	tin[v] = tik_tak++;
	up[0][v] = p;
	cup[0][v] = w;
	for (int i = 1; i < LG; i++) {
		up[i][v] = up[i - 1][up[i - 1][v]];
		cup[i][v] = max(cup[i - 1][v], cup[i - 1][up[i - 1][v]]);
	}
	for (pii e : g[v]) {
		int to = e.first;
		if (to != p) dfs(to, v, e.second);
	}
	tout[v] = tik_tak++;
}

bool upper(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int get(int u, int v) {
	if (tin[u] > tin[v]) swap(u, v);
	int ans = 0;
	if (upper(u, v)) {
		for (int i = LG - 1; i >= 0; i--) {
			if (!upper(up[i][v], u)) {
				ans = max(ans, cup[i][v]);
				v = up[i][v];
			}
		}
		return max(ans, cup[0][v]);
	}
	else {
		for (int i = LG - 1; i >= 0; i--) {
			if (!upper(up[i][v], u)) {
				ans = max(ans, cup[i][v]);
				v = up[i][v];
			}
		}
		for (int i = LG - 1; i >= 0; i--) {
			if (!upper(up[i][u], v)) {
				ans = max(ans, cup[i][u]);
				u = up[i][u];
			}
		}
		return max({ ans, cup[0][v], cup[0][u] });
	}
}

int lca(int u, int v) {
	if (tin[u] > tin[v]) swap(u, v);
	if (upper(u, v)) return u;
	for (int i = LG - 1; i >= 0; i--) {
		if (!upper(up[i][v], u)) {
			v = up[i][v];
		}
	}
	return up[0][v];
}

vi in[N], out[N];
multiset<int> kek[N];
multiset<int>* lol[N];

void dfs1(int v, int p, int id) {
	bool ok = false;
	for (int i = 0; i < sz(g[v]); i++) {
		int to = g[v][i].first;
		if (to != p) {
			dfs1(to, v, ids[v][i]);
			if (!ok || sz(*lol[to]) > sz(*lol[v])) lol[v] = lol[to], ok = true;
		}
	}
	if (!ok) {
		lol[v] = &kek[v];
	}
	for (pii e : g[v]) {
		int to = e.first;
		if (to != p && lol[v] != lol[to]) {
			for (int x : *lol[to]) lol[v]->insert(x);
			multiset<int>().swap(*lol[to]);
		}
	}
	for (int x : in[v]) lol[v]->insert(x);
	for (int x : out[v]) lol[v]->erase(lol[v]->find(x));
	if (id != -1) {
		if (lol[v]->empty()) ans[id] = 1000000000;
		else ans[id] = *(*lol[v]).begin();
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		--u; --v;
		a[i] = { u, v, w, i };
	}
	sort(a, a + m);
	DSU dsu(n);
	for (int i = 0; i < m; i++) {
		edge& e = a[i];
		if (dsu.get(e.u) != dsu.get(e.v)) {
			g[e.u].pb({ e.v, e.w });
			g[e.v].pb({ e.u, e.w });
			ids[e.u].pb(e.id);
			ids[e.v].pb(e.id);
			dsu.unite(e.u, e.v);
			e.id = -1;
		}
	}
	dfs(0, 0, 0);
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < m; i++) if (a[i].id != -1) ans[a[i].id] = get(a[i].u, a[i].v);
	for (int i = 0; i < m; i++) if (a[i].id != -1) {
		int u = a[i].u, v = a[i].v, w = a[i].w;
		if (tin[u] > tin[v]) swap(u, v);
		if (upper(u, v)) {
			in[v].pb(w);
			out[u].pb(w);
		}
		else {
			int o = lca(u, v);
			in[u].pb(w);
			in[v].pb(w);
			out[o].pb(w);
			out[o].pb(w);
		}
	}
	dfs1(0, -1, -1);
	for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}