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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());          
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e6+8;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, k, dp[N][2];
vpll adj[N];

void dfs(ll x, ll p){
	multiset <pll, greater<>> s;
	for(auto it : adj[x]){
		if(it.f == p) continue;
		dfs(it.f,x);
		s.insert({it.s+dp[it.f][0]-dp[it.f][1],dp[it.f][1]});
	}
	int ct = 1;
	for(auto it : s){
		if(it.f < 0){
			dp[x][1] += it.s;
			dp[x][0] += it.s;
			continue;
		}
		if(ct == k){
			dp[x][1] += it.f+it.s;
			dp[x][0] += it.s;
		}
		else if(ct > k){
			dp[x][1] += it.s;
			dp[x][0] += it.s;
		}
		else{
			dp[x][1] += it.f+it.s;
			dp[x][0] += it.f+it.s;
		}
		ct++;
	}
}

void solve(){
	cin>>n>>k;
	for(int i = 1; i < n; i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfs(1,0);
	deb1(dp[1][1]);
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		dp[i][0] = dp[i][1] = 0;
	}
}

int main(){
    fastio;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}