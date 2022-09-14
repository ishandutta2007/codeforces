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

const int maxn = 110, mod = (int)1e9 + 7;

int dp[maxn][maxn];
int v[maxn];
int c[maxn][maxn];

int C(int n, int k) {
	if (c[n][k] != -1) {
		return c[n][k];
	}

	if (k == 0 || k == n) {
		return c[n][k] = 1;
	}

	return c[n][k] = (C(n - 1, k - 1) + C(n - 1, k)) % mod;
}

int go(int d, int pos) {
	if (dp[d][pos] != -1) {
		return dp[d][pos];
	}

	if (pos == 10) {
		if (d == 0) {
			return 1;
		}

		return 0;
	}

	int ans = 0;

	for (int i = v[pos]; i <= d; i++) {
		ans = (ans + (ll)C(d, i) * go(d - i, pos + 1)) % mod;
	}

	return dp[d][pos] = ans;
}

int main() {
	memset(c, -1, sizeof c);
	int n;

	cin >> n;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &v[i]);
	}

	memset(dp, -1, sizeof dp);

	int ans = 0;

	for (int i = 1; i < 10; i++) {
		memset(dp, -1, sizeof dp);
		bool fl = true;

		if (v[i] == 0) {
			fl = false;
		}
		else {
			v[i]--;
		}

		for (int d = 0; d <= n - 1; d++) {
			ans += go(d, 0);
			if (ans >= mod) {
				ans -= mod;
			}
		}

		if (fl) {
			v[i]++;
		}
	}

	cout << ans << endl;

	return 0;
}