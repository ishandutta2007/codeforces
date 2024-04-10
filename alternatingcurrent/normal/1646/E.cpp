#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

ll n, m;
ll maxpow[1010];
bool done[1111111];
ll maskpro[1111111];
int getval(int l, int r, ll x){
	ll ans = 0;
	for(int mask = 1; mask < 1 << (r - l + 1); mask++)
		ans += (__builtin_popcount(mask) & 1) ? (x / maskpro[mask << (l - 1)]) : -(x / maskpro[mask << (l - 1)]);
//	cout << l << " " << r << " " << x << ": " << ans << endl;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 2; i <= 1000; i++){
		maxpow[i] = 0;
		int nown = n / i;
		while(nown)
			maxpow[i]++, nown /= i;
	}
	rep(mask, 1 << 20){
		maskpro[mask] = 1;
		rep(i, 20)
			if(mask & (1 << i)){
				ll g = __gcd(maskpro[mask], (ll)(i + 1));
				maskpro[mask] /= g;
				maskpro[mask] *= (ll)(i + 1);
			}
	}
	ll ans = (n - 1) * m + 1;
	for(ll i = 2; i <= 1000; i++){
		if(done[i])
			continue;
		ll allsum = 0;
		ans -= maxpow[i] * m;
		for(int j = 1; j <= maxpow[i]; j++)
			allsum += getval(j, maxpow[i], j * m) - getval(j, maxpow[i], (j - 1) * m);
		ans += allsum;
		ll nowval = i;
		while(nowval <= n){
			done[nowval] = 1;
			nowval *= i;
		}
//		cout << i << " " << maxpow[i] << ": " << "-" << maxpow[i] * m << " +" << allsum << endl;
	}
	cout << ans << endl;
	return 0;
}