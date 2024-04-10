/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 310;

int dp[2][maxn][maxn][2];
int v[maxn][maxn];
bool used[maxn][maxn][2];

int n;

int y;

int go(int it, int l, int r, int tp) {
	if (used[l][r][tp]) {
		return dp[it][l][r][tp];
	}

	used[l][r][tp] = true;

	dp[it][l][r][tp] = v[l][y] + v[r][y] - (l == r ? v[l][y] : 0) + dp[it ^ 1][l][r][0];

	if (tp == 0 && l != n - 1) {
		dp[it][l][r][tp] = max(dp[it][l][r][tp], go(it, l + 1, max(r, l + 1), tp) + v[l][y]);
	}

	if (r != n - 1) {
		dp[it][l][r][tp] = max(dp[it][l][r][tp], go(it, l, r + 1, 1) + (l != r ? v[r][y] : 0));
	}

	return dp[it][l][r][tp];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[0][i][j][0] = -(int)1e9;
		}
	}

	dp[0][n - 1][n - 1][0] = 0;

	int it = 1;

	for (y = n - 1; y >= 0; y--) {
		memset(used, 0, sizeof used);

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				go(it, i, j, 0);
			}
		}

		it ^= 1;
	}

	it ^= 1;

	cout << dp[it][0][0][0] << endl;

	return 0;
}