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

const int N = 1e5 + 228;
const int LG = 30;

int n, m;
vector<pii> g[N];
bool was[N];
int xr[N];
int basis[LG];

void dfs(int v) {
	was[v] = true;
	for (auto e : g[v]) {
		if (!was[e.first]) {
			xr[e.first] = xr[v] ^ e.second;
			dfs(e.first);
		}
		else {
			int x = xr[v] ^ xr[e.first] ^ e.second;
			for (int i = LG - 1; i >= 0; i--) {
				if (!(x >> i & 1)) continue;
				if (!basis[i]) {
					basis[i] = x;
					break;
				}
				x ^= basis[i];
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	dfs(0);
	int base = xr[n - 1];
	for (int i = LG - 1; i >= 0; i--) {
		if (!basis[i]) continue;
		if (!(base >> i & 1)) continue;
		base ^= basis[i];
	}
	cout << base;
}