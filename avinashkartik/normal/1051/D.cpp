#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
#define	 x                     first                 
#define  y                     second                
 
const ll   N     =  2e+3+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
ll n1,k1,dp[N][N][4];
vll a;
 
int main(){
    fastio;
    cin>>n1>>k1;
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;
    for(int n = 1; n < n1; n++){
    	for(int k = 1; k <= k1; k++){
	    	dp[n+1][k][0] = (dp[n+1][k][0] + dp[n][k][0] + dp[n][k][1] + dp[n][k][2])%mod;
	    	dp[n+1][k+1][0] = (dp[n+1][k+1][0] + dp[n][k][3])%mod;
	    	
	    	dp[n+1][k][1] = (dp[n+1][k][1] + dp[n][k][1])%mod;
	    	dp[n+1][k+1][1] = (dp[n+1][k+1][1] + dp[n][k][0] + dp[n][k][3])%mod;
	    	dp[n+1][k+2][1] = (dp[n+1][k+2][1] + dp[n][k][2])%mod;

	    	dp[n+1][k][2] = (dp[n+1][k][2] + dp[n][k][2])%mod;
	    	dp[n+1][k+1][2] = (dp[n+1][k+1][2] + dp[n][k][0] + dp[n][k][3])%mod;
	    	dp[n+1][k+2][2] = (dp[n+1][k+2][2] + dp[n][k][1])%mod;

	    	dp[n+1][k][3] = (dp[n+1][k][3] + dp[n][k][3] + dp[n][k][1] + dp[n][k][2])%mod;
	    	dp[n+1][k+1][3] = (dp[n+1][k+1][3] + dp[n][k][0])%mod;
	    }
    }

    ll ans = (dp[n1][k1][0] + dp[n1][k1][1] + dp[n1][k1][2] + dp[n1][k1][3])%mod;
	cout<<ans<<endl;
}