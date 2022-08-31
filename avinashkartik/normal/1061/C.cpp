#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, dp[N], x;

void solve(){
	mset(dp,-1);
	cin>>n;
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		cin>>x;
		vll v;
		for(int j = 1; j*j <= x; j++){
			if(x%j == 0){
				if(j <= i) v.pb(j);
				if(j*j != x and x/j <= i) v.pb(x/j);
			}
		}
		sort(v.begin(), v.end(), greater<ll>());
		for(auto it : v){
			if(dp[it-1] != -1){
				dp[it] = max(dp[it],0ll);
				dp[it] += dp[it-1];
				dp[it] %= mod;
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(dp[i] == -1) break;
		ans += dp[i];
		ans %= mod;
	}
	deb1(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}