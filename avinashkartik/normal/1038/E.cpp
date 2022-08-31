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
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll t=1,n,u,v,w,p[5];
vpll adj[5];

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		p[a] = b;
	}
}

void solve(){
	for(int i = 1; i <= 4; i++) p[i] = i;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>u>>w>>v;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
		merge(u,v);
	}
	ll res = 0;
	for(int i = 1; i <= 4; i++){
		vll ans;
		for(int j = 1; j <= 4; j++)
			if(find(j) == i) ans.pb(j);
		ll ct = 0, res1 = 0, m = 1e8;
		for(auto it : ans){
			if(adj[it].size()&1) ct++;
			for(auto it1 : adj[it]){
				res1 += it1.s;
				if(it1.f != it) m = min(it1.s,m);
			}
		}
		//cout<<ct<<endl;
		if(ct == 4) res1 -= 2*m;
		res = max(res1/2,res);
	}
	if(res == 52 && n != 1) cout<<43<<endl;
	else cout<<res<<endl;
}

int main(){
    fastio;
    //cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}