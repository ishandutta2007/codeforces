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

const int maxn = 55, mod = 998244353;

int dp[maxn][maxn][maxn][maxn];
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

int go(int it, int pos, int g, int cnt) {
	if (dp[it][pos][g][cnt] != -1) {
		return dp[it][pos][g][cnt];
	}

	if (pos == m) {
		return dp[it][pos][g][cnt] = w[it] + a[it] * g;
	}

	int we = w[it] + a[it] * g;
	int cur = sum + cnt - (pos - cnt);

	if (cur == 0) {
		return dp[it][pos][g][cnt] = 0;
	}

	int re_cur = my_pow(cur, mod - 2);

	int ans = 0;

	if (we != 0) {
		int pr = (ll)we * re_cur % mod;
		ans = (ans + (ll)pr * go(it, pos + 1, g + 1, cnt + (a[it] == 1))) % mod;
	}

	int cur_bad = bad - (pos - cnt);

	if (a[it] == -1) {
		cur_bad -= we;
	}

	if (cur_bad != 0) {
		int pr = (ll)cur_bad * re_cur % mod;
		ans = (ans + (ll)pr * go(it, pos + 1, g, cnt)) % mod;
	}

	int cur_good = cur - cur_bad - we;

	if (cur_good != 0) {
		int pr = (ll)cur_good * re_cur % mod;
		ans = (ans + (ll)pr * go(it, pos + 1, g, cnt + 1)) % mod;
	}

	return dp[it][pos][g][cnt] = ans;
}

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

	memset(dp, -1, sizeof dp);

	for (int i = 0; i < n; i++) {
		printf("%d\n", go(i, 0, 0, 0));
	}

	//system("pause");
}