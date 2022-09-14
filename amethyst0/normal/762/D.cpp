/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
#include <unordered_map>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;

int v[3][maxn];
ll dp[3][maxn];
ll f[2][maxn];
ll pre[maxn], suf[maxn];
ll gl[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
		}
	}

	ll now = v[1][0];

	for (int i = 0; i < n; i++) {
		now += v[2][i];
	}

	for (int i = 0; i < n; i++) {
		dp[0][i] = now;

		if (i != n - 1) {
			now -= v[2][i];
			now += v[1][i + 1];
		}
	}

	now = 0;

	for (int i = n - 1; i >= 0; i--) {
		now += v[1][i] + v[2][i];

		dp[1][i] = now;
	}

	now = 0;

	for (int i = 0; i < n; i++) {
		now += v[1][i];
		pre[i] = now;
	}

	now = 0;

	for (int i = n - 1; i >= 0; i--) {
		now += v[1][i];
		suf[i] = now;
	}

	for (int i = n - 2; i >= 0; i--) {
		dp[0][i] = max(dp[0][i + 1], dp[0][i]);
	}

	for (int i = 1; i < n; i++) {
		dp[1][i] = max(dp[1][i], dp[1][i - 1]);
	}

	now = 0;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 3; j++) {
			now += v[j][i];
		}

		gl[i] = now;
	}

	now = 0;

	dp[0][n - 1] = (ll)v[0][n - 1] + v[1][n - 1] + v[2][n - 1];
	dp[1][n - 1] = v[1][n - 1] + v[2][n - 1];
	dp[2][n - 1] = v[2][n - 1];

	now = dp[2][n - 1];
	ll lnow = dp[0][n - 1];

	for (int i = n - 2; i >= 0; i--) {
		now += (ll)v[0][i] + v[1][i] + v[2][i];
		lnow += (ll)v[0][i] + v[1][i] + v[2][i];

		dp[0][i] = v[0][i] + dp[0][i + 1];

		dp[0][i] = max(dp[0][i], dp[1][i + 1] + v[0][i] + v[1][i]);
		dp[0][i] = max(dp[0][i], dp[2][i + 1] + v[0][i] + v[1][i] + v[2][i]);
		dp[0][i] = max(dp[0][i], now);
		dp[0][i] = max(dp[0][i], gl[i]);

		dp[1][i] = dp[1][i + 1] + v[1][i];
		dp[1][i] = max(dp[1][i], v[1][i] + v[0][i] + dp[0][i + 1]);
		dp[1][i] = max(dp[1][i], v[1][i] + v[2][i] + dp[2][i + 1]);

		dp[2][i] = v[2][i] + dp[2][i + 1];
		dp[2][i] = max(dp[2][i], dp[1][i + 1] + v[2][i] + v[1][i]);
		dp[2][i] = max(dp[2][i], dp[0][i + 1] + v[0][i] + v[1][i] + v[2][i]);
		dp[2][i] = max(dp[2][i], lnow);
		dp[2][i] = max(dp[2][i], gl[i]);

		now = max(now, dp[2][i]);
		lnow = max(lnow, dp[0][i]);
	}

	cout << dp[0][0] << endl;

	return 0;
}