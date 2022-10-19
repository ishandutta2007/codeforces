#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int MAXN=207, MAXM=1e5+7, INF=1e9+7;
ll dp[MAXN][MAXM], kubelki[MAXM], wjakim[MAXM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n, m;
	cin >> n >> m;
	rep(i, n+1) rep(j, m+1) dp[i][j]=INF;
	dp[0][0]=0;
	for(ll i=1; i<=n; ++i) {
		rep(j, m+1) {
			wjakim[j]=INF;
			kubelki[j]=0;
		}
		ll t, x, y;
		cin >> t >> x >> y;
		rep(j, m+1) dp[i][j]=dp[i-1][j];
		if(t==1) {
			x=(x+99999)/100000;
			rep(j, x) {
				rep(l, y+1) {
					if(j+l*x>m) break;
					if(dp[i-1][j+l*x]<INF) ++kubelki[j];
					if(kubelki[j] && dp[i][j+l*x]==INF) dp[i][j+l*x]=i;
				}
			}
			for(ll j=(y+1)*x; j<=m; ++j) {
				if(dp[i-1][j]<INF) ++kubelki[j%x];
				if(dp[i-1][j-(y+1)*x]<INF) --kubelki[j%x];
				if(kubelki[j%x] && dp[i][j]==INF) dp[i][j]=i;
			}
		} else {
			rep(j, m+1) if(wjakim[j]==INF) {
				if(!j) continue;
				ll ile=0, poczatek=j;
				for(ll l=j; l<=m; l=(l*x+99999)/100000) {
					if(dp[i-1][l]<INF) ++kubelki[j];
					wjakim[l]=j;
					++ile;
					if(ile>y+1) {
						if(dp[i-1][poczatek]<INF) --kubelki[j];
						poczatek=(poczatek*x+99999)/100000;
					}
					if(dp[i][l]==INF && kubelki[j]) dp[i][l]=i;
				}
			}
		}
	}
	rep(i, m) cout << (dp[n][i+1]==INF?-1:dp[n][i+1]) << " ";
	cout << '\n';
}