//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <limits.h>
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
#define pll pair <ll, ll>

using namespace std;

const int mod = 998244353;

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int my_pow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

int r;

const int maxn = 310;

int dp[maxn][2][maxn];

vector <int> ed[maxn];

void dfs(int v, int p) {
	for (int i = 0; i < (int)ed[v].size(); i++) {
		if (ed[v][i] == p) {
			swap(ed[v][i], ed[v].back());
			ed[v].pop_back();
			break;
		}
	}

	for (int u : ed[v]) {
		dfs(u, v);
	}

	for (int it = 0; it < 2; it++) {
		for (int d = 0; d <= r; d++) {
			if (it == 1 || d == 0) {
				int res = 1;
				for (int u : ed[v]) {
					res = mul(res, add(add(dp[u][1][d + 1], dp[u][0][d]), (d > 0 ? dp[u][0][d - 1] : 0)));
				}

				dp[v][it][d] = res;
			}
			else {
				vector <int> a;
				for (int u : ed[v]) {
					int cur = add(add(dp[u][1][d + 1], dp[u][0][d]), (d > 0 ? dp[u][0][d - 1] : 0));
					a.push_back(cur);
				}

				for (int i = (int)a.size() - 2; i >= 0; i--) {
					a[i] = mul(a[i], a[i + 1]);
				}

				int val = 1;
				int res = 0;

				for (int i = 0; i < (int)ed[v].size(); i++) {
					res = add(res, mul(dp[ed[v][i]][0][d - 1], mul(val, (i + 1 == (int)ed[v].size() ? 1 : a[i + 1]))));
					int u = ed[v][i];
					val = mul(val, add(dp[u][1][d + 1], dp[u][0][d]));
				}

				dp[v][it][d] = res;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	int total = my_pow(2, n);

	int ans = 0;
	int r2 = my_pow(2, mod - 2);

	for (r = 1; r <= n; r++) {
		memset(dp, 0, sizeof dp);
		dfs(0, -1);

		int tot = 0;

		for (int i = 0; i <= r; i++) {
			tot = add(tot, dp[0][0][i]);
		}

		tot = sub(total, tot);
		ans = add(ans, tot);
	}

	ans = sub(ans, 1);
	ans = mul(ans, my_pow(r2, n));
	cout << ans << '\n';
}