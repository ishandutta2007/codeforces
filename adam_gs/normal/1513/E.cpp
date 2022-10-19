#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
const int LIM=1e5+7;
ll sil[LIM], osil[LIM], T[LIM];
map<ll,ll>ile;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b%2==1) ans=(ans*a)%MOD;
		b/=2;
		a=(a*a)%MOD;
	}
	return ans;
}
ll C(ll n, ll k) {
	ll ans=(sil[n]*osil[k])%MOD;
	ans*=osil[n-k];
	return ans%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=osil[0]=1;
	for(ll i=1; i<LIM; ++i) {
		sil[i]=(sil[i-1]*i)%MOD;
		osil[i]=pot(sil[i], MOD-2);
	}
	ll n;
	cin >> n;
	ll sum=0;
	rep(i, n) {
		cin >> T[i];
		sum+=T[i];
	}
	if(sum%n) {
		cout << 0 << '\n';
		return 0;
	}
	sum/=n;
	ll ilezer=0, ilemalych=0, ileduzych=0;
	rep(i, n) {
		if(sum-T[i]==0) ++ilezer;
		if(sum-T[i]<0) ++ilemalych;
		if(sum-T[i]>0) ++ileduzych;
		++ile[T[i]];
	}
	ll ans=1;
	if(min(ilemalych, ileduzych)==1) {
		ans=sil[ilemalych+ileduzych];
	} else if(max(ilemalych, ileduzych)>0) {
		ans=sil[ilemalych]*sil[ileduzych];
		ans%=MOD;
		ans*=2;
		ans%=MOD;
	}
	ans=(ans*C(n, ilezer))%MOD;
	ans=(ans*sil[ilezer])%MOD;
	rep(i, n) {
		if(ile[T[i]]) {
			ans*=osil[ile[T[i]]];
			ans%=MOD;
		}
		ile[T[i]]=0;
	}
	cout << ans << '\n';
}