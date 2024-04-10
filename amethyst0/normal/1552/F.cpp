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
#include <cstdio>
#include <cassert>
#include <cstring>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;

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

int dp[maxn];
int sum[maxn];

int go(int l, int r) {
	return (l == 0 ? sum[r] : sub(sum[r], sum[l - 1]));
}

struct vt {
	int x, y, s;
	int lnk;

	vt() {}

	vt(int x, int y, int s): x(x), y(y), s(s), lnk(-1) {}
};

bool operator <(const vt &a, const vt &b) {
	return a.x < b.x;
}

vt v[maxn];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &v[i].x, &v[i].y, &v[i].s);
	}

	sort(v, v + n);

	for (int i = 0; i < n; i++) {
		int pos = lower_bound(v, v + n, vt(v[i].y, v[i].y, 0)) - v;
		v[i].lnk = pos;
	}

	int ans = v[0].x % mod;

	for (int i = 0; i < n; i++) {
		int to = v[i].lnk;

		int d = (i == n - 1 ? 1 : (v[i + 1].x - v[i].x) % mod);
		int dd = d;
		d = add(d, (v[to].x - v[i].y) % mod);
		if (to != i) {
			d = add(d, go(to, i - 1));
		}

		dp[i] = d;
		sum[i] = add(dp[i], (i == 0 ? 0 : sum[i - 1]));
		if (v[i].s) {
			ans = add(ans, dp[i]);
		}
		else {
			ans = add(ans, dd);
		}
	}

	printf("%d\n", ans);
}