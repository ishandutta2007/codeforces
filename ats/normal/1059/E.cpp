#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
vector<vector<int> > g;
vector<int> W;
vector <map<pair<int, int>, int>  > dp;
vector<int> mm;
int N, L, S;
int dfs(int a) {
	int mn = 0;
	for (int i = 0; i < g[a].size(); i++) {
		dfs(g[a][i]);
		auto& mp = dp[g[a][i]];
		mm[g[a][i]] = N;
		for (auto m : mp) {
			mm[g[a][i]] = min(mm[g[a][i]], m.first.second);
		}
		mn += mm[g[a][i]];
	}
	for (int i = 0; i < g[a].size(); i++) {
		auto& mp = dp[g[a][i]];
		for (auto m : mp) {
			if (mm[g[a][i]] + 1 >= m.first.second && m.first.first + 1 <= L && m.second + W[a] <= S) {
				pair<int, int> p(m.first.first + 1, m.first.second + mn - mm[g[a][i]]);
				if (dp[a].count(p) == 0) {
					dp[a][p] = m.second + W[a];
				}
				else {
					dp[a][p] = min(dp[a][p], m.second+ W[a]);
				}
			}
		}
	}
	if (dp[a].size() == 0) {
		dp[a][make_pair(1, mn + 1)] = W[a];
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L >> S;
	g.resize(N);
	W.resize(N);
	dp.resize(N);
	mm.resize(N, N);
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	int a;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		a--;
		g[a].push_back(i + 1);
	}
	for (int i = 0; i < N; i++) {
		if (W[i] > S) {
			cout << -1 << endl;
			return 0;
		}
	}
	dfs(0);
	int res = N;
	for (auto d : dp[0]) {
		res = min(res, d.first.second);
	}
	cout << res << endl;
}