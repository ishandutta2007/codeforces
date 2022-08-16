#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
const ll   mod   =  1e+9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll p[N], sz[N], n, m, vis[N];
vll adj[N];
vpll v;

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

void solve(){
	cin>>n>>m;
	make(n);
	for(int i = 1; i <= n; i++){
		int x;
		cin>>x;
		v.pb({x,i});
	}
	sort(v.begin(), v.end());
	for(int i = 1; i <= m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll res = 0;
	for(int i = n-1; i >= 0; i--){
		int x = v[i].f, y = v[i].s, ct = 0;
		set <ll> s;
		for(auto it : adj[y]){
			if(vis[it] == 0) continue;
			int z = find(it);
			if(s.find(z) == s.end()){
				s.insert(z);
				res += sz[z]*x;
				ct += sz[z];
			}
		}
		ll res1 = 0;
		for(auto it : s){
			res1 += (ct-sz[it])*sz[it]*x;
		}
		for(auto it : s){
			merge(it,y);
		}
		res += res1/2;
		vis[y] = 1;
	}
	ll den = n*(n-1)/2;
	deb1((ld)res/den)
}

int main(){
	fastio;
	ll t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}