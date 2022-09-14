/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define uint unsigned int

using namespace std;

const int maxn = (int)2e5 + 10, mod = (int)1e9 + 7;
int v[maxn];

ll f[maxn], rf[maxn];

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return a * my_pow(a, b - 1) % mod;
	}

	ll z = my_pow(a, b >> 1);

	return z * z % mod;
}

ll C(int n, int k) {
	return (f[n] * rf[k] % mod) * rf[n - k] % mod;
}

int main() {
	f[0] = 1;
	rf[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = f[i - 1] * i;
		f[i] %= mod;
		rf[i] = my_pow(f[i], mod - 2);
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	if (n == 1) {
		cout << v[0] << endl;
		return 0;
	}

	if (n % 2 == 1) {
		int z = 1;
		for (int i = 0; i < n - 1; i++) {
			v[i] += z * v[i + 1];
			v[i] %= mod;

			if (v[i] < 0) {
				v[i] += mod;
			}

			z *= -1;
		}

		n--;
	}

	int z = n / 2 - 1;

	ll a[2];

	memset(a, 0, sizeof a);

	for (int i = 0; i < n; i++) {
		a[i % 2] += C(z, i / 2) * v[i];
		a[i % 2] %= mod;

		if (a[i % 2] < 0) {
			a[i % 2] += mod;
		}
	}

	if (n % 4 == 2) {
		cout << (a[0] + a[1]) % mod << endl;
	} else {
		ll ans = a[0] - a[1];

		if (ans < 0) {
			ans += mod;
		}

		cout << ans << endl;
	}

	return 0;
}