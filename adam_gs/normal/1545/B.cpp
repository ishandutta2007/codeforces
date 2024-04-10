#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
const ll MOD=998244353;
const int LIM=1e5+7;
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
	ll ans=sil[n];
	ans=(ans*osil[k])%MOD;
	ans=(ans*osil[n-k])%MOD;
	return ans;
}
void solve() {
	int n;
	string x;
	cin >> n >> x;
	int pary=0, wolne=0;
	rep(i, n-1) {
		if(x[i]=='1' && x[i+1]=='1') {
			x[i]=x[i+1]='0';
			++pary;
		}
	}
	rep(i, n) if(x[i]=='0') ++wolne;
	/*ll dp[wolne+1][pary+1];
	rep(i, wolne+1) rep(j, pary+1) dp[i][j]=0;
	rep(i, wolne+1) dp[i][0]=1;
	for(int i=2; i<=wolne; ++i) for(int j=1; j<=pary; ++j) {
		dp[i][j]=(dp[i-1][j]+dp[i-2][j-1])%MOD;
	}*/
	cout << c(wolne-pary, pary) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=osil[0]=1;
	for(ll i=1; i<LIM; ++i) {
		sil[i]=(sil[i-1]*i)%MOD;
		osil[i]=pot(sil[i], MOD-2);
	}
	int _=1;
	cin >> _;
	while(_--) solve();
}