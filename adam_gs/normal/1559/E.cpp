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
const int LIM=1e5+7;
const ll MOD=998244353;
ll dp[LIM][57], ans[LIM], lewo[57], prawo[57], pref[LIM];
vector<int>dzielniki[LIM];
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=m; ++i) {
		for(int j=2*i; j<=m; j+=i) {
			dzielniki[j].pb(i);
		}	
	}
	rep(i, n) cin >> lewo[i] >> prawo[i];
	for(int l=1; l<=m; ++l) {
		bool ok=true;
		rep(i, n) {
			if((lewo[i]+l-1)/l>prawo[i]/l || prawo[i]/l==0) ok=false;
		}
		if(!ok) continue;
		dp[0][0]=1;
		int nm=m/l;
		rep(i, n) {
			for(int j=0; j<=m/l; ++j) pref[j]=0;
			rep(j, m/l) {
				int a=(lewo[i]+l-1)/l, b=prawo[i]/l;
				if(j+a<=m/l) pref[j+a]=(pref[j+a]+dp[j][i])%MOD;
				if(j+b+1<=m/l) pref[j+b+1]=(pref[j+b+1]-dp[j][i]+MOD)%MOD;
			}
			ll suma=0;
			for(int j=0; j<=m/l; ++j) {
				suma=(suma+pref[j]+MOD)%MOD;
				dp[j][i+1]=suma;
			}
		}
		for(int j=0; j<=m/l; ++j) ans[l]+=dp[j][n];
	}
	for(int i=m; i>1; --i) {
		for(auto j : dzielniki[i]) {
			ans[j]=(ans[j]-ans[i]+MOD)%MOD;
		}
	}
	cout << ans[1] << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}