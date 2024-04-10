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

const int maxn = (int)2e5 + 10;
char s[maxn];

const int mod = 998244353;

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
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

int f[maxn], rf[maxn];

int C(int n, int k) {
	return mul(mul(f[n], rf[n - k]), rf[k]);
}

int main() {
	f[0] = rf[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = mul(f[i - 1], i);
		rf[i] = my_pow(f[i], mod - 2);
		assert(mul(f[i], rf[i]) == 1);
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		scanf("%s", s);

		int z = 0;
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				z++;
				continue;
			}

			if (i == n - 1 || s[i + 1] == '0') {
				continue;
			}

			cnt++;
			i++;
		}

		if (cnt == 0) {
			cout << 1 << '\n';
			continue;
		}

		int ans = 0;
		for (int i = 0; i <= z; i++) {
			ans = add(ans, C(cnt + i - 1, i));
		}

		cout << ans << '\n';
	}
}