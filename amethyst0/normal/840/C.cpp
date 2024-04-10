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
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = 310;
int v[maxn];
int cn[maxn];
bool used[maxn];
int pos = 0;

bool check(ll x) {
	ll l = 0;
	ll r = (ll)1e9;

	while (l != r) {
		ll m = (l + r + 1) >> 1;

		if (m * m > x) {
			r = m - 1;
		} else {
			l = m;
		}
	}

	return l * l == x;
}

ll f[maxn];
ll rf[maxn];
const int mod = (int)1e9 + 7;

ll dp[maxn][maxn][2];
ll z[maxn][maxn][2];
ll c[maxn][maxn];

ll C(int n, int k) {
	if (c[n][k] != -1) {
		return c[n][k];
	}

	if (k == 0 || k == n) {
		return c[n][k] = 1;
	}

	return c[n][k] = (C(n - 1, k) + C(n - 1, k - 1)) % mod;
}

ll goz(int cnt, int num, int tp) {
	if (z[cnt][num][tp] != -1) {
		return z[cnt][num][tp];
	}

	if (cnt == 0) {
		return z[cnt][num][tp] = (num == 0 && tp == 0 ? 1 : 0);
	}

	if (num == 0) {
		return z[cnt][num][tp] = 0;
	}

	ll ans = 0;

	for (int i = 1; i <= cnt; i++) {
		ans += goz(cnt - i, num - 1, (tp + i + 1) & 1) * (C(cnt, i) * f[i] % mod);
		ans %= mod;
	}

	return z[cnt][num][tp] = ans;
}

ll go(int p, int cnt, int tp) {
	if (dp[p][cnt][tp] != -1) {
		return dp[p][cnt][tp];
	}

	if (p == pos) {
		return dp[p][cnt][tp] = (tp == 0 ? f[cnt] : mod - f[cnt]);
	}

	ll ans = 0;

	for (int i = 1; i <= cn[p]; i++) {
		ans += (goz(cn[p], i, 0) * rf[i] % mod) * go(p + 1, cnt + i, tp);
		ans %= mod;
		ans += (goz(cn[p], i, 1) * rf[i] % mod) * go(p + 1, cnt + i, tp ^ 1);
		ans %= mod;
	}

	return dp[p][cnt][tp] = ans;
}

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return my_pow(a, b - 1) * a % mod;
	}

	ll g = my_pow(a, b >> 1);

	return g * g % mod;
}

int main() {
	f[0] = 1;
	rf[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = f[i - 1] * i;
		f[i] %= mod;
		rf[i] = my_pow(f[i], mod - 2);
	}

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int i = 0; i < n; i++) {
		if (used[i]) {
			continue;
		}

		cn[pos] = 1;
		used[i] = true;

		for (int j = i + 1; j < n; j++) {
			if (check((ll)v[i] * v[j])) {
				used[j] = true;
				cn[pos]++;
			}
		}

		pos++;
	}

	memset(dp, -1, sizeof dp);
	memset(c, -1, sizeof c);
	memset(z, -1, sizeof z);

	cout << go(0, 0, 0) << endl;

	return 0;
}