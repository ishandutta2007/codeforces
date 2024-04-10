/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)5010, mod = (int)1e9 + 7;

ll pr[maxn];
ll dp[maxn][maxn];
int a[maxn];
ll st[maxn];

int n, k;

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return a * my_pow(a, b - 1) % mod;
	}

	ll z = my_pow(a, b >> 1);

	return z * z % mod;
}

ll go(int pos, int now) {
	if (dp[pos][now] != -1) {
		return dp[pos][now];
	}

	if (pos == n) {
		if (now == 0) {
			return dp[pos][now] = 0;
		}
		else {
			ll z = (pr[now] * st[now]) % mod;
			
			if (now % 2 == 0) {
				z = (mod - z) % mod;
			}

			return dp[pos][now] = z;
		}
	}

	return dp[pos][now] = (go(pos + 1, now) * a[pos] + go(pos + 1, now + 1)) % mod;
}

int main() {
	memset(dp, -1, sizeof dp);

	cin >> n >> k;

	pr[0] = 1;

	for (int i = 1; i <= n; i++) {
		pr[i] = pr[i - 1] * (k - i + 1) % mod;
	}

	for (int i = 0; i <= n; i++) {
		if (i < k) {
			st[i] = my_pow(n, k - i);
		}
		if (i == k) {
			st[i] = 1;
		}
		else if (i > k) {
			st[i] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	ll ans = go(0, 0);

	ans = ans * my_pow(my_pow(n, k), mod - 2) % mod;
	cout << ans << endl;
}