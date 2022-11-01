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

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 4000001;
const int delta = 2000000;

struct node {
	int ad, mx;
};

node merge(node a, node b) {
	node r;
	r.ad = 0;
	r.mx = max(a.mx, b.mx);
	return r;
}

node rmq[4 * MAXN];

void create_rmq(int v, int lf, int rg) {
	if (lf == rg) {
		rmq[v].mx = rmq[v].ad = 0;
		return;
	}
	int md = (lf + rg) >> 1;
	create_rmq(v * 2 + 1, lf, md);
	create_rmq(v * 2 + 2, md + 1, rg);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void push_rmq(int v) {
	rmq[v * 2 + 1].mx += rmq[v].ad;
	rmq[v * 2 + 1].ad += rmq[v].ad;
	rmq[v * 2 + 2].mx += rmq[v].ad;
	rmq[v * 2 + 2].ad += rmq[v].ad;
	rmq[v].ad = 0;
}

void modify_rmq(int v, int lf, int rg, int l, int r, int val) {
	if (r < lf || rg < l) {
		return;
	}
	if (l <= lf && rg <= r) {
		rmq[v].mx += val;
		rmq[v].ad += val;
		return;
	}
	push_rmq(v);
	int md = (lf + rg) >> 1;
	modify_rmq(v * 2 + 1, lf, md, l, r, val);
	modify_rmq(v * 2 + 2, md + 1, rg, l, r, val);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

struct event {
	int x, idx;
	bool in;
	event(int _x, int _idx, bool _in) : x(_x), idx(_idx), in(_in) {}
	bool operator < (const event &a) const {
		return x < a.x || x == a.x && in > a.in;
	}
};

int main()
{
	//ifstream cin("in.txt");
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, r;
	cin >> n >> r;

	vector<pair<int, int>> Cord(n);
	r *= 2;
	int s = r, w = r;
	vector<event> ev;
	vector<int> y0(n), y1(n);

	for (int i = 0; i < n; i++)
	{
		cin >> Cord[i].first >> Cord[i].second;

		int cop1 = Cord[i].first + Cord[i].second;
		int cop2 = Cord[i].second - Cord[i].first;

		Cord[i].first = cop1 + delta;
		Cord[i].second = cop2 + delta;

		int x = Cord[i].first;
		int y = Cord[i].second;

		//cout << x-delta << ' ' << y-delta << endl;

		ev.push_back(event(x, i, true));
		ev.push_back(event(x + s, i, false));
		y0[i] = y - delta;
		y1[i] = y + w - delta;
	}
	sort(ev.begin(), ev.end());
	int ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (ev[i].in) {
			//cout << "BAIR ";
			modify_rmq(0, 0, MAXN - 1, y0[ev[i].idx] + delta, y1[ev[i].idx] + delta, 1);
		}
		else {
			//cout << "NE LOH";
			modify_rmq(0, 0, MAXN - 1, y0[ev[i].idx] + delta, y1[ev[i].idx] + delta, -1);
		}
		ans = max(ans, rmq[0].mx);
	}
	cout << ans;
}


/*
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

const int inf = (int)1e9 + 100;

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
		for (int p = 0; p < n; p++) {
			while (pt[p] + 1 < sz(pl[p]) && ss[i].a >= pl[p][pt[p] + 1].first) pt[p]++;
			if (pt[p] != -1) hi = max(hi, pm[p][pt[p]]);
		}
		if (hi == -1) broken.pb(i);
		else {
			hi -= ss[i].p;
			if (hi < 0) grape.addEdge(i, grape.T, -hi);
			else if (hi > 0) grape.addEdge(grape.S, i, hi);
			w[i] = hi;
		}
	}
	for (int i = 0; i < k; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g1[v].pb(u); e.pb({ u, v });
	}
	for (int u : broken) if (!ban[u]) dfs(u);
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
*/