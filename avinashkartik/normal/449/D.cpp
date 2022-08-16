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
 
const ll   N     =  (1<<20)+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, a[N], dp[N], p2[N];

void solve(){
	mset(dp,0);
	cin>>n;
	p2[0] = 1;
	for(int i = 1; i <= n ;i++) p2[i] = (p2[i-1]*2)%mod;
	for(int i = 0; i < n ;i++) cin>>a[i], dp[a[i]]++;
	for(int j = 0; j < 20; j++){
		for(int i = (1<<20)-1; i >= 0; i--){
			if(i&(1<<j)) dp[i-(1<<j)] = (dp[i-(1<<j)]+dp[i])%mod;
		}
	}
	ll ans = 0;
	for(int i = 0; i < (1<<20); i++){
		//deb2(dp[i],i)
		int x = __builtin_popcount(i);
		if(x&1) ans = (ans+mod-p2[dp[i]]+1)%mod;
		else ans = (ans+p2[dp[i]]-1)%mod;
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