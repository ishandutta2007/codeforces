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
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 55;
int v[maxn];
int dp[maxn];
int sum[maxn][maxn];
int n;

int go(int l) {
	if (l == n) {
		return 0;
	}

	if (dp[l] != -1) {
		return dp[l];
	}

	int ans = go(l + 1);
	ans = max(ans, sum[l + 1][n - 1] - go(l + 1) + v[l]);

	return dp[l] = ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	
	cin >> n;

	int sums = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		sums += v[i];
	}

	for (int i = 0; i < n; i++) {
		int now = 0;

		for (int j = i; j < n; j++) {
			now += v[j];
			sum[i][j] = now;
		}
	}

	int ans = go(0);

	cout << sums - ans << ' ' << ans << endl;

	return 0;
}