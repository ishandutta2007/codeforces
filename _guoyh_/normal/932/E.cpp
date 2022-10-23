# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 5005;
const int P = 1e9 + 7;
int n, k;
ll fac[MAXN], ifac[MAXN];
ll s[MAXN][MAXN];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
ll C(ll x, ll y){
	if (y < 0 || y > x) return 0;
	return fac[x] * ifac[y] % P * ifac[x - y] % P;
}
int main(){
	scanf("%d%d", &n, &k);
	s[0][0] = 1;
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= i; j++){
			s[i][j] = (s[i - 1][j - 1] + s[i - 1][j] * j) % P;
		}
	}
	fac[0] = ifac[0] = 1;
	for (int i = 1; i <= k; i++){
		fac[i] = fac[i - 1] * i % P;
		ifac[i] = pwr(fac[i], P - 2);
	}
	ll ans = 0;
	ll cni = 1;
	for (int i = 1; i <= k && i <= n; i++){
		cni = cni * (n - i + 1) % P;
		ans = (ans + fac[i] * s[k][i] % P * cni % P * ifac[i] % P * pwr(2, n - i)) % P;
		// printf("i %d\n", i);
	}
	printf("%lld\n", ans);
	return 0;
}