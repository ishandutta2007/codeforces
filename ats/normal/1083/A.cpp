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
int res = 0;
vector<vector<int> > g;
vector<vector<int> > len;
vector<int> w;
int dfs(int a, int p) {

	int mx1 = 0;
	int mx2 = 0;
	for (int i = 0; i < g[a].size(); i++) {
		if (g[a][i] != p) {
			int r = dfs(g[a][i], a) - len[a][i];
			if (mx1 < r) {
				mx2 = mx1;
				mx1 = r;
			}
			else if (mx2 < r) {
				mx2 = r;
			}
		}
	}

	res = max(res, w[a] + mx1 + mx2);

	return mx1 + w[a];
}
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	g.resize(N);
	w.resize(N);
	len.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
		res = max(res, w[i]);
	}
	int u, v, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> c; u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
		len[u].push_back(c);
		len[v].push_back(c);
	}
	dfs(0, -1);
	cout << res << endl;
}