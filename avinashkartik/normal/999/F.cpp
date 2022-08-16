#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

const ll   N     =  1e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, k, h[11], cards[N], players[N], dp[505][5005];

void solve(){
	mset(dp,0);
    cin>>n>>k;
    for(int i = 0; i < n*k; i++){
    	int x;
    	cin>>x;
    	cards[x]++;
    }
    for(int i = 0; i < n; i++){
    	int x;
    	cin>>x;
    	players[x]++;
    }
    for(int i = 1; i <= k; i++) cin>>h[i];
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= n*k; j++){
    		for(int kk = 0; kk <= k; kk++){
    			if(j-kk < 0) break;
    			dp[i][j] = max(dp[i][j],dp[i-1][j-kk]+h[kk]);
    		}
    	}
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
    	ans += dp[players[i]][cards[i]];
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