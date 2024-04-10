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
ll pot(ll a, ll b, bool t) {
	ll ans=1;
	while(b) {
		if(b&1) {
			ans*=a;
			if(t) ans%=MOD;
		}
		a*=a;
		if(t) a%=MOD;
		b/=2;
	}
	return ans;
}
void solve() {
	ll n;
	cin >> n;
	ll x=pot(2, n, false)-1;
	ll p=pot(2, x, true);
	ll dp[n];
	dp[0]=1;
	for(int i=1; i<n; ++i) {
		dp[i]=(2*dp[i-1])%MOD;
		dp[i]=(dp[i]*dp[i])%MOD;
	}
	dp[n-1]=(dp[n-1]*3)%MOD;
	dp[n-1]=(dp[n-1]*p)%MOD;
	cout << dp[n-1] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}