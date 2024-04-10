#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vi col;
bool ok;
vi col0;
vi col1;

void dfs(int v, const vector<vector<pii>>& g) {
	if (col[v] == 0) {
		col0.pb(v);
	}
	else {
		col1.pb(v);
	}
	for (auto e : g[v]) {
		int to = e.first;
		if (col[to] == -1) {
			col[to] = col[v] ^ e.second;
			dfs(to, g);
		}
		else if(col[to] != (col[v] ^ e.second)) {
			ok = false;
		}
	}
}

#define end KUKAREX

void end(const vi& ans) {
	cout << sz(ans) << endl;
	for (auto v : ans) cout << v + 1 << ' ';
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> g(n), gg(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		--u; --v;
		if (c == 'B') {
			g[u].pb(mp(v, 0));
			g[v].pb(mp(u, 0));
			gg[u].pb(mp(v, 1));
			gg[v].pb(mp(u, 1));
		}
		else {
			gg[u].pb(mp(v, 0));
			gg[v].pb(mp(u, 0));
			g[u].pb(mp(v, 1));
			g[v].pb(mp(u, 1));
		}
	}
	vi ans0;
	col.resize(n, -1);
	ok = true;
	for (int u = 0; u < n; u++) {
		if (col[u] == -1) {
			col0.clear();
			col1.clear();
			col[u] = 0;
			dfs(u, g);
			if (sz(col0) < sz(col1)) {
				for (auto v : col0) {
					ans0.pb(v);
				}
			}
			else {
				for (auto v : col1) {
					ans0.pb(v);
				}
			}
		}
	}
	bool ok1 = ok;
	vi ans1;
	col.assign(n, -1);
	ok = true;
	for (int u = 0; u < n; u++) {
		if (col[u] == -1) {
			col0.clear();
			col1.clear();
			col[u] = 0;
			dfs(u, gg);
			if (sz(col0) < sz(col1)) {
				for (auto v : col0) {
					ans1.pb(v);
				}
			}
			else {
				for (auto v : col1) {
					ans1.pb(v);
				}
			}
		}
	}
	bool ok2 = ok;
	if (ok1 && ok2) {
		end(sz(ans0) < sz(ans1) ? ans0 : ans1);
	}
	else if (ok1) {
		end(ans0);
	}
	else if (ok2) {
		end(ans1);
	}
	else {
		cout << -1;
	}
}