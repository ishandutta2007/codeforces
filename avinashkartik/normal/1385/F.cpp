#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
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

int test = 1, n, k, dp[N], cnt[N], ans;
vll adj[N];

void dfs(int x, int p){
	dp[x] = 1;
	cnt[x] = 0;
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x);
		if(dp[it] == 1 and cnt[it] == 0) cnt[x]++;
		else dp[x] += dp[it]+cnt[it];
	}
	cnt[x] %= k;
}

void reroot(int x, int p){
	if(p){
		if(dp[x] == 1 and cnt[x] == 0) cnt[p] = (k+cnt[p]-1)%k;
		else dp[p] -= dp[x]+cnt[x];
		if(dp[p] == 1 and cnt[p] == 0) cnt[x] = (cnt[x]+1)%k;
		else dp[x] += dp[p]+cnt[p];
		ans = min(ans,dp[x]+cnt[x]);
		//deb3(x,dp[x],cnt[x])
	}
	for(auto it : adj[x]){
		if(it == p) continue;
		reroot(it,x);
	}
	if(p){
		if(dp[p] == 1 and cnt[p] == 0) cnt[x] = (k+cnt[x]-1)%k;
		else dp[x] -= dp[p]+cnt[p];
		if(dp[x] == 1 and cnt[x] == 0) cnt[p] = (cnt[p]+1)%k;
		else dp[p] += dp[x]+cnt[x];
	}
}

void solve(){
	cin>>n>>k;
	for(int i = 1; i < n; i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    ans = dp[1]+cnt[1];
    reroot(1,0);
    deb1((n-ans)/k)
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        dp[i] = 0;
        cnt[i] = 0;
    }
}

int main(){
    GODSPEED;
    cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}