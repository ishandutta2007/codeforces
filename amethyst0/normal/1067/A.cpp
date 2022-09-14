#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10, mod = 998244353;
const int maxm = 210;

int dp[maxn][2][maxm];
int v[maxn];

int get_sum(int pos, int tp, int l, int r) {
	int ans = dp[pos][tp][r] - dp[pos][tp][l - 1];

	if (ans < 0) {
		ans += mod;
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 1; i <= 200; i++) {
		if (v[n - 1] == -1 || v[n - 1] == i) {
			dp[n - 1][0][i] = 0;
			dp[n - 1][1][i] = 1;
		}

		dp[n - 1][1][i] += dp[n - 1][1][i - 1];

		if (dp[n - 1][1][i] >= mod) {
			dp[n - 1][1][i] -= mod;
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j <= 200; j++) {
			if (v[i] == -1 || v[i] == j) {
				//tp == 0
				dp[i][0][j] = get_sum(i + 1, 0, j + 1, 200);
				dp[i][0][j] += get_sum(i + 1, 1, j, j);
				if (dp[i][0][j] >= mod) {
					dp[i][0][j] -= mod;
				}

				//tp == 1
				dp[i][1][j] = get_sum(i + 1, 0, j + 1, 200);
				dp[i][1][j] += get_sum(i + 1, 1, 1, j);
				if (dp[i][1][j] >= mod) {
					dp[i][1][j] -= mod;
				}
			}
		}

		for (int j = 1; j <= 200; j++) {
			dp[i][0][j] += dp[i][0][j - 1];
			dp[i][1][j] += dp[i][1][j - 1];

			if (dp[i][0][j] >= mod) {
				dp[i][0][j] -= mod;
			}

			if (dp[i][1][j] >= mod) {
				dp[i][1][j] -= mod;
			}
		}
	}

	ll ans = 0;

	for (int i = 1; i <= 200; i++) {
		if (v[0] == -1 || i == v[0]) {
			ans += dp[0][0][i] - dp[0][0][i - 1];
			ans %= mod;

			if (ans < 0) {
				ans += mod;
			}
		}
	}

	cout << ans << endl;

	//system("pause");
}