#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <iomanip>
#include <numeric>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <random>
#include <queue>
#include <cstring>

#define sz(a) (int)((a).size())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using ld = long double;
using pll = pair<ll, ll>;

const int N = 2.6e6 + 228;

int n, p, M, m;
vi g[N];
vi g1[N];
vi tps;
bool was[N];
int inc[N];
int cc;

void addOr(int x, int y, int tot) {
	int nx = (x < tot ? x + tot : x - tot);
	int ny = (y < tot ? y + tot : y - tot);
	g[nx].pb(y);
	g[ny].pb(x);
	g1[y].pb(nx);
	g1[x].pb(ny);
}

void dfs0(int v) {
	was[v] = true;
	for (int to : g[v]) {
		if (!was[to]) {
			dfs0(to);
		}
	}
	tps.pb(v);
}

void dfs1(int v) {
	inc[v] = cc;
	for (int to : g1[v]) {
		if (!inc[to]) {
			dfs1(to);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> p >> M >> m;
	int tot = M + p;
	addOr(0, 0, tot);
	for (int i = 0; i < M - 1; i++) {
		addOr(i, i + 1 + tot, tot);
	}
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		u += M;
		v += M;
		addOr(u, v, tot);
	}
	for (int i = 0; i < p; i++) {
		int l, r;
		cin >> l >> r;
		--l; --r;
		addOr(l, M + i + tot, tot);
		if (r < M - 1) {
			addOr(r + 1 + tot, M + i + tot, tot);
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		u += M;
		v += M;
		addOr(u + tot, v + tot, tot);
	}
	tps.reserve(2 * tot);
	for (int u = 0; u < 2 * tot; u++) {
		if (!was[u]) {
			dfs0(u);
		}
	}
	reverse(all(tps));
	cc++;
	for (auto v : tps) {
		if (inc[v]) continue;
		dfs1(v);
		cc++;
	}
	for (int u = 0; u < tot; u++) {
		if (inc[u] == inc[u + tot]) {
			return cout << -1, 0;
		}
	}
	vi sts;
	int f = 0;
	for (int i = 0; i < M; i++) {
		f += (inc[i] > inc[i + tot]);
	}
	for (int i = 0; i < p; i++) {
		if (inc[M + i] > inc[M + i + tot]) {
			sts.pb(i);
		}
	}
	cout << sz(sts) << ' ' << f << '\n';
	for (auto s : sts) {
		cout << s + 1 << ' ';
	}
}