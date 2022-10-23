# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000051;
const int P = 1000000007;
const ll INV2 = 500000004;
int t, n, m, k;
ll fac[MAXN], ifac[MAXN], pw[MAXN];
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
ll C(int u, int v){
	if (v < 0 || v > u) return 0;
	return fac[u] * ifac[v] % P * ifac[u - v] % P;
}
int main(){
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i % P;
	ifac[MAXN - 1] = pwr(fac[MAXN - 1], -1);
	for (int i = MAXN - 2; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % P;
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * INV2 % P;
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		if (n == m){
			printf("%lld\n", 1ll * m * k % P);
			continue;
		}
		ll ans = 0;
		for (int i = 1; i <= m; i++){
			ans = (ans + 1ll * i * k % P * C(n - i - 1, m - i) % P * pw[n - i]) % P;
		}
		printf("%lld\n", ans);
	}
	return 0;
}