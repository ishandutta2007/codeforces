#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iomanip>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int N = 1.5e5 + 228;
const int LG = 18;

struct Fen {
	int n;
	vi t;
	Fen() : n(0), t() {}
	void resize(int n) {
		this->n = n;
		t.assign(n, 0);
	}
	void upd(int v, int x) {
		for (int i = v; i < n; i |= i + 1) {
			t[i] += x;
		}
	}
	int get(int v) {
		int ret = 0;
		for (int i = v; i >= 0; i = (i & (i + 1)) - 1) {
			ret += t[i];
		}
		return ret;
	}
	int get(int l, int r) {
		if (l > r) {
			return 0;
		}
		return get(r) - get(l - 1);
	}
};

int n, m, k;
vi g[N];
bool ban[N];
int sz[N];
ll ans;
int cp[N];
vector<pii> ps[N];
int in[N], out[N], timer;
int up[LG][N];
int psum[N];
vi vsbt;
vector<pii> sbt;
int dep[N];
vector<pii> es[N];
ll cadd;
set<int> setik[N];
set<int>* psetik[N];
vi tms[N];
vi* ptms[N];
Fen t[N];
Fen* pt[N];
vi sps[N];
vi* psps[N];

void calc_sz(int v, int p) {
	sz[v] = 1;
	for (int to : g[v]) {
		if (!ban[to] && to != p) {
			calc_sz(to, v);
			sz[v] += sz[to];
		}
	}
}

int getc(int v, int p, int n) {
	for (int to : g[v]) {
		if (!ban[to] && to != p && 2 * sz[to] >= n) {
			return getc(to, v, n);
		}
	}
	return v;
}

void cdec(int v, int p) {
	calc_sz(v, -1);
	v = getc(v, -1, sz[v]);
	ban[v] = true;
	cp[v] = p;
	for (int to : g[v]) {
		if (!ban[to]) {
			cdec(to, v);
		}
	}
}

void cfill(int v, bool val) {
	while (v != -1) {
		ban[v] = val;
		v = cp[v];
	}
}

int clca(int u, int v) {
	cfill(u, true);
	while (!ban[v]) {
		v = cp[v];
	}
	cfill(u, false);
	return v;
}

void dfs_time(int v, int p) {
	up[0][v] = p;
	for (int i = 1; i < LG; i++) {
		up[i][v] = up[i - 1][up[i - 1][v]];
	}
	in[v] = timer++;
	for (int to : g[v]) {
		if (to != p && !ban[to]) {
			dfs_time(to, v);
		}
	}
	out[v] = timer;
}

bool rupper(int u, int v) {
	return (in[u] <= in[v] && out[v] <= out[u]);
}

int rlca(int u, int v) {
	if (in[u] > in[v]) {
		swap(u, v);
	}
	if (rupper(u, v)) {
		return u;
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (!rupper(up[i][u], v)) {
			u = up[i][u];
		}
	}
	return up[0][u];
}

int kanc(int v, int k) {
	for (int i = LG - 1; i >= 0; i--) {
		if (k >= (1 << i)) {
			k -= (1 << i);
			v = up[i][v];
		}
	}
	return v;
}

void collect_subtree(int v, int p) {
	vsbt.pb(v);
	setik[v].clear();
	if (p != -1) {
		for (auto p : ps[v]) {
			sbt.pb(p);
		}
	}
	for (int to : g[v]) {
		if (to != p && !ban[to]) {
			dep[to] = dep[v] + 1;
			collect_subtree(to, v);
		}
	}
}

void updvert(int u, int v) {
	if (dep[v] - dep[u] < k) {
		return;
	}
	int w = kanc(v, (dep[v] - dep[u]) - k);
	ans += (psum[out[w] - 1] - (in[w] ? psum[in[w] - 1] : 0));
}

void prepare(int v, int p) {
	int kid = -1;
	for (int to : g[v]) {
		if (to != p && !ban[to]) {
			prepare(to, v);
			if (kid == -1 || psetik[kid]->size() < psetik[to]->size()) {
				kid = to;
			}
		}
	}
	if (kid == -1) {
		psetik[v] = &setik[v];
	}
	else {
		psetik[v] = psetik[kid];
	}
	for (int to : g[v]) {
		if (to != p && !ban[to] && to != kid) {
			for (int tm : *psetik[to]) {
				psetik[v]->insert(tm);
			}
		}
	}
	for (auto p : es[v]) {
		psetik[v]->insert(in[p.first ^ p.second ^ v]);
	}
}

void solve(int v, int p, int c) {
	int kid = -1;
	for (int to : g[v]) {
		if (to != p && !ban[to]) {
			solve(to, v, c);
			if (kid == -1 || psetik[kid]->size() < psetik[to]->size()) {
				kid = to;
			}
		}
	}
	if (kid == -1) {
		psetik[v] = &setik[v];
		psps[v] = &sps[v];
		ptms[v] = &tms[v];
		pt[v] = &t[v];
	}
	else {
		psetik[v] = psetik[kid];
		psps[v] = psps[kid];
		ptms[v] = ptms[kid];
		pt[v] = pt[kid];
	}
	for (int to : g[v]) {
		if (to != p && !ban[to] && to != kid) {
			for (int ov : *psps[to]) {
				int w = c;
				if (dep[v] < k) {
					int rem = k - dep[v];
					if (dep[ov] < rem) {
						w = -1;
					}
					else {
						w = kanc(ov, dep[ov] - rem);
					}
				}
				if (w != -1) {
					int lf = lower_bound(all(*ptms[v]), in[w]) - ptms[v]->begin();
					int rg = lower_bound(all(*ptms[v]), out[w]) - ptms[v]->begin() - 1;
					cadd += pt[v]->get(lf, rg);
				}
			}
			for (int ov : *psps[to]) {
				psps[v]->pb(ov);
				pt[v]->upd(lower_bound(all(*ptms[v]), in[ov]) - ptms[v]->begin(), 1);
			}
			for (int tm : *psetik[to]) {
				psetik[v]->insert(tm);
			}
		}
	}
	ll curadd = 0;
	for (auto p : es[v]) {
		int ov = p.first ^ p.second ^ v;
		int w = c;
		if (dep[v] < k) {
			int rem = k - dep[v];
			if (dep[ov] < rem) {
				w = -1;
			}
			else {
				w = kanc(ov, dep[ov] - rem);
			}
		}
		if (w != -1) {
			int lf = lower_bound(all(*ptms[v]), in[w]) - ptms[v]->begin();
			int rg = lower_bound(all(*ptms[v]), out[w]) - ptms[v]->begin() - 1;
			curadd += pt[v]->get(lf, rg);
		}
		psps[v]->pb(ov);
		pt[v]->upd(lower_bound(all(*ptms[v]), in[ov]) - ptms[v]->begin(), 1);
		psetik[v]->insert(in[ov]);
	}
	cadd += curadd;
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	cdec(0, -1);
	memset(ban, false, sizeof(ban));
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; ps[clca(u, v)].pb(mp(u, v));
	}
	for (int c = 0; c < n; c++) {
		cfill(c, true);
		timer = 0;
		dfs_time(c, c);
		// First part
		memset(psum, 0, 4 * timer);
		for (auto p : ps[c]) {
			psum[in[p.first]]++;
			psum[in[p.second]]++;
		}
		for (int i = 1; i < timer; i++) {
			psum[i] += psum[i - 1];
		}
		vsbt.clear();
		sbt.clear();
		dep[c] = 0;
		collect_subtree(c, -1);
		for (auto p : sbt) {
			int u = p.first, v = p.second;
			int mid = rlca(u, v);
			if (u != mid) {
				updvert(mid, u);
			}
			if (v != mid) {
				updvert(mid, v);
			}
		}
		// Second part
		for (auto p : ps[c]) {
			es[p.first].pb(p);
			es[p.second].pb(p);
		}
		prepare(c, -1);
		for (int v : vsbt) {
			sps[v].clear();
			tms[v] = vi(all(setik[v]));
			setik[v].clear();
			t[v].resize(sz(tms[v]));
		}
		cadd = 0;
		solve(c, -1, c);
		ans += cadd / 2;
		for (auto p : ps[c]) {
			es[p.first].clear();
			es[p.second].clear();
		}
		cfill(c, false);
	}
	cout << ans;
}