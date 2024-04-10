#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<vector<int>> g;
vector<int> used;

struct Women {
	int w;
	int b;
	bool f = false;
};

vector<Women> w;
vector<Women> rw; 

Women dfs(int v) {
	rw.push_back(w[v]);
	used[v] = 1;
	Women ans = w[v];
	ans.f = true;

	for (auto u : g[v]) {
		if (!used[u]) {
			Women p = dfs(u);
			ans.w += p.w;
			ans.b += p.b;
		}
	}
	return ans;
}

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n, m, weight;
	cin >> n >> m >> weight;
	g.resize(n);
	w.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> w[i].w;
	for (int i = 0; i < n; ++i)
		cin >> w[i].b;


	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	used.resize(n);

	for (int i = 0; i < n; ++i) {
		if (!used[i])
			rw.push_back(dfs(i));
	}

	n = sz(rw);

	vector<vector<int>> dp(n + 1, vector<int>(weight + 1, 0));

	int prev = -1;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= weight; ++j) {
			dp[i + 1][j] = dp[i][j];
			dp[i + 1][j] = max(dp[i + 1][j], dp[prev + 1][j]);
			if (j >= rw[i].w) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[prev + 1][j - rw[i].w] + rw[i].b);
			}
		}
		if (rw[i].f)
			prev = i;
	}

	int ans = 0;
	for (int i = 0; i <= weight; ++i) {
		ans = max(ans, dp[n][i]);
	}

	cout << ans << endl;


}