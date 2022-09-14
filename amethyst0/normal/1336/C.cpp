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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = 3010, mod = 998244353;

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

int dp[maxn][maxn];
string s, t;

int go(int l, int r) {
	if (l == r) {
		if (t[l] == s[0]) {
			dp[l][r] = 2;
		}
		else {
			dp[l][r] = 0;
		}

		return dp[l][r];
	}

	if (dp[l][r] != -1) {
		return dp[l][r];
	}

	int d = r - l;

	int ans = 0;

	if (s[d] == t[l]) {
		ans = go(l + 1, r);
	}

	if (s[d] == t[r]) {
		ans += go(l, r - 1);
		if (ans >= mod) {
			ans -= mod;
		}
	}

	return dp[l][r] = ans;
}

int st[maxn];

int dp1[maxn][maxn];

int go1(int pt, int ps) {
	if (pt == (int)t.size()) {
		return st[ps + 1];
	}

	if ((int)t.size() - pt == ps + 1) {
		return dp1[pt][ps] = go(pt, (int)t.size() - 1);
	}
	
	if (dp1[pt][ps] != -1) {
		return dp1[pt][ps];
	}

	int ans = go1(pt, ps - 1);
	
	if (s[ps] == t[pt]) {
		ans = add(ans, go1(pt + 1, ps - 1));
	}

	return dp1[pt][ps] = ans;
}

int main() {
	memset(dp1, -1, sizeof dp1);
	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = mul(st[i - 1], 2);
	}

	memset(dp, -1, sizeof dp);
	cin >> s;
	cin >> t;

	int n = (int)t.size();

	int ans = 0;

	ans = mul((int)s.size() - n + 1, go(0, n - 1));
	
	for (int i = (int)t.size(); i < (int)s.size(); i++) {
		if (s[i] == t[0]) {
			ans = add(ans, mul((int)s.size() - i, go1(1, i - 1)));
		}
	}

	cout << ans << '\n';
}