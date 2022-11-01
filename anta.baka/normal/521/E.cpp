#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cassert>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std; using ll = long long; using pii = pair<int, int>; using vi = vector<int>; using ld = long double;

const int N = (int)2e5 + 100;

int n, m;
vector<pii> g[N];
int dep[N];
int up[N];
int C;
int col[N];
vector<pii> ce[N];
vi cv[N];
vi G[N];
bool was[N];
vi path;
set<pii> cyc;
bool onc[N];
vi vcyc;

void dfs(int v, int p) {
	up[v] = dep[v];
	for (auto e : g[v]) {
		int to = e.first;
		if (to != p) {
			if (dep[to] == -1) {
				dep[to] = dep[v] + 1;
				dfs(to, v);
				up[v] = min(up[v], up[to]);
			}
			else {
				up[v] = min(up[v], dep[to]);
			}
		}
	}
}

void paint(int v, int p, int pcol) {
	for (auto e : g[v]) {
		int to = e.first;
		int eid = e.second;
		if (to != p) {
			if (dep[to] == -1) {
				dep[to] = dep[v] + 1;
				if (up[to] < dep[v]) {
					col[eid] = pcol;
				}
				else {
					col[eid] = C++;
				}
				paint(to, v, col[eid]);
				ce[col[eid]].pb({ v, to });
			}
			else if(dep[to] < dep[v]) {
				col[eid] = pcol;
				ce[col[eid]].pb({ v, to });
			}
			cv[col[eid]].pb(v);
			cv[col[eid]].pb(to);
		}
	}
}

void ins(int u, int v) {
	if (u > v) {
		swap(u, v);
	}
	cyc.insert({ u, v });
}

bool fnd(int u, int v) {
	if (u > v) {
		swap(u, v);
	}
	return cyc.count({ u, v });
}

void dfs1(int v, int p) {
	path.pb(v);
	was[v] = true;
	for (int to : G[v]) {
		if (to != p) {
			if (was[to]) {
				if (!cyc.empty()) {
					continue;
				}
				int i = sz(path) - 1;
				while (path[i] != to) {
					--i;
				}
				for (int j = i + 1; j < sz(path); j++) {
					ins(path[j - 1], path[j]);
				}
				ins(v, to);
				for (int j = i; j < sz(path); j++) {
					onc[path[j]] = true;
					vcyc.pb(path[j]);
				}
			}
			else {
				dfs1(to, v);
			}
		}
	}
	path.pop_back();
}

void dfs2(int v, int p, int st) {
	path.pb(v);
	was[v] = true;
	for (int to : G[v]) {
		if (to != p) {
			if (!fnd(v, to)) {
				if (!was[to]) {
					if (onc[to]) {
						int en = to;
						cout << "YES\n";
						cout << sz(path) + 1 << ' ';
						for (int u : path) {
							cout << u + 1 << ' ';
						}
						cout << en + 1 << '\n';
						int i1 = find(all(vcyc), st) - vcyc.begin();
						int i2 = find(all(vcyc), en) - vcyc.begin();
						assert(max(i1, i2) < sz(vcyc));
						if (i1 < i2) {
							cout << i2 - i1 + 1 << ' ';
							for (int i = i1; i <= i2; i++) {
								cout << vcyc[i] + 1 << ' ';
							}
							cout << endl;
							cout << (i1 + 1) + (sz(vcyc) - i2) << ' ';
							for (int i = i1; i >= 0; i--) {
								cout << vcyc[i] + 1 << ' ';
							}
							for (int i = sz(vcyc) - 1; i >= i2; i--) {
								cout << vcyc[i] + 1 << ' ';
							}
						}
						else {
							cout << i1 - i2 + 1 << ' ';
							for (int i = i1; i >= i2; i--) {
								cout << vcyc[i] + 1 << ' ';
							}
							cout << endl;
							cout << (i2 + 1) + (sz(vcyc) - i1) << ' ';
							for (int i = i1; i < sz(vcyc); i++) {
								cout << vcyc[i] + 1 << ' ';
							}
							for (int i = 0; i <= i2; i++) {
								cout << vcyc[i] + 1 << ' ';
							}
						}
						exit(0);
					}
					else {
						dfs2(to, v, st);
					}
				}
			}
		}
	}
	path.pop_back();
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb({ v, i }); g[v].pb({ u, i });
	}
	memset(dep, -1, sizeof(dep));
	for (int i = 0; i < n; i++) if (dep[i] == -1) dep[i] = 0, dfs(i, -1);
	memset(dep, -1, sizeof(dep));
	for (int i = 0; i < n; i++) if (dep[i] == -1) dep[i] = 0, paint(i, -1, 0);
	for (int z = 0; z < C; z++) {
		if (sz(ce[z]) == 1) continue;
		sort(all(cv[z]));
		cv[z].resize(unique(all(cv[z])) - cv[z].begin());
		if (sz(cv[z]) == sz(ce[z])) continue;
		for (auto e : ce[z]) G[e.first].pb(e.second), G[e.second].pb(e.first);
		dfs1(cv[z][0], -1);
		pii se{ -1, -1 };
		for (int u : cv[z]) if (onc[u]) for (int v : G[u]) if (!fnd(u, v)) se = { u, v };
		assert(se != pii(-1, -1));
		int rt = se.first;
		if (!onc[rt]) {
			rt = se.second;
		}
		for (int u : cv[z]) was[u] = false;
		dfs2(rt, -1, rt);
		assert(false);
		for (int u : cv[z]) G[u].clear(), onc[u] = false;
		cyc.clear();
	}
	cout << "NO";
}