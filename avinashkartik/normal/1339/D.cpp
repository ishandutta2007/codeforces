#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,x,y,a,b,vis[N],f=0,ct=0,ans,minn,maxx,ch[N][2];
vll adj[N];

void dfs(ll x){
	vis[x] = 1;
	if(adj[x].size() == 1) ch[x][0] = 1;
	for(auto it : adj[x]){
		if(!vis[it]){
			dfs(it);
			if(ch[x][0] == 0 && ch[it][1] == 1)
				ch[x][0] = 1;
			if(ch[x][1] == 0 && ch[it][0] == 1)
				ch[x][1] = 1;
			if(ch[x][0] == 1 && ch[x][1] == 1)
				minn = 3;
		}
	}
}

void dfsmax(ll x){
	vis[x] = 1;
	ll no = 0;
	for(auto it : adj[x]){
		if(adj[it].size() == 1) no++;
		if(!vis[it]){
			dfsmax(it);
		}
	}
	if(no != 0) maxx -= no, maxx++;
}

void solve(){
	cin>>n;
	minn = 1;
	maxx = n-1;
	for(int i = 0; i < n-1; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	mset(vis,0);
	dfsmax(1);
	mset(vis,0);
	dfs(1);
	cout<<minn<<" "<<maxx<<endl;
	
}

int main(){
    fastio;
    //cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
}