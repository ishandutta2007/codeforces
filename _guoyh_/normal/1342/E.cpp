# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int P = 998244353;
int n;
ll k;
ll ans;
ll fac[MAXN], ifac[MAXN];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
ll C(int x, int y){
	if (y < 0 || y > x) return 0;
	return fac[x] * ifac[y] % P * ifac[x - y] % P;
}
int main(){
	scanf("%d%lld", &n, &k);
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= n; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwr(fac[i], P - 2);
	}
	if (k == 0){
		printf("%lld\n", fac[n]);
		return 0;
	}
	if (k >= n){
		printf("0\n");
		return 0;
	}
	k = n - k;
	for (int i = 0; i <= k; i++){
		ll nw = C(k, i) * pwr(k - i, n) % P;
		if (i & 1) ans = (ans - nw) % P;
		else ans = (ans + nw) % P;
	}
	ans = 2 * C(n, k) % P * ans % P;
	printf("%lld\n", (ans + P) % P);
	return 0;
}