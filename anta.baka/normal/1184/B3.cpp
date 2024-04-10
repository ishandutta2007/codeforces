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

#define int ll
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

const ll inf = (ll)1e18 + 100;

int n, m;
int d[100][100];
int s, b, k;

struct ship {
	int x, a, f, p;
} ss[100000];

struct base {
	int x, d, g;
} bb[100000];

struct maxflow {
	struct edge {
		int to, c, f;
	};

	vector<edge> e;
	vector<vi> g;
	int N, S, T;
	vi pt, d;
	int A;

	bool bfs() {
		fill_n(d.begin(), N, inf);
		d[S] = 0;
		queue<int> q;
		q.push(S);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i : g[v]) {
				edge& ee = e[i];
				if (ee.c - ee.f >= A && d[ee.to] == inf) {
					d[ee.to] = d[v] + 1;
					q.push(ee.to);
				}
			}

		}
		return (d[T] != inf);
	}

	int dfs(int v, int cmin) {
		if (v == T) {
			return cmin;
		}
		for (; pt[v] < sz(g[v]); pt[v]++) {
			int i = g[v][pt[v]];
			edge& ee = e[i];
			if (ee.c - ee.f >= A && d[ee.to] == d[v] + 1) {
				int f = dfs(ee.to, min(cmin, ee.c - ee.f));
				if (f > 0) {
					ee.f += f;
					e[i ^ 1].f -= f;
					return f;
				}
			}
		}
		return 0;
	}

	void dinic() {
		d.resize(N);
		pt.resize(N);
		int mf = 0;
		for (A = inf; A; A >>= 1) {
			while (bfs()) {
				fill_n(pt.begin(), N, 0);
				while (dfs(S, inf));
			}
		}
	}

	void addEdge(int u, int v, int c) {
		static int i = 0;
		e.pb({ v, c, 0 });
		e.pb({ u, 0, 0 });
		g[u].pb(i);
		g[v].pb(i ^ 1);
		i += 2;
		//cout << u << ' ' << v << endl;
	}

	void zhfs(int v, vector<bool>& was) {
		was[v] = true;
		for (int i : g[v]) {
			edge& ee = e[i];
			if (ee.c - ee.f > 0 && !was[ee.to]) {
				zhfs(ee.to, was);
			}
		}
	}
};

vi g1[100000];
vector<pii> e;
bool ban[100000];
int w[100000];

void dfs(int v) {
	ban[v] = true;
	for (int to : g1[v]) if(!ban[to]) dfs(to);
}

vector<pii> pl[100];
vi pm[100];

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if(i != j) d[i][j] = inf;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; d[u][v] = d[v][u] = 1;
	}
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	cin >> s >> b >> k;
	for (int i = 0; i < s; i++) cin >> ss[i].x >> ss[i].a >> ss[i].f >> ss[i].p, --ss[i].x;
	for (int i = 0; i < b; i++) cin >> bb[i].x >> bb[i].d >> bb[i].g, --bb[i].x, pl[bb[i].x].pb({ bb[i].d, bb[i].g });
	for (int i = 0; i < n; i++) {
		if (pl[i].empty()) continue;
		sort(all(pl[i]));
		pm[i].resize(sz(pl[i]));
		pm[i][0] = pl[i][0].second;
		for (int j = 1; j < sz(pm[i]); j++) {
			pm[i][j] = max(pm[i][j - 1], pl[i][j].second);
		}
	}
	vi broken;
	maxflow grape;
	grape.N = s + 2;
	grape.S = grape.N - 2;
	grape.T = grape.N - 1;
	grape.g.resize(grape.N);
	vi ord(s); iota(all(ord), 0);
	sort(all(ord), [](int i, int j) { return ss[i].a < ss[j].a; });
	vi pt(n, -1);
	for (int i : ord) {
		int hi = -1;
		//for (int p = 0; p < n; p++) if (ss[i].f >= d[ss[i].x][p]) for (pii bas : pl[p]) if (ss[i].a >= bas.first) hi = max(hi, bas.second);
		// me for (int p = 0; p < n; p++) if (ss[i].f >= d[ss[i].x][p]) for (int t = 0; t < sz(pl[p]) && ss[i].a >= pl[p][t].first; t++) hi = max(hi, pm[p][t]);
 		//for (int j = 0; j < b; j++) if (ss[i].a >= bb[j].d && ss[i].f >= d[ss[i].x][bb[j].x]) hi = max(hi, bb[j].g);
		for (int p = 0; p < n; p++) if(ss[i].f >= d[ss[i].x][p]) {
			while (pt[p] + 1 < sz(pl[p]) && ss[i].a >= pl[p][pt[p] + 1].first) pt[p]++;
			if (pt[p] != -1) hi = max(hi, pm[p][pt[p]]);
		}
		if (hi == -1) broken.pb(i);
		else {
			hi -= ss[i].p;
			w[i] = hi;
			//cout << i << ' ' << w[i] << endl;
		}
	}
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g1[v].pb(u); e.pb({ u, v });
	}
	for (int u : broken) if (!ban[u]) dfs(u);
	for (int i = 0; i < s; i++) if (!ban[i]) {
		//cout << '!' << i << endl;
		int hi = w[i];
		if (hi < 0) grape.addEdge(i, grape.T, -hi);
		else if (hi > 0) grape.addEdge(grape.S, i, hi);
	}
	for (pii r : e) {
		int u = r.first, v = r.second;
		if (!ban[u] && !ban[v]) grape.addEdge(u, v, inf);
	}
	grape.dinic();
	vector<bool> was(grape.N, false);
	grape.zhfs(grape.S, was);
	ll ans = 0;
	for (int u = 0; u < s; u++) {
		if (was[u]) {
			ans += w[u];
		}
	}
	cout << ans;
}