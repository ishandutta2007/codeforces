#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
#define lg(a) (a?31-__builtin_clz(a):0)
const ll MOD=998244353;
ll ile[30][30], dp[1<<23], mi[1<<23];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin >> n;
	rep(i, n) {
		string x;
		cin >> x;
		for(auto j : x) ++ile[i][j-'a'];
	}
	for(ll i=1; i<(1<<n); ++i) dp[i]=1;
	rep(i, 26) {
		rep(j, 1<<n) mi[j]=MOD;
		for(ll j=1; j<(1<<n); ++j) mi[j]=min(mi[j^(1<<lg(j))], ile[lg(j)][i]);
		for(ll j=1; j<(1<<n); ++j) dp[j]=(dp[j]*(mi[j]+1))%MOD;
	}
	rep(i, 1<<n) if(__builtin_popcount(i)%2==0) dp[i]*=-1;
	rep(i, n) rep(j, 1<<n) if(j&(1<<i)) dp[j]=(dp[j]+dp[j^(1<<i)]+MOD)%MOD;
	ll ans=0;
	rep(i, 1<<n) {
		ll p=0, k=0;
		rep(j, n) if(i&(1<<j)) {
			p+=j+1;
			++k;
		}
		p*=k;
		ans^=dp[i]*p;
	}
	cout << ans << '\n';
}