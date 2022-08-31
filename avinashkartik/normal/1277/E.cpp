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
 
const ll   N     =  2e+5+3;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
int n,m,a,b,u,v,ct,vis[N];
vll adj[N];

void dfs(int x,int ch){
	if(!vis[x]){
		vis[x] = 1;
		ct++;
		for(auto it : adj[x]){
			if(it == ch) continue;
			dfs(it,ch);
		}
	}
}

int main(){
	fastio;
	ll te;
	cin>>te;
	while(te--){
		cin>>n>>m>>a>>b;
		for(int i = 0; i < m; i++){
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		ct = 0;
		dfs(a,b);
		ll ct1 = ct;

		ct = 0;
		fill_n(vis,n+1,0);
		dfs(b,a);
		cout<<(n-ct-1)*(n-ct1-1)<<endl;

		fill_n(vis,n+1,0);
		for(int i = 0; i <= n; i++) adj[i].clear();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}