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

const int maxn = (int)1e6 + 10;

const int mod = 998244353;

int cnt[maxn];
int dp[maxn];

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int main() {
	for (int i = 1; i < maxn; i++) {
		for (int j = i; j < maxn; j += i) {
			cnt[j]++;
		}
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = add(dp[i - 1], cnt[i]);
		if (i != n) {
			dp[i] = add(dp[i], dp[i - 1]);
		}
	}

	cout << dp[n] << '\n';
}