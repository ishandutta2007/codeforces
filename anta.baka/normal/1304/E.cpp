#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <fstream>
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
#define eb emplace_back
#define endl '\n'
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;

const int N = 1e5 + 228;
const int LG = 18;

int up[LG][N];

int n;
vector<vi> g;
vi dep;
vi in, out;
int timer;

void dfs(int v, int p) {
	in[v] = timer++;
	up[0][v] = p;
	for (int i = 1; i < LG; i++) {
		up[i][v] = up[i - 1][up[i - 1][v]];
	}
	for (int to : g[v]) {
		if (to != p) {
			dep[to] = dep[v] + 1;
			dfs(to, v);
		}
	}
	out[v] = timer;
}

bool upper(int u, int v) {
	return in[u] <= in[v] && out[v] <= out[u];
}

int lca(int u, int v) {
	if (in[u] > in[v]) {
		swap(u, v);
	}
	if (upper(u, v)) {
		return u;
	}
	for (int i = LG - 1; i >= 0; i--) {
		if (!upper(up[i][u], v)) {
			u = up[i][u];
		}
	}
	return up[0][u];
}

int dist(int u, int v) {
	int t = lca(u, v);
	return dep[u] + dep[v] - 2 * dep[t];
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	dep.resize(n, 0);
	in.resize(n);
	out.resize(n);
	dfs(0, 0);
	int q;
	cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		--x; --y; --a; --b;
		int dab = dist(a, b);
		int dxy = dist(a, x) + 1 + dist(y, b);
		int dyx = dist(a, y) + 1 + dist(x, b);
		bool ok = false;
		ok |= (dab <= k && (dab & 1) == (k & 1));
		ok |= (dxy <= k && (dxy & 1) == (k & 1));
		ok |= (dyx <= k && (dyx & 1) == (k & 1));
		cout << (ok ? "YES\n" : "NO\n");
	}
}