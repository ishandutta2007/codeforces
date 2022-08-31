#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n, p , k, s[N][10], dp[N][130];
pll a[N];

void solve(){
	cin>>n>>p>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i].f;
		a[i].s = i;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < p; j++)
			cin>>s[i][j];
	sort(a+1,a+n+1,greater<>());
	mset(dp,-1);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++){
		ll ind = a[i].s;
		for(int mask = 0; mask < (1<<p); mask++){
			ll pl = i-1-__builtin_popcount(mask);
			dp[i][mask] = dp[i-1][mask];
			for(int j = 0; j < p; j++){
				if((mask&(1<<j)) && dp[i-1][mask-(1<<j)] != -1)
					dp[i][mask] = max(dp[i][mask],dp[i-1][mask-(1<<j)]+s[ind][j]);
			}
			if(pl < k && dp[i-1][mask] != -1){
				dp[i][mask] = max(dp[i][mask],dp[i-1][mask]+a[i].f);
			}
			//deb3(i,mask,dp[i][mask]);
		}
	}
	cout<<dp[n][(1<<p)-1]<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}