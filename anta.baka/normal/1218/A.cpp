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
vector<vi> g;
vector<bool> was;
vi cur_path;
vi cycle;
vector<bool> on_cycle;
vi SZ;
vi dp;
vi dp2;
vi pref_sz;
int opt[15000];
int opt1[15000];

void dfs(int v, int p) {
	was[v] = true;
	cur_path.pb(v);
	for (int to : g[v]) {
		if (to != p) {
			if (was[to]) {
				if (cycle.empty()) {
					cycle = cur_path;
					reverse(all(cycle));
					while (cycle.back() != to) {
						cycle.pop_back();
					}
				}
			}
			else {
				dfs(to, v);
			}
		}
	}
	cur_path.pop_back();
}

void dfs1(int v, int p) {
	SZ[v] = 1;
	dp[v] = 0;
	for (int to : g[v]) {
		if (to != p && !on_cycle[to]) {
			dfs1(to, v);
			SZ[v] += SZ[to];
			dp[v] += dp[to];
		}
	}
	dp[v] += SZ[v];
}

void dfs2(int v, int p, int up_dp) {
	dp2[v] = n + up_dp + (dp[v] - SZ[v]);
	for (int to : g[v]) {
		if (to != p && !on_cycle[to]) {
			int new_dp = up_dp + (n - SZ[to]) + (dp[v] - SZ[v] - dp[to]);
			dfs2(to, v, new_dp);
			dp2[v] = max(dp2[v], dp2[to]);
		}
	}
}

int get(int l, int r) {
	if (l <= r) {
		return n - (pref_sz[r] - (l ? pref_sz[l - 1] : 0));
	}
	return pref_sz[l - 1] - pref_sz[r];
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	was.resize(n, false);
	dfs(0, -1);
	on_cycle.resize(n, false);
	for (int u : cycle) {
		on_cycle[u] = true;
	}
	SZ.resize(n);
	dp.resize(n);
	for (int u : cycle) {
		dfs1(u, -1);
	}
	dp2.resize(n);
	for (int u : cycle) {
		dfs2(u, -1, 0);
	}
	int K = sz(cycle);
	pref_sz.resize(K);
	pref_sz[0] = SZ[cycle[0]];
	for (int i = 1; i < K; i++) {
		pref_sz[i] = pref_sz[i - 1] + SZ[cycle[i]];
	}
	//
	for (int i = 0; i < K; i++) {
		opt[i] = dp2[cycle[i]];
	}
	for (int len = 1; len < K; len++) {
		memset(opt1, 0, sizeof(opt1));
		for (int i = 0; i < K; i++) {
			int j = i + len - 1;
			if (j >= K) {
				j -= K;
			}
			int cur = opt[i] + get(i, j);
			{
				int jj = j + 1;
				if (jj == K) {
					jj = 0;
				}
				int u = cycle[jj];
				opt1[i] = max(opt1[i], cur + (dp[u] - SZ[u]));
			}
			{
				int ii = i - 1;
				if (ii == -1) {
					ii = K - 1;
				}
				int u = cycle[ii];
				opt1[ii] = max(opt1[ii], cur + (dp[u] - SZ[u]));
			}
		}
		memcpy(opt, opt1, sizeof(opt));
	}
	cout << *max_element(opt, opt + 15000);
}