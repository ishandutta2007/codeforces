//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int mod = (int)1e9 + 7;
int r2 = (mod + 1) / 2;

const int maxn = 2010;
int dp[maxn][maxn];

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int go(int n, int m) {
	if (m == 0) {
		return dp[n][m] = 0;
	}
	if (n == m) {
		return dp[n][m] = n;
	}

	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	dp[n][m] = mul(add(go(n - 1, m - 1), go(n - 1, m)), r2);
	return dp[n][m];
}

int main() {
	memset(dp, -1, sizeof dp);
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);

		printf("%d\n", mul(k, go(n, m)));
	}
}