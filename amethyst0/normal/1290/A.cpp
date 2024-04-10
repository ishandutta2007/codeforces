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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = 3510;
int v[maxn];
int dp[maxn][maxn];
int len = -1;

int go(int l, int r) {
	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	if (r - l + 1 == len) {
		return dp[l][r] = max(v[l], v[r]);
	}

	return dp[l][r] = min(go(l + 1, r), go(l, r - 1));
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m, k;

		scanf("%d %d %d", &n, &m, &k);
		len = n - m + 1;

		if (k >= m) {
			k = m - 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				dp[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}

		int ans = 0;

		for (int i = 0; i <= k; i++) {
			ans = max(ans, go(i, n - 1 - (k - i)));
		}

		printf("%d\n", ans);
	}
}