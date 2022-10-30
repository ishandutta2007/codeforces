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
int INF = (int)1e9;
int N, K;
int res = 1;
vector<int> path;
vector<int> dp1;
vector<int> dp2;
int dfs(int a) {
	path.push_back(a);
	int ans = 0;
	int mx = 0;
	int base = 0;
	for (int i = 0; i < g[a].size(); i++) {
		int t = dfs(g[a][i]);
		base += dp2[g[a][i]];
		dp2[a] += dp2[g[a][i]];
		mx = max(mx, t - dp2[g[a][i]]);
	}
	for (int i = 0; i < g[a].size(); i++) {
		dp1[a] += dp1[g[a][i]];
	}
	if (dp1[a] == 0) {
		dp2[a] = 0;
	}
	/*if (a == 0) {
		cerr << ans << " " << mx << endl;
	}*/
	ans = base + mx;
	if ((int)g[a].size() == 0) {
		ans = 1;
		int t = (int)path.size() - K - 1;
		if (t >= 0) {
			dp1[path[t]]--;
		}
		dp1[a]++;
		dp2[a] = 1;
	}
	path.pop_back();
	return ans;
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	g.resize(N);
	dp1.resize(N, 0);
	dp2.resize(N, 0);
	int a;
	for (int i = 0; i < N - 1; i++) {
		cin >> a;
		a--;
		g[a].push_back(i + 1);
	}

	cout << dfs(0) << endl;
}