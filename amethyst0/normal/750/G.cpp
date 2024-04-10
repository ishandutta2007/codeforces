/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
//#include <unordered_map>
//#include <random>
//#include <unordered_set>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 110;

ll sum[maxn];

ll dp[maxn][maxn][2];
int lena, lenb;

ll go(ll s, int pos, int x, int o) {
	if (x < 0) {
		return 0;
	}

	if (dp[pos][x][o] != -1) {
		return dp[pos][x][o];
	}

	if (pos >= lena && pos >= lenb) {
		if (x == 0 && s == o) {
			dp[pos][x][o] = 1;
		} else {
			dp[pos][x][o] = 0;
		}

		return dp[pos][x][o];
	}

	dp[pos][x][o] = 0;

	for (int i = 0; i < 2; i++) {
		int j = (s & 1) ^ i ^ o;

		if (i == 1 && pos >= lena) {
			continue;
		}

		if (j == 1 && pos >= lenb) {
			continue;
		}

		dp[pos][x][o] += go(s >> 1, pos + 1, x - i - j, (o + i + j) >> 1);
	}

	return dp[pos][x][o];
}

int main() {
	sum[0] = 0;
	for (int i = 1; i < 52; i++) {
		sum[i] = (sum[i - 1] + (1ll << (i - 1)));
	}

	ll s;

	cin >> s;

	ll ans = 0;

	for (int l = 0; l <= 50; l++) {
		for (int r = 0; r <= 50; r++) {
			lena = l;
			lenb = r;

			if (s < sum[r]) {
				break;
			}

			ll now = s - sum[r];

			ll mod = 2 * sum[l] + 2 * sum[r] + 1;

			if (now < mod) {
				break;
			}

			now %= mod;

			for (int x = 0; x <= l + r - (l != 0) - (r != 0); x++) {
				if ((now + x) & 1) {
					continue;
				}

				memset(dp, -1, sizeof dp);
				ans += go((now + x) >> 1, 1, x, 0);
			}
		}
	}

	cout << ans << endl;

	return 0;
}