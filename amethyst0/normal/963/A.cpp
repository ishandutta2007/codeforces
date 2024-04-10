#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld long double

using namespace std;

const int mod = (int)1e9 + 9;

int my_pow(int a, int b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (ll)a * my_pow(a, b - 1) % mod;
	}

	ll z = my_pow(a, b >> 1);

	return z * z % mod;
}

ll go(ll x, int n) {
	if (n == 1) {
		return 1;
	}

	if (n & 1) {
		return (1 + x * go(x, n - 1)) % mod;
	}

	ll z = go(x, n >> 1);

	return z * (1 + my_pow(x, n >> 1)) % mod;
}

int main() {
	int n, k, a, b;

	cin >> n >> a >> b >> k;

	ll ans = 0;

	int ra = my_pow(a, mod - 2);

	int x = (ll)b * ra % mod;

	int st = 1;

	for (int i = 0; i < k; i++) {
		char c;
		scanf(" %c", &c);

		if (c == '+') {
			ans += st;

			if (ans >= mod) {
				ans -= mod;
			}
		}
		else {
			ans -= st;

			if (ans < 0) {
				ans += mod;
			}
		}

		st = (ll)st * x % mod;
	}

	ans = ans * go(st, (n + 1) / k) % mod;

	ans = ans * my_pow(a, n) % mod;

	cout << ans << endl;

	//system("pause");
}