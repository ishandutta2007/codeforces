//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 2010, mod = 998244353;
int dp[maxn][maxn][2];
int st[maxn];
int cnt[maxn];

int get_sum(int l, int r) {
	return (l == 0 ? cnt[r] : cnt[r] - cnt[l - 1]);
}

string s;

int go(int l, int r, int le) {
	if (dp[l][r][le] != -1) {
		return dp[l][r][le];
	}

	if (l >= r) {
		return dp[l][r][le] = 0;
	}

	if (s[l] == ')') {
		return dp[l][r][le] = go(l + 1, r, le);
	}

	if (s[r] == '(') {
		return dp[l][r][le] = go(l, r - 1, le);
	}

	int ans = 0;

	if (s[l] == '?' && le == 0) {
		ans = go(l + 1, r, le);
	}

	if (s[r] == ')') {
		ans += go(l + 1, r - 1, 0);
		if (ans >= mod) {
			ans -= mod;
		}
		ans += st[get_sum(l + 1, r - 1)];
		if (ans >= mod) {
			ans -= mod;
		}
	}
	else {
		ans += go(l + 1, r - 1, 0);
		if (ans >= mod) {
			ans -= mod;
		}

		ans += st[get_sum(l + 1, r - 1)];
		if (ans >= mod) {
			ans -= mod;
		}

		ans += go(l, r - 1, 1);
		if (ans >= mod) {
			ans -= mod;
		}
	}

	return dp[l][r][le] = ans;
}

int main() {
	st[0] = 1;

	for (int i = 1; i < maxn; i++) {
		st[i] = (ll)st[i - 1] * 2 % mod;
	}

	cin >> s;

	memset(dp, -1, sizeof dp);
	int n = (int)s.size();

	int cur = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			cur++;
		}

		cnt[i] = cur;
	}

	cout << go(0, n - 1, 0) << endl;

	//system("pause");
}