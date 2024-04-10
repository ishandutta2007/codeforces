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
#include <unordered_map>
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)3e5 + 10, mod = 998244353;

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

	for (; y; y >>= 1, x = mul(x, x)) {
		if (y & 1) {
			ans = mul(ans, x);
		}
	}

	return ans;
}

pii dp[maxn];
int v[maxn];
int res[maxn];

int main() {
	int m;

	cin >> m;

	int n = 0;

	int ps = 0;

	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
		n += v[i];

		if (v[i] > v[ps]) {
			ps = i;
		}
	}

	dp[1] = mp(1, 0);
	dp[0] = mp(1, 0);
	//dp[0] = mp(0, 0);

	int rn = my_pow(n, mod - 2);
	int rm = my_pow(m - 1, mod - 2);

	for (int i = 1; i < n; i++) {
		int p1 = mul(i, rn);
		int p2 = sub(1, p1);
		int p3 = mul(p2, rm);
		int p4 = mul(p2, mul(m - 2, rm));
		//dp[i] = i / n + p1 * dp[i - 1] + p3 * dp[i + 1] + p4 * dp[i]
		//dp[i + 1] = (-dp[i - 1] * p1 + dp[i] * (1 - p4) - 1) / p3
		pii cur = mp(0, sub(0, mul(i, rn)));
		cur.first = add(cur.first, add(sub(0, mul(dp[i - 1].first, p1)), mul(dp[i].first, sub(1, p4))));
		cur.second = add(cur.second, add(sub(0, mul(dp[i - 1].second, p1)), mul(dp[i].second, sub(1, p4))));
		cur.first = mul(cur.first, my_pow(p3, mod - 2));
		cur.second = mul(cur.second, my_pow(p3, mod - 2));
		dp[i + 1] = cur;
	}

	pii cur = dp[n];
	cur.first += mul(m - 1, dp[0].first);
	cur.second += mul(m - 1, dp[0].second);

	int x = mul(sub(0, cur.second), my_pow(cur.first, mod - 2));

	for (int i = 0; i <= n; i++) {
		res[i] = add(mul(dp[i].first, x), dp[i].second);
	}

	int tot = 0;

	for (int i = 0; i < m; i++) {
		tot = add(tot, res[v[i]]);
	}

	cout << tot << endl;
}