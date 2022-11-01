#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cassert>
#include <set>
#include <cstring>
#include <map>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
using vi = vector<int>;

int n;
vector<vi> a;
vector<vi> b;
vi c;
vector<vi> g;
vector<vi> g1;
vector<bool> was;
vi tps;
vi comp;
int cur_comp;

void dfs(int v) {
	was[v] = true;
	for (int to : g[v]) {
		if (!was[to]) {
			dfs(to);
		}
	}
	tps.pb(v);
}

void dfs1(int v) {
	comp[v] = cur_comp;
	for (int to : g1[v]) {
		if (comp[to] == -1) {
			dfs1(to);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			a[i][j] = ch - '0';
		}
	}
	b.resize(n, vi(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char ch;
			cin >> ch;
			b[i][j] = ch - '0';
		}
	}
	c.resize(n);
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		c[i] = ch - '0';
	}
	g.resize(4 * n);
	g1.resize(4 * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int xi = 0; xi < 2; xi++) {
				for (int xj = 0; xj < 2; xj++) {
					int xr = a[i][j];
					if (xi) {
						xr ^= c[j];
					}
					if (xj) {
						xr ^= c[i];
					}
					if (xr != b[i][j]) {
						if (xi == 1 && xj == 1) {
							g[i].pb(j + 3 * n);
							g[j + n].pb(i + 2 * n);
							g1[j + 3 * n].pb(i);
							g1[i + 2 * n].pb(j + n);
						}
						else if (xi == 1 && xj == 0) {
							g[i].pb(j + n);
							g[j + 3 * n].pb(i + 2 * n);
							g1[j + n].pb(i);
							g1[i + 2 * n].pb(j + 3 * n);
						}
						else if (xi == 0 && xj == 1) {
							g[i + 2 * n].pb(j + 3 * n);
							g[j + n].pb(i);
							g1[j + 3 * n].pb(i + 2 * n);
							g1[i].pb(j + n);
						}
						else {
							g[i + 2 * n].pb(j + n);
							g[j + 3 * n].pb(i);
							g1[j + n].pb(i + 2 * n);
							g1[i].pb(j + 3 * n);
						}
					}
				}
			}
		}
	}
	was.resize(sz(g), false);
	for (int i = 0; i < sz(g); i++) {
		if (!was[i]) {
			dfs(i);
		}
	}
	reverse(all(tps));
	comp.resize(sz(g), -1);
	for (int u : tps) {
		if (comp[u] == -1) {
			dfs1(u);
			cur_comp++;
		}
	}
	for (int i = 0; i < 2 * n; i++) {
		if (comp[i] == comp[i + 2 * n]) {
			return cout << -1, 0;
		}
	}
	vi rows;
	for (int i = 0; i < n; i++) {
		if (comp[i] > comp[i + 2 * n]) {
			rows.pb(i);
		}
	}
	vi cols;
	for (int i = n; i < 2 * n; i++) {
		if (comp[i] > comp[i + 2 * n]) {
			cols.pb(i);
		}
	}
	cout << sz(rows) + sz(cols) << endl;
	for (int i : rows) {
		cout << "row " << i << '\n';
	}
	for (int j : cols) {
		cout << "col " << j - n << '\n';
	}
}