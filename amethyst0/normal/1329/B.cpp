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

const int maxn = 40;
ll d;
int m;

ll cnt[maxn];
int dp[maxn];

int go(int w) {
	if (cnt[w] == 0) {
		return 0;
	}

	if (dp[w] != -1) {
		return dp[w];
	}

	dp[w] = 1 % m;

	for (int i = w + 1; i < maxn; i++) {
		dp[w] += go(i);
		dp[w] %= m;
	}

	dp[w] = (ll)dp[w] * cnt[w] % m;
	return dp[w];
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		cin >> d >> m;

		int old = maxn - 1;

		while (!((d >> old) & 1)) {
			old--;
		}
		
		for (int i = 0; i < maxn; i++) {
			if ((1ll << i) > d) {
				cnt[i] = 0;
				continue;
			}

			if (i == old) {
				cnt[i] = 1;
				for (int j = i - 1; j >= 0; j--) {
					if ((d >> j) & 1) {
						cnt[i] += (1ll << j);
					}
				}
			}
			else {
				cnt[i] = (1ll << i);
			}
		}

		int ans = 0;

		memset(dp, -1, sizeof dp);

		for (int i = 0; i < maxn; i++) {
			ans += go(i);
			ans %= m;
		}

		cout << ans << '\n';
	}
}