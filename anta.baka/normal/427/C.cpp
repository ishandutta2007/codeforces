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
#include <map>
#include <functional>
#include <bitset>
#include <complex>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int inf = 1e9 + 228;
const int mod = 1e9 + 7;

int n;
vi c;
int m;
vector<vi> g, g1;
vi tps;
vector<bool> was;
int comp;
vi inc;
vector<pii> low;

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
	inc[v] = comp;
	for (int to : g1[v]) {
		if (inc[to] == -1) {
			dfs1(to);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	c.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	g.resize(n);
	g1.resize(n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g1[v].pb(u);
	}
	was.resize(n, false);
	for (int i = 0; i < n; i++) {
		if (!was[i]) {
			dfs(i);
		}
	}
	reverse(all(tps));
	inc.resize(n, -1);
	for (int u : tps) {
		if (inc[u] == -1) {
			dfs1(u);
			comp++;
		}
	}
	low.resize(n, { inf, inf });
	for (int i = 0; i < n; i++) {
		if (c[i] < low[inc[i]].first) {
			low[inc[i]] = { c[i], 1 };
		}
		else if (c[i] == low[inc[i]].first) {
			low[inc[i]].second++;
		}
	}
	ll ans = 0, mul = 1;
	for (int i = 0; i < comp; i++) {
		(ans += low[i].first);
		(mul *= low[i].second) %= mod;
	}
	cout << ans << ' ' << mul;
}