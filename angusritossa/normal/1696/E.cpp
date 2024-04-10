#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
#define MAXN 500010
#define MOD 1000000007
typedef long long ll;
ll fastmult(ll n, ll k) {
	if (!k) return 1;
	ll ans = fastmult(n, k/2);
	ans *= ans;
	ans %= MOD;
	if (k%2) {
		ans *= n;
		ans %= MOD;
	}
	return ans;
}
ll factorial[MAXN], ans;

int main() {
	factorial[0] = 1;
	for (ll i = 1; i < MAXN; i++) {
		factorial[i] = (factorial[i-1]*i)%MOD;
	}
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n+1; i++) {
		int a;
		scanf("%d", &a);
		if (!a) break;
		ll am = factorial[a+i-1];
		am *= fastmult((factorial[a-1]*factorial[i])%MOD, MOD-2);
		am %= MOD;
		ans += am;
		ans %= MOD;
	}
	printf("%lld\n", ans);
}