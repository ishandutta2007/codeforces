#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cstring>
#include <numeric>
#include <set>
#include <queue>
#include <deque>
#include <array>
#include <string>
#include <cmath>
#include <random>
#include <ctime>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = double;

const ld inf = 1e18;
const int NAZI = 2e5 + 228;

struct Edge {
	int from, to, a, b, id;
};

struct Line {
	ll k, b;
	bool operator < (const Line& o) const {
		return (k < o.k || k == o.k && b > o.b);
	}
	ll eval(int x) {
		return k * x + b;
	}
	Line operator + (const Line& o) const {
		return { k + o.k, b + o.b };
	}
};

int n, m;
int SZ;
vector<Edge> gkek[NAZI], g[NAZI];
int sizes[NAZI];
bool ban[NAZI];
int ID;
vector<Line> setik[2];
ll sumA[NAZI];
ll sumB[NAZI];
vector<Line> h1, h2;
ll ans[1000228];
vector<Line> cand, h;

void addEdge(int u, int v, int a, int b) {
	g[u].pb({ u, v, a, b, ID });
	g[v].pb({ v, u, a, b, ID++ });
}

void dfs(int v, int p) {
	if (p != -1) {
		int pos = 0;
		while (gkek[v][pos].to != p) {
			pos++;
		}
		gkek[v].erase(gkek[v].begin() + pos);
	}
	int last_node = v;
	for (int i = 0; i < sz(gkek[v]); i++) {
		addEdge(last_node, gkek[v][i].to, gkek[v][i].a, gkek[v][i].b);
		dfs(gkek[v][i].to, v);
		if (i < sz(gkek[v]) - 1) {
			addEdge(last_node, SZ, 0, 0);
			last_node = SZ++;
		}
	}
}

void calcSizes(int v, int p) {
	sizes[v] = 1;
	for (auto& e : g[v]) {
		if (!ban[e.id] && e.to != p) {
			calcSizes(e.to, v);
			sizes[v] += sizes[e.to];
		}
	}
}

void getCent(int v, int p, int n, Edge& pred) {
	for (auto& e : g[v]) {
		if (!ban[e.id] && e.to != p && 2 * sizes[e.to] >= n) {
			return getCent(e.to, v, n, pred = e);
		}
	}
	if (p == -1) {
		pred = g[v][0];
	}
	return;
}

void dfsKek(int v, int p, int id) {
	setik[id].pb({ sumA[v], sumB[v] });
	for (auto& e : g[v]) {
		if (!ban[e.id] && e.to != p) {
			sumA[e.to] = sumA[v] + e.a;
			sumB[e.to] = sumB[v] + e.b;
			dfsKek(e.to, v, id);
		}
	}
}

ld isec(Line& a, Line& b) {
	return ((ld)a.b - b.b) / (b.k - a.k);
}

void add(Line l, vector<Line>& h) {
	if (!h.empty() && h.back().k == l.k) {
		return;
	}
	while (sz(h) > 1 && isec(h[sz(h) - 2], h.back()) > isec(h.back(), l)) {
		h.pop_back();
	}
	h.pb(l);
}

void centDec(int v) {
	calcSizes(v, -1);
	if (sizes[v] == 1) {
		return;
	}
	Edge mid;
	getCent(v, -1, sizes[v], mid);
	ban[mid.id] = true;
	sumA[mid.from] = 0;
	sumB[mid.from] = 0;
	sumA[mid.to] = mid.a;
	sumB[mid.to] = mid.b;
	setik[0].clear();
	setik[1].clear();
	dfsKek(mid.from, -1, 0);
	dfsKek(mid.to, -1, 1);
	sort(all(setik[0]));
	sort(all(setik[1]));
	h1.clear();
	h2.clear();
	for (auto& l : setik[0]) {
		add(l, h1);
	}
	for (auto& l : setik[1]) {
		add(l, h2);
	}
	ld last1 = -inf, last2 = -inf;
	if (sz(h1) > 1) {
		last1 = isec(h1[sz(h1) - 2], h1.back());
	}
	if (sz(h2) > 1) {
		last2 = isec(h2[sz(h2) - 2], h2.back());
	}
	cand.pb(h1[0] + h2[0]);
	while (last1 > -inf || last2 > -inf) {
		cand.pb(h1.back() + h2.back());
		if (last1 > last2) {
			h1.pop_back();
			last1 = -inf;
			if (sz(h1) > 1) {
				last1 = isec(h1[sz(h1) - 2], h1.back());
			}
		}
		else {
			h2.pop_back();
			last2 = -inf;
			if (sz(h2) > 1) {
				last2 = isec(h2[sz(h2) - 2], h2.back());
			}
		}
	}
	for (auto& e : g[mid.from]) {
		if (!ban[e.id]) {
			centDec(e.to);
		}
	}
	for (auto& e : g[mid.to]) {
		if (!ban[e.id]) {
			centDec(e.to);
		}
	}
}


void shift(int x, vector<Line>& h) {
	while (sz(h) > 1 && x < isec(h[sz(h) - 2], h.back())) {
		h.pop_back();
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	if (n == 1) {
		for (int i = 0; i < m; i++) {
			cout << 0 << ' ';
		}
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v, a, b; cin >> u >> v >> a >> b; --u; --v; gkek[u].pb({ u, v, a, b }); gkek[v].pb({ v, u, a, b });
	}
	SZ = n;
	dfs(0, -1);
	n = SZ;
	centDec(0);
	sort(all(cand));
	for (auto l : cand) {
		add(l, h);
	}
	for (int x = m - 1; x >= 0; x--) {
		shift(x, h);
		ans[x] = h.back().eval(x);
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << ' ';
	}
}