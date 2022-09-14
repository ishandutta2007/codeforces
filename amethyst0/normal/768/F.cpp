/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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
#define ld long double
#define pii pair <int, int>
#define mp make_pair
#define tm tmmm

using namespace std;

const int maxn = (int)1e5 + 10;
const int mod = (int)1e9 + 7;

ll z[maxn];
ll y[maxn];

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (a * my_pow(a, b - 1)) % mod;
	}

	ll t = my_pow(a, b >> 1);

	return (t * t) % mod;
}

ll fac[4 * maxn];
ll rf[4 * maxn];

int main() {
	ll t = 1;
	
	for (int i = 0; i < 4 * maxn; i++) {
		fac[i] = t;
		rf[i] = my_pow(t, mod - 2);
		t *= (i + 1);
		t %= mod;
	}

	int f, w, h;

	cin >> f >> w >> h;

	if (w == 0) {
		cout << 1 << endl;
		return 0;
	}

	if (w <= h) {
		cout << 0 << endl;
		return 0;
	}

	if (f == 0) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i <= f; i++) {
		z[i] = fac[f - 1] * rf[f - i];
		z[i] %= mod;
		z[i] *= rf[i - 1];
		z[i] %= mod;
	}

	h++;

	ll ans = 0;
	ll g = 0;

	for (int i = 1; i <= (w / h); i++) {
		y[i] = rf[w - h * i] * fac[i + w - h * i - 1];
		y[i] %= mod;

		y[i] *= rf[i - 1];
		y[i] %= mod;

		ans += y[i] * (z[i - 1] + 2 * z[i] + z[i + 1]);
		ans %= mod;
	}

	for (int i = 1; i <= w; i++) {
		ll r = fac[w - 1] * rf[w - i];
		r %= mod;
		r *= rf[i - 1];
		r %= mod;
		g += r * (z[i - 1] + 2 * z[i] + z[i + 1]);
		g %= mod;
	}

	cout << (ans * my_pow(g, mod - 2)) % mod << endl;

	return 0;
}