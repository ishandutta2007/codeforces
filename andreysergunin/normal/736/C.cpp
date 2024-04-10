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

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;

const int P = 1e9 + 7;

vector<vector<int>> g;

ll dp[110][50][25];

int k;

void add(ll &a, ll b) {
	a += b;
	if (a >= P)
		a -= P;
}

void dfs(int v, int p) {

	if (sz(g[v]) == 1 && p != -1) {
		dp[v][k + 1][1] = 1;
		dp[v][1][0] = 1;
		return;
	}

	for (int i = 0; i < sz(g[v]); ++i) {
		if (g[v][i] != p) 
			dfs(g[v][i], v);
	}
	
	int start = (g[v][0] == p ? 1 : 0);	

	int u = g[v][start];

	for (int j = 0; j <= 2 * k + 3; ++j) {
		for (int l = 0; l <= k + 1; ++l) {
			// if (j <= k)
			// 	add(dp[v][j + 1][0], dp[u][j][l]);
			// else

			if (l != 0 || j > k) 
				add(dp[v][j + 1][l + 1], dp[u][j][l]);
			else {
				add(dp[v][j + 1][0], dp[u][j][l]);
			}

			// if (l <= k)
			// 	add(dp[v][1][0], dp[u][j][l]);
			// else 
			// 	add(dp[v][1][l + 1], dp[u][j][l]);
		}
	}

	for (int i = start + 1; i < sz(g[v]); ++i) {
		if (p == g[v][i])
			continue;

		ll dpNext[50][25];
		for (int j = 0; j <= 2 * k + 3; ++j)
			for (int l = 0; l <= k + 1; ++l)
				dpNext[j][l] = 0;

		int u = g[v][i];
		for (int j = 0; j <= 2 * k + 3; ++j) {
			for (int l = 0; l <= k + 1; ++l) {
				for (int p = 0; p <= 2 * k + 3; ++p) {
					for (int q = 0; q <= k + 1; ++q) {
						int h1 = min(j, p + 1);
						int h2 = k - (h1 - 1) + 1;
						int h3 = max(l, q + 1);
						if (h3 <= h2) {
							add(dpNext[h1][0], dp[v][j][l] * dp[u][p][q] % P);
						} else {
							add(dpNext[h1][h3], dp[v][j][l] * dp[u][p][q] % P);
						}

						// h2 = k + 1;
						// if (h3 <= h2) {
						// 	add(dpNext[1][0], dp[v][j][l] * dp[u][p][q] % P);
						// } else {
						// 	add(dpNext[1][h3], dp[v][j][l] * dp[u][p][q] % P);
						// }
					}
				}
			}
		}

		for (int j = 0; j <= 2 * k + 3; ++j)
			for (int l = 0; l <= k + 1; ++l)
				dp[v][j][l] = dpNext[j][l];
	}

	for (int j = 0; j <= 2 * k + 3; ++j) {
		for (int l = 0; l <= k + 1; ++l) {
			add(dp[v][1][0], dp[v][j][l]);
		}
	}
}

int main()
{

	// ifstream cin("joke.in");
	// ofstream cout("joke.out");


	int n;
	cin >> n >> k;

	g.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	dfs(0, -1);

	ll ans = 0;

	for (int i = 0; i <= 2 * k + 3; ++i) {
		// cout << dp[0][i + 1][0] << endl;
		add(ans, dp[0][i + 1][0]);
	}

	cout << ans << endl;

}