#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)2e5 + 10, maxm = 3010, mod = 998244353;

int dp[maxm][maxm];
int sum;
int bad;

int w[maxn];
int a[maxn];

int n, m;

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = (ll)ans * x % mod;
		}

		y >>= 1;
		x = (ll)x * x % mod;
	}

	return ans;
}

int ver[maxm];
int rever[maxm];

int main() {
	cin >> n >> m;

	bad = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);

		if (a[i] == 0) {
			a[i] = -1;
		}
	}

	sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		sum += w[i];

		if (a[i] == -1) {
			bad += w[i];
		}
	}

	dp[0][0] = 1;

	int sumver = 0;
	int sumrever = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= i; j++) {
			int we = bad - j;

			if (we < 0) {
				continue;
			}

			int cur = sum - j + (i - j);

			int re_cur = my_pow(cur, mod - 2);

			int good = cur - we;

			ver[i] = (ver[i] + (ll)((ll)re_cur * dp[i][j] % mod) * good) % mod;
			rever[i] = (rever[i] + (ll)((ll)re_cur * dp[i][j] % mod) * we) % mod;

			dp[i + 1][j] = (dp[i + 1][j] + (ll)((ll)re_cur * dp[i][j] % mod) * good) % mod;
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (ll)((ll)re_cur * dp[i][j] % mod) * we) % mod;
		}

		sumver = (sumver + ver[i]) % mod;
		sumrever = (sumrever + rever[i]) % mod;
	}

	for (int i = 0; i < n; i++) {
		int ans = w[i];

		int pr = 0;

		if (a[i] == 1) {
			pr = (ll)w[i] * my_pow(sum - bad, mod - 2) % mod;
		}
		else {
			pr = (ll)w[i] * my_pow(bad, mod - 2) % mod;
		}

		if (a[i] == 1) {
			ans = (ans + (ll)pr * sumver) % mod;
		}
		else {
			ans = (ans - (ll)pr * sumrever) % mod;
		}

		if (ans < 0) {
			ans += mod;
		}

		printf("%d\n", ans);
	}

	//system("pause");
}