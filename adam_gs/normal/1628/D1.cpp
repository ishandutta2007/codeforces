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
const int LIM=2e3+7;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
ll dp[LIM][LIM];
void solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	rep(i, n+1) rep(j, m+1) dp[i][j]=0;
	for(int i=1; i<=n; ++i) {
		dp[i][i]=(dp[i-1][i-1]+k)%MOD;
		for(int j=1; j<i && j<=m; ++j) {
			ll x=(dp[i-1][j]-dp[i-1][j-1]+MOD)%MOD;
			x=(x*pot(2, MOD-2))%MOD;
			dp[i][j]=(dp[i-1][j-1]+x)%MOD;
		}
	}
	cout << dp[n][m] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}