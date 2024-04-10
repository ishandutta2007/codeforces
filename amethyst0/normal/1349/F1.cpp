#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <unordered_map>
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}

	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int my_pow(int x, int y) {
	int ans = 1;

	for (; y; y >>= 1, x = mul(x, x)) {
		if (y & 1) {
			ans = mul(ans, x);
		}
	}

	return ans;
}

const int maxn = 5010;

int dp[maxn][maxn];
int f[maxn], rf[maxn];

int main() {
	f[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = mul(i, f[i - 1]);
		rf[i] = my_pow(f[i], mod - 2);
	}

	int n;
	cin >> n;

	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		int s = 0;
		for (int j = 1; j <= i; j++) {
			dp[i][j] = add(mul(dp[i - 1][j], j), mul(dp[i - 1][j - 1], i - j + 1));
			s = add(s, dp[i][j]);
		}
	}

	for (int x = 0; x < n; x++) {
		int ans = 0;
		for (int i = x + 1; i <= n; i++) {
			ans = add(ans, mul(dp[i][x + 1], rf[i]));
		}

		ans = mul(ans, f[n]);

		printf("%d ", ans);
	}
}