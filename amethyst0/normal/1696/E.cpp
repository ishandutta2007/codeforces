#pragma comment(linker, "/STACK:1000000000")
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
#include <unordered_set>

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

int main() {
	int n;
	scanf("%d", &n);

	int prev = -1;
	int val = 0;
	int ans = 0;

	for (int i = 0; i <= n; i++) {
		int x;
		scanf("%d", &x);

		if (i == 0) {
			ans = x;
			prev = x;
			val = x;
			continue;
		}

		val = mul(val, prev + i);
		val = mul(val, my_pow(i + 1, mod - 2));
		while (prev != x) {
			val = mul(val, my_pow(prev + i, mod - 2));
			prev--;
			val = mul(val, prev);
		}
		ans = add(ans, val);
	}
	cout << ans << '\n';
}