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
const int LIM=1e3+7;
const ll MOD=1e9+7;
ll lewo[LIM][LIM]; 
ll prawo[LIM][LIM];
void solve() {
	int n, k;
	cin >> n >> k;
	rep(i, n) rep(j, k) lewo[i][j]=prawo[i][j]=0;
	prawo[0][0]=1;
	ll ans=0;
	rep(j, k) {
		ll pref=0;
		rep(i, n) {
			pref=(pref+prawo[i][j])%MOD;
			lewo[i][j+1]=pref;
		}
		ans=(ans+pref)%MOD;
		pref=0;
		for(int i=n-1; i>0; --i) {
			pref=(pref+lewo[i][j])%MOD;
			prawo[i][j+1]=pref;
		}
		ans=(ans+pref+lewo[0][j])%MOD;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}