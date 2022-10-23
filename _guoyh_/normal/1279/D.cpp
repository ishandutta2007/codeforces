# include <cstdio>
# include <cstring>
# include <iostream>
# include <algorithm>
# define ll long long
using namespace std;
const ll NR = 1000051;
const ll PR = 998244353;
ll n, mx, tol;
ll k[NR], a[NR], flag[NR];
ll p[NR];
ll pwr(ll x, ll y){
	ll ans = 1;
	x = x % PR;
	while (y){
		if (y & 1) ans = ans * x % PR;
		x = x * x % PR;
		y >>= 1;
	}
	return ans % PR;
}
int main(){
	cin>>n;
	for (ll i = 1; i <= n; i++){
		cin>>k[i];
		for (ll j = 1; j <= k[i]; j++){
			ll x;
			cin>>x;
			mx = max(mx, x);
			if (flag[x] != i){
				a[x]++;
				flag[x] = i;
			}
			p[x] = (p[x] + pwr((ll)n * k[i], PR - 2)) % PR;
		}
	}
	for (ll i = 1; i <= mx; i++)
		tol = ((ll)tol + (p[i] * pwr(n, PR - 2) % PR) * a[i] % PR) % PR;
	cout<<tol<<endl;
	return 0;
}