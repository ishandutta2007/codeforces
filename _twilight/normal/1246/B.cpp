#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 1e5 + 5;

#define ll unsigned long long

ll qpow(ll x, int pos) {
	if (pow(x, pos) > 1e11)
		return 1e11;
	ll rt = 1;
	for ( ; pos; pos >>= 1, x *= x)
		if (pos & 1)
			rt *= x;
	return rt;
}

int n, K;
map<ll, int> G;

int main() {
	scanf("%d%d", &n, &K);
	ll ans = 0;
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		ll rt1 = 1, rt2 = 1;
		double drt = 1;
		for (int p = 2; p * p <= x; p++) {
			if (!(x % p)) {
				int pos = 0;
				while (!(x % p))
					x /= p, pos++;
				pos %= K;
				rt1 *= qpow(p, pos);
				pos = (K - pos) % K;
				rt2 *= qpow(p, pos);
				drt *= qpow(p, pos);
			}
		}
		if (x > 1) {
			rt1 *= x;
			rt2 *= qpow(x, K - 1);
			drt *= qpow(x, K - 1);
		} 
//		cerr << rt1 << " " << rt2 << '\n'9;
		if (drt < 1e11) {
			ans += G[rt2];	
		}
		G[rt1]++;
	}
	printf("%llu\n", ans);
	return 0;
}