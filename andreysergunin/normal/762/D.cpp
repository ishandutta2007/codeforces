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
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
mt19937 rr(random_device{}());


const ll INF = 1e18;
const int MAXN = 2e5;

ll dp[MAXN][8];
ll v[3][MAXN];

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	}

	for (int mask = 0; mask < 8; ++mask)
		dp[0][mask] = -INF;
	dp[0][1] = 0;

	for (int i = 0; i < n; ++i) {
		dp[i + 1][1] = max({
			dp[i][1] + v[0][i], 
			dp[i][2] + v[0][i] + v[1][i], 
			dp[i][4] + v[0][i] + v[1][i] + v[2][i], 
			dp[i][7] + v[0][i] + v[1][i] + v[2][i]
		});


		dp[i + 1][2] = max({
			dp[i][1] + v[0][i] + v[1][i], 
			dp[i][2] + v[1][i], 
			dp[i][4] + v[1][i] + v[2][i], 
		});

		dp[i + 1][4] = max({
			dp[i][1] + v[0][i] + v[1][i] + v[2][i], 
			dp[i][2] + v[1][i] + v[2][i], 
			dp[i][4] + v[2][i], 
			dp[i][7] + v[0][i] + v[1][i] + v[2][i]
		});

		dp[i + 1][7] = max({
			dp[i][1] + v[0][i] + v[1][i] + v[2][i], 
			dp[i][4] + v[0][i] + v[1][i] + v[2][i], 
			dp[i][7] + v[0][i] + v[1][i] + v[2][i]
		});
	}

	cout << dp[n][4] << endl;

	return 0;
}