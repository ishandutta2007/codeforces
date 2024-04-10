//#pragma comment(linker, "/STACK:1000000000")
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
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}

	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}

	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		x = mul(x, x);
		y >>= 1;
	}

	return ans;
}

const int maxn = 3605;

int dp[maxn][maxn];

int go(int pos, int cnt, int n, const vector <bool> &us) {
	if (cnt < 0) {
		return 0;
	}

	if (dp[pos][cnt] != -1) {
		return dp[pos][cnt];
	}

	int &ans = dp[pos][cnt];
	ans = 0;

	if (pos == n) {
		return ans = (cnt == 0);
	}

	ans = add(ans, go(pos + 1, cnt, n, us));

	if (pos + 1 < n && !us[pos] && !us[pos + 1]) {
		ans = add(ans, go(pos + 2, cnt - 1, n, us));
	}

	return ans;
}

vector <int> solve(int n, vector <bool> us) {
	memset(dp, -1, sizeof dp);

	vector <int> ans(n + 1);

	for (int i = 0; i <= n; i++) {
		ans[i] = go(0, i, n, us);
	}

	return ans;
}

int c[maxn][maxn];
int f[maxn];

int main() {
	int n, m, cnt;

	cin >> n >> m >> cnt;

	vector <bool> usx(n), usy(m);

	for (int i = 0; i < cnt; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;

		usx[x1] = true;
		usx[x2] = true;
		usy[y1] = true;
		usy[y2] = true;
	}

	vector <int> a = solve(n, usx), b = solve(m, usy);
	int cnx = 0;
	int cny = 0;

	for (bool x : usx) {
		if (!x) {
			cnx++;
		}
	}

	for (bool x : usy) {
		if (!x) {
			cny++;
		}
	}

	f[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = mul(f[i - 1], i);
	}

	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			}
			else {
				c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
			}
		}
	}

	int ans = 0;

	for (int t = 0; t <= n; t++) {
		for (int o = 0; o <= cnx - 2 * t; o++) {
			if (t + 2 * o > cny) {
				break;
			}

			int res = a[t];
			res = mul(res, c[cnx - 2 * t][o]);
			res = mul(res, b[o]);
			res = mul(res, c[cny - 2 * o][t]);
			res = mul(res, f[o]);
			res = mul(res, f[t]);
			ans = add(ans, res);
		}
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}