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
 
const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, k, d[N], p[N], st, en, vis[N];
vll adj[N];
set <ll> s;

void dfs(ll x, ll par){
	vis[x] = 1;
	s.insert(x);
	for(auto it : adj[x]){
		if(st != -1) return;
		if(s.find(it) != s.end() and d[x] - d[it] >= k) st = it, en = x;
		if(!vis[it]){
			p[it] = x;
			d[it] = d[x]+1;
			dfs(it,x);
		}
	}
	s.erase(x);
}

void solve(){
	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	st = en = -1;
	d[1] = 0;
	dfs(1,0);
	vll ans;
	ans.pb(en);
	while(en != st){
		ans.pb(p[en]);
		en = p[en];
	}
	deb1(ans.size())
	debv(ans)
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}