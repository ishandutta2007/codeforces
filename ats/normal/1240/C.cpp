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
vector<vector<int> > dp;
vector<vector<int> > w;
int N, K;
void dfs(int a, int p = -1) {

	int sum = 0;
	vector<int> X;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			dfs(g[a][i], a);
			sum += dp[g[a][i]][1];
			if (dp[g[a][i]][1] < dp[g[a][i]][0] + w[a][i]) {
				X.push_back(dp[g[a][i]][0] + w[a][i] - dp[g[a][i]][1]);
			}
		}
	}
	sort(X.rbegin(), X.rend());

	int s = min(K - 1, (int)X.size());
	dp[a][0] = sum;
	for (int i = 0; i < s; i++) {
		dp[a][0] += X[i];
	}
	dp[a][1] = dp[a][0];
	if (s < (int)X.size()) {
		dp[a][1] += X[s];
	}

}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		
		cin >> N >> K;
		int res = 0;
		int a, b, c;
		g.clear();
		w.clear();
		dp.clear();
		g.resize(N);
		w.resize(N);
		dp.resize(N, vector<int>(2));

		for (int i = 0; i < N - 1; i++) {
			cin >> a >> b >> c;
			a--; b--;
			g[a].push_back(b);
			g[b].push_back(a);
			w[a].push_back(c);
			w[b].push_back(c);
		}

		dfs(0);

		cout << dp[0][1] << '\n';
	}
	return 0;
}