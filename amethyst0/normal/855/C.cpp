/*AMETHYSTS*/
#include <cstdio>
#include <fstream>
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10, mod = (int)1e9 + 7;
vector <int> ed[maxn];
ll x;
ll k;

ll dp[maxn][11][3];
vector <ll> zz[maxn][3];

ll go(int v, int p, int m, int tp);

void getzz(int v, int p, int tp) {
	if (!zz[v][tp].empty()) {
		return;
	}

	vector <ll> z;
	z.assign(11, 0);
	z[0] = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];
		if (u == p) {
			continue;
		}

		vector <ll> buf = z;
		z.assign(11, 0);

		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 10 - j; k++) {
				z[j + k] = (z[j + k] + buf[j] * go(u, v, k, tp)) % mod;
			}
		}
	}

	zz[v][tp] = z;
}

ll go(int v, int p, int m, int tp) {
	if (dp[v][m][tp] != -1) {
		return dp[v][m][tp];
	}

	getzz(v, p, 0);
	getzz(v, p, 1);
	getzz(v, p, 2);

	if (tp == 1) {
		return dp[v][m][tp] = zz[v][0][m] * (x - 1) % mod;
	} else if (tp == 0) {
		ll ans = zz[v][0][m] * (x - 1) % mod;

		if (m != 0) {
			ans = (ans + zz[v][1][m - 1]) % mod;
		}

		ans = (ans + zz[v][2][m] * (k - x)) % mod;

		return dp[v][m][tp] = ans;
	} else {
		ll ans = zz[v][0][m] * (x - 1) % mod;

		ans = (ans + zz[v][2][m] * (k - x)) % mod;

		return dp[v][m][tp] = ans;
	}
}

int main() {
	memset(dp, -1, sizeof dp);

	int n, m;

	cin >> n >> k;
	//n = (int)1e5;
	//k = (int)1e9;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		//x = i + 1;
		//y = i + 2;

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	cin >> x >> m;
	//x = k / 2;
	//m = 10;

	ll ans = 0;

	for (int i = 0; i <= m; i++) {
		ans += go(1, 1, i, 0);
	}

	cout << ans % mod << endl;

	return 0;
}