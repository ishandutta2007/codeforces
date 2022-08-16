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
 
const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, lvl[N], dp[N], ct = 0;
vll adj[N];
set <pll> ans;

void dfs(int x, int par){
	dp[x] = 0;
	for (auto it : adj[x]) {
		if(it == par) continue;
		if(lvl[it] == 0){ /* edge to child */
			//deb2(it,x)
			lvl[it] = lvl[x] + 1;
			dfs(it,x);
			ans.insert({x,it});
			dp[x] += dp[it];
		}
		else if (lvl[it] < lvl[x]){ /* edge upwards */
			ans.insert({x,it});
			dp[x]++;
		}
		else if (lvl[it] > lvl[x]){ /* edge downwards */
			dp[x]--;
		}
	}
	if(lvl[x] > 1 and dp[x] == 0){
		ct++;
	}
}

void solve(){
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	lvl[1] = 1;
	dfs(1,0);
	if(ct != 0){
		deb1(0)
		return;
	}
	for(auto it : ans){
		deb2(it.f,it.s)
	}
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