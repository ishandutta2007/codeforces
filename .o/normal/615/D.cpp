#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M_ = 200500;
const ll MOD = (ll)1e9 + 7;
int M; map<int, int> D;

ll power (ll a, ll b) {
	ll ret = 1;
	while(b > 0) {
		if(b & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &M);
	while(M--) {
		int p; scanf("%d", &p);
		++D[p];
	}
	
	ll ans = 1, num = 1;
	for(auto x : D) {
		int p = x.first, q = x.second;
		ll s = 1, t = 1;
		for(int i = 0; i <= q; i++) {
			s = (s * t) % MOD; 
			t = (t * p) % MOD;
		}
		ans = (power(ans, q + 1) * power(s, num)) % MOD;
		num = (num * (q + 1)) % (MOD - 1);
	}
	// 1*2*4
	
	// (1*2*4)*(1*2*4*3)*(1*2*4*9)
	printf("%lld\n", ans);
	return 0;
}