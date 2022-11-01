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

int n;
vector<vi> g;
vi cl;
int lo, hi;
bool par[2];

void dfs(int v, int p, int dep) {
	bool any = false;
	for (int to : g[v]) {
		if (to == p) continue;
		dfs(to, v, dep + 1);
		any = true;
	}
	if (!any) {
		par[dep & 1] = true;
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v; g[u].pb(v); g[v].pb(u);
	}
	cl.resize(n);
	int rt = -1;
	for (int i = 0; i < n; i++) {
		if (sz(g[i]) == 1) {
			cl[g[i][0]]++;
		}
		else {
			if (rt == -1) {
				rt = i;
			}
		}
	}
	hi = n - 1;
	for (int i = 0; i < n; i++) {
		hi -= max(0, cl[i] - 1);
	}
	dfs(rt, -1, 0);
	cout << (par[0] && par[1] ? 3 : 1) << ' ';
	cout << hi;
}