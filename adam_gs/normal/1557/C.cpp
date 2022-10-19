#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
const int LIM=2e5+7;
ll sil[LIM], osil[LIM];
ll C(ll n, ll k) {
	return (((sil[n]*osil[k])%MOD)*osil[n-k])%MOD;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	ll s=0, p=1, ans=0;
	rep(i, n) {
		s=(s+C(n, i))%MOD;
		++i;
	}
	if(n%2==1) s=(s+1)%MOD;
	rep(i, k) {
		if(n%2==0) {
			ans=(ans+(p*pot(pot(2, k-i-1), n)))%MOD;
		}
		p=(p*s)%MOD;
	}
	ans=(ans+p)%MOD;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=osil[0]=1;
	for(ll i=1; i<LIM; ++i) {
		sil[i]=(sil[i-1]*i)%MOD;
		osil[i]=pot(sil[i], MOD-2);
	}
	int _;
	cin >> _;
	while(_--) solve();
}