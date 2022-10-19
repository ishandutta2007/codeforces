#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
typedef long long ll;
#define MOD 1000000007
int n;
ll num_odd;
ll num_even[50];
ll p2(ll a) {
	int ans = 0;
	while (a%2 == 0) {
		ans++;
		a /= 2;
	}
	return ans;
}
ll power_of_2[200010];
ll ans;
int main() {
	scanf("%d", &n);
	power_of_2[0] = 1;
	for (int i = 1; i < 200010; i++) {
		power_of_2[i] = (2*power_of_2[i-1])%MOD;
	}
	for (int j = 0; j < n; j++) {
		ll a;
		scanf("%lld", &a);
		ll p = p2(a);
		if (!p) num_odd++;
		else num_even[p]++;
	}
	ll tot_even = n-num_odd;
	ans = (power_of_2[num_odd]-1)*power_of_2[tot_even];
	//printf("%lld\n", ans);
	//printf("%lld %lld\n", num_odd, tot_even);
	ans %= MOD;
	for (int i = 0; i < 35; i++) {
		tot_even -= num_even[i];
		if (num_even[i]) {
			ll am = power_of_2[tot_even]*(power_of_2[num_even[i]-1]-1);
			am %= MOD;
			ans += am;
		}	
	}
	ans %= MOD;
	printf("%lld\n", ans);
}