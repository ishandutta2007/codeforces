#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, p, k, a[N], dp[55][N], pre[N];

void solve(){
	mset(dp,-1);
	cin >> n >> k >> p;
    dp[0][0] = 0, pre[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = (pre[i-1]+a[i])%p;
    for(int i = 1; i <= k; i++){
    	set <ll,greater<>> s[p+1];
    	for(int j = 0; j <= n; j++){
    		for(int pp = 0; pp < p; pp++){
	    		if(s[pp].size()){
	    			auto it = s[pp].begin();
	    			dp[i][j] = max(dp[i][j],(*it)+(pp+pre[j])%p);
	    		}
	    	}
    		if(dp[i-1][j] != -1) s[(p-pre[j])%p].insert(dp[i-1][j]);
    	}
    }
    deb1(dp[k][n])
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}