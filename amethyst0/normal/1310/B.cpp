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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = (1 << 17) + 10;

bool g[maxn];

const int maxlog = 17;

int dp[maxlog + 1][maxn][2][2];

const int inf = (int)1e9;

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x;
		scanf("%d", &x);
		x--;
		g[x] = true;
	}

	if (k == 0) {
		cout << 0 << '\n';
		return 0;
	}

	int tot = 0;

	for (int i = 0; i < (1 << n); i += 2) {
		dp[1][i][0][0] = dp[1][i][0][1] = dp[1][i][1][0] = dp[1][i][1][1] = -inf;
		dp[1][i][g[i]][g[i + 1]] = 0;
		dp[1][i][g[i + 1]][g[i]] = 0;
		if (g[i] || g[i + 1]) {
			tot++;
		}
	}

	for (int it = 2; it <= n; it++) {
		for (int i = 0; i < (1 << n); i += (1 << it)) {
			dp[it][i][0][0] = dp[it][i][0][1] = dp[it][i][1][0] = dp[it][i][1][1] = -inf;

			for (int a = 0; a < 2; a++) {
				for (int b = 0; b < 2; b++) {
					for (int c = 0; c < 2; c++) {
						for (int d = 0; d < 2; d++) {
							int cur = dp[it - 1][i][a][b] + dp[it - 1][i + (1 << (it - 1))][c][d];
							if (a || c) {
								cur++;
							}

							if (b || d) {
								cur += 2;
							}

							if (b == 0 && d == 0 && a == 1 && c == 1) {
								cur++;
							}

							int x = (a || c);
							int y = (b || d);

							if (b == 0 && d == 0 && a == 1 && c == 1) {
								y = 1;
							}

							dp[it][i][x][y] = max(dp[it][i][x][y], cur);

							if (b == 0 && d == 0 && (a == 1 || c == 1)) {
								cur = dp[it - 1][i][a][b] + dp[it - 1][i + (1 << (it - 1))][c][d];
								cur += 2;
								dp[it][i][0][1] = max(dp[it][i][0][1], cur);
							}
						}
					}
				}
			}
		}
	}

	cout << tot + max(dp[n][0][0][0], max(dp[n][0][0][1] + 1, max(dp[n][0][1][0] + 1, dp[n][0][1][1] + 1))) << '\n';
}