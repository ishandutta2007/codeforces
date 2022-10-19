#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=998244353;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m, a, ans=1, lst=0;
	cin >> n >> m >> a;
	while(m--) {
		ll p;
		cin >> p;
		ll x=p-lst;
		ll z=pot(a, x);
		z=(z*(z-1))%MOD;
		z=(z*pot(2, MOD-2))%MOD;
		z=(z+pot(a, x))%MOD;
		ans=(ans*z)%MOD;
		lst=p;
	}
	ans=(ans*pot(a, n-2*lst))%MOD;
	cout << ans << '\n';
}