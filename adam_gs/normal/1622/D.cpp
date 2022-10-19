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
const ll MOD=998244353;
const int LIM=5e3+7;
ll sil[LIM], osil[LIM];
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
ll c(ll n, ll k) {
	if(k>n) return 0;
	return (((sil[n]*osil[k])%MOD)*osil[n-k])%MOD;
}
void solve() {
	sil[0]=1;
	for(ll i=1; i<LIM; ++i) sil[i]=(sil[i-1]*i)%MOD;
	osil[LIM-1]=pot(sil[LIM-1], MOD-2);
	for(ll i=LIM-2; i>=0; --i) osil[i]=(osil[i+1]*(i+1))%MOD;
	ll n, k;
	string s;
	cin >> n >> k >> s;
	ll ans=0, sum=0, bylo=0, l=0;
	rep(i, n) {
		sum+=s[i]-'0';
		while(sum>k) {
			sum-=s[l]-'0';
			++l;
		}
		if(sum==k) {
			ll zero=i-l+1-sum;
			if(!bylo) {
				bylo=1;
				ans=(ans+c(i-l+1, sum))%MOD;
			} else {
				if(s[i]=='0') {
					ans=(ans+c(i-l, sum-1))%MOD;
				} else {
					ans=(ans+c(i-l, sum))%MOD;
				}
			}
		}
	}
	if(!bylo) ans=1;
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}