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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

#define tm asjdhaksd

const int maxn = 2010;
int l[maxn], s[maxn];
int c[2 * maxn];

const int maxlog = 13;

const int inf = (int)1e9;

ll res = 0;

void remax(ll &x, ll y) {
	res = max(res, y);
	x = max(x, y);
}

int get_sum(int l, int r) {
	if (l > r) {
		return 0;
	}

	return (l == 0 ? c[r] : c[r] - c[l - 1]);
}

ll dp[maxn][1 << maxlog];
ll best[maxn];

ll old[maxn][1 << maxlog];
int tm[maxn][1 << maxlog];
int curtm = -1;

int num[1 << maxlog];

int main() {
	for (int i = 1; i < (1 << maxlog); i++) {
		if (i & 1) {
			num[i] = num[i >> 1] + 1;
		}
		else {
			num[i] = 0;
		}
	}

	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
		l[i]--;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	for (int i = 0; i < n + m; i++) {
		scanf("%d", &c[i]);
	}

	for (int i = 1; i < n + m; i++) {
		c[i] += c[i - 1];
	}

	for (int i = 0; i < maxn; i++) {
		for (int j = 1; j < (1 << maxlog); j++) {
			dp[i][j] = -inf;
		}

		dp[i][0] = 0;
	}

	for (int i = n - 1; i >= 0; i--) {
		curtm = i + 1;
		int cl = l[i];

		for (int d = 0; d < maxlog; d++) {
			if (cl - d < 0) {
				break;
			}

			for (int mask = (1 << maxlog) - 1; mask >= 0; mask--) {
				ll cur = (curtm != tm[cl - d][mask] ? dp[cl - d][mask] : old[cl - d][mask]);

				int nm = (mask >> d);

				int cnt = num[nm];
				nm++;
				cur += get_sum(cl, cl + cnt);
				cur -= s[i];

				if (tm[cl][nm] != curtm) {
					tm[cl][nm] = curtm;
					old[cl][nm] = dp[cl][nm];
				}

				remax(dp[cl][nm], cur);
				remax(best[cl], cur);
			}
		}

		for (int d = maxlog; d < maxn; d++) {
			if (cl - d < 0) {
				break;
			}

			remax(dp[cl][1], best[cl - d] - s[i] + get_sum(cl, cl));
			remax(best[cl], best[cl - d] - s[i] + get_sum(cl, cl));
		}
	}

	cout << res << '\n';

	return 0;
}