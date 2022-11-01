#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

ll f, w, h, fac[N], ifac[N];

ll bigMod (ll a, ll e) {
	if (e == -1) e = MOD - 2;
	ll r = 1; while (e) {
		if (e & 1) r = (r * a) % MOD;
		a = (a * a) % MOD;
		e >>= 1;
	}
	return r;
}

ll nCr (ll n, ll k) {
	if (n < 0 or k < 0 or n < k) return 0;
	ll res = fac[n];
	res = (res * ifac[k]) % MOD;
	res = (res * ifac[n - k]) % MOD;
	return res;
}

int main (int argc, char const *argv[]) {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (ll) i * fac[i - 1];
		fac[i] %= MOD;
		ifac[i] = bigMod(fac[i], -1);
	}
	// cout << nCr(1, 0) << endl;
	cin >> f >> w >> h;
	if (w == 0) {
		puts("1");
		return 0; 
	}
	if (f == 0) {
		puts(w > h ? "1" : "0");
		return 0;
	}
	ll down = 0;
	for (int l = 0; l <= f + w; ++l) {
		int x = l + 1 >> 1, y = l - x;
		// cout << x << " " << y << endl;
		// cout << "ok: " << f - 1 << "," << x - 1 << "    " << w - 1 << "," << y - 1 << endl;
		// cout << "yo: " << nCr(f - 1, x - 1) << " " << nCr(w - 1, y - 1) << endl;
		down += nCr(f - 1, x - 1) * nCr(w - 1, y - 1);
		// cout << down << endl;
		down %= MOD;
		down += nCr(w - 1, x - 1) * nCr(f - 1, y - 1);
		down %= MOD;
	}
	ll up = 0;
	for (int l = 0; l <= f + w; ++l) {
		int x = l + 1 >> 1, y = l - x;
		ll nw = w - h * y;
		up += nCr(f - 1, x - 1) * nCr(nw - 1, y - 1);
		up %= MOD;
		nw = w - h * x;
		up += nCr(nw - 1, x - 1) * nCr(f - 1, y - 1);
		up %= MOD; 
	}
	// cout << up << " " << down << endl;
	ll ans = (up * bigMod(down, -1)) % MOD;
	printf("%lld\n", ans);
	return 0;
}