#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

const double EPS = 1e-7;

const int MAXN = 200000;
const int P = 1e9 + 7;

ll fact[MAXN];
ll factRev[MAXN];

ll binPow(ll a, ll b) {
	if (b == 0)
		return 1;
	ll x = binPow(a, b / 2);
	x *= x;
	x %= P;
	if (b & 1) {
		x *= a;
		x %= P;
	}
	return x;
}

ll choose(ll n, ll k) {
	if (k < 0 || k > n)
		return 0;
	ll ans = fact[n];
	ans *= factRev[k];
	ans %= P;
	ans *= factRev[n - k];
	ans %= P;
	return ans;
}


int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("output.txt", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll f, w, h;
	cin >> f >> w >> h;

	if (w == 0) {
		cout << 1 << endl;
		return 0;
	}

	if (f == 0) {
		cout << (w > h) << endl;
		return 0;
	}

	fact[0] = 1;
	for (int i = 1; i < MAXN; ++i) 
		fact[i] = fact[i - 1] * i % P; 

	for (int i = 0; i < MAXN; ++i)
		factRev[i] = binPow(fact[i], P - 2);


	ll p = 0;
	ll q = 0;
	for (int n = 1; n <= f; ++n) {
		ll a = choose(f - 1, n - 1);
		ll b;
		b = 0;
		if (w >= n - 1 && n > 1) {
			b += choose(w - 1, n - 2);
		}
		if (w >= n) {
			b += 2 * choose(w - 1, n - 1);
		}
		if (w >= n + 1) {
			b += choose(w - 1, n);
		}
		b %= P;
		q += a * b;
		q %= P;

		b = 0;

		if (w >= (n - 1) * (h + 1) && n > 1) {
			b += choose(w - h * (n - 1) - 1, n - 2);
		}
		if (w >= n * (h + 1)) {
			b += 2 * choose(w - h * n - 1, n - 1);
		}
		if (w >= (n + 1) * (h + 1)) {
			b += choose(w - h * (n + 1) - 1, n);
		}
		p += a * b;
		p %= P;
	}

	// cout << p << " " << q << endl;
	ll ans = p * binPow(q, P - 2);
	ans %= P;
	cout << ans << endl;
}