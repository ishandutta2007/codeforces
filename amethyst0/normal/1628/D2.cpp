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
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int mod = (int)1e9 + 7;
int r2 = (mod + 1) / 2;

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

const int maxn = (int)1e6 + 10;
int f[maxn], rf[maxn];
int st[maxn];

int C(int n, int m) {
	return mul(mul(f[n], rf[n - m]), rf[m]);
}

int main() {
	f[0] = 1;
	st[0] = 1;
	for (int i = 1; i < maxn; i++) {
		f[i] = mul(f[i - 1], i);
		st[i] = mul(st[i - 1], r2);
	}
	rf[maxn - 1] = my_pow(f[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--) {
		rf[i] = mul(rf[i + 1], i + 1);
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		int ans = 0;

		if (n != m) {
			for (int i = 1; i <= m; i++) {
				int cur = st[n - i];
				cur = mul(cur, i);
				cur = mul(cur, f[n - 1 - i]);
				cur = mul(cur, rf[m - i]);
				ans = add(ans, cur);
			}
			ans = mul(ans, rf[n - m - 1]);
		}
		else {
			ans = m;
		}
		printf("%d\n", mul(ans, k));
	}
}