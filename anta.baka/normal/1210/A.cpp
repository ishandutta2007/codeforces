#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize("O3")

#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <assert.h>
#include <set>
#include <cstdio>
#include <cstring>
#include <queue>
#include <random>
#include <map>
#include <array>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std; using ll = long long; using vi = vector<int>; using pii = pair<int, int>; using ld = long double;

int n, m;
vi g[7];
int val[7];
int ans = 0;
bool was[7][7];

void gen(int v) {
	if (v == n) {
		int cnt = 0;
		memset(was, false, sizeof(was));
		for(int u = 0; u < n; u++)
			for (int v : g[u]) {
				int x = val[u], y = val[v];
				if (x > y) swap(x, y);
				if (!was[x][y]) {
					cnt++;
					was[x][y] = true;
				}
			}
		ans = max(ans, cnt);
	}
	else {
		for (val[v] = 1; val[v] < 7; val[v]++) {
			gen(v + 1);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	gen(0);
	cout << ans;
}