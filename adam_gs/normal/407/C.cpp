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
const int LIM=1e5+7, K=107;
ll pref[LIM][K], sil[LIM], osil[LIM];
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
ll C(ll n, ll k) {
	if(k>n) return 0;
	return (((sil[n]*osil[k])%MOD)*osil[n-k])%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=osil[0]=1;
	for(ll i=1; i<LIM; ++i) {
		sil[i]=(sil[i-1]*i)%MOD;
		osil[i]=pot(sil[i], MOD-2);
	}
	int n, m;
	cin >> n >> m;
	rep(i, n) {
		ll a;
		cin >> a;
		pref[i][K-1]=(pref[i][K-1]+a)%MOD;
		pref[i+1][K-1]=(pref[i+1][K-1]-a+MOD)%MOD;
	}
	while(m--) {
		int l, r, k;
		cin >> l >> r >> k; --l; --r;
		pref[l][K-1-k]=(pref[l][K-1-k]+1)%MOD;
		ll x=r-l+1;
		rep(i, k+1) pref[r+1][K-1-k+i]=(pref[r+1][K-1-k+i]-C(x-1+i, i)+MOD)%MOD;
	}
	for(int i=1; i<K; ++i) {
		rep(j, n) {
			if(j) pref[j][i]=(pref[j][i]+pref[j-1][i])%MOD;
			pref[j][i]=(pref[j][i]+pref[j][i-1])%MOD;
		}
	}
	rep(i, n) cout << pref[i][K-1] << " ";
	cout << '\n';
}