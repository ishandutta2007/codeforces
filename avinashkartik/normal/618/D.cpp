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

ll t=1,n,x,y,a,b,vis[N],f=0,ct=0,ans,avail[N];
vll adj[N];

ll bfs(ll s){
	ll x;
	mset(vis,-1);
	queue <ll> q;
	q.push(s);
	vis[s] = 0;
	while(q.size()){
		x = q.front();
		q.pop();
		for(auto it : adj[x]){
			if(vis[it] == -1){
				vis[it] = vis[x]+1;
				q.push(it);
			}
		}
	}
	return x;
}

void dfs(ll x){
	vis[x] = 1;
	ll no = 0;
	for(auto it : adj[x]){
		if(!vis[it]){
			dfs(it);
			if(avail[it] == 0)
				no++;
		}
		//cout<<it<<" "<<avail[it]<<endl;
	}
	if(no >= 2){
		no = 2;
		avail[x] = -1;
	}
	//cout<<x<<" "<<no<<endl;
	ct += no;
}

ll solve(){
	cin>>n>>x>>y;
	for(int i = 0; i < n-1; i++){
		ll u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if(x >= y){
		int flag = 0;
		for(int i = 1; i <= n; i++){
			if(adj[i].size() == n-1){
				flag = 1;
				break;
			}
		}
		ans = (n-2)*y;
		if(flag == 1) ans += x;
		else ans += y;
	}
	else{
		mset(avail,0);
		dfs(1);
		//cout<<ct<<endl;
		ans = (ct)*x+(n-1-ct)*y;
	}
	return ans;
	
}

int main(){
    fastio;
    //cin>>t;
    for(int i = 0; i < t; i++){
        cout<<solve()<<endl;
    }
}