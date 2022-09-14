/*AMETHYSTS*/
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

const ll inf = (int)1e9;

ll my_pow(ll a, int b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		ll z = my_pow(a, b - 1) * a;
		if (z > inf) {
			z = inf;
		}

		return z;
	}

	ll g = my_pow(a, b >> 1);
	g *= g;
	if (g >= inf) {
		g = inf;
	}

	return g;
}

const int maxn = (int)1e7 + 10;
int llm[maxn], rrm[maxn];

int main() {
	int n, l, r;

	cin >> n >> l >> r;

	if (n == 1) {
		cout << r - l + 1 << endl;
		return 0;
	}

	if (n >= 30) {
		cout << 0 << endl;
		return 0;
	}

	if (n == 2) {
		ll cnt = r - l + 1;

		cout << cnt * (cnt - 1) << endl;
		return 0;
	}

	ll ans = 0;

	for (int i = 1; i < maxn; i++) {
		for (int j = 1; ; j++) {
			ll z = my_pow(j, n - 1);

			if (z * i > r) {
				break;
			}

			rrm[i] = j;
			if (z * i >= l && llm[i] == 0) {
				llm[i] = j;
			}
		}
	}

	for (int x = 1; x <= 10000; x++) {
		if (my_pow(x, n - 1) > r) {
			break;
		}

		ll g = my_pow(x, n - 1);

		for (ll f = 1, i = g; i <= r; f++, i += g) {
			if (i < l) {
				continue;
			}

			int lm = llm[f];
			int rm = rrm[f];

			if (lm == 0) {
				continue;
			}

			if (x != 1) {
				for (int j = lm; j <= rm; j++) {
					if (gcd(j, x) == 1) {
						ans++;
					}
				}
			} else {
				ans += rm - lm + 1;
				if (lm == 1) {
					ans--;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}