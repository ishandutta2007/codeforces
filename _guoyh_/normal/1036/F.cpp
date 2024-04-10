# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll INF = 1000000000000000051;
int t;
ll n;
int mu[61];
ll pwr(ll x, ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = INF / ans >= x ? ans * x : INF;
		x = INF / x >= x ? x * x : INF;
		y >>= 1;
	}
	return ans;
}
int main(){
	for (int i = 2; i <= 60; i++){
		int x = i;
		mu[i] = 1;
		for (int j = 2; j * j <= x; j++){
			if (x % j) continue;
			if (x % (j * j) == 0){
				mu[i] = 0;
				break;
			}
			x /= j;
			mu[i] = -mu[i];
		}
		if (x > 1) mu[i] = -mu[i];
		// printf("mu %d %d\n", i, mu[i]);
	}
	scanf("%d", &t);
	while (t--){
		scanf("%lld", &n);
		ll ans = n - 1;
		for (int d = 2; d <= 60; d++){
			ll nm = (ll)(pow(n, 1.0 / d));
			while (pwr(nm + 1, d) <= n) nm++;
			while (pwr(nm, d) > n) nm--;
			ans += mu[d] * (nm - 1);
			// printf("ans %lld %lf\n", ans, pow(n, 1.0 / d));
		}
		printf("%lld\n", ans);
	}
	return 0;
}