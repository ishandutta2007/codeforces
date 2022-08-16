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
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
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

ll test = 1, n, mx, mn, sz[N];
vpll adj[N];

void dfsmax(int x, int p){
	sz[x] = 1;
	for(auto it : adj[x]){
		if(it.f == p) continue;
		dfsmax(it.f,x);
		sz[x] += sz[it.f];
		mx += it.s*min(sz[it.f],2*n-sz[it.f]);
	}
}

void dfsmin(int x, int p){
	sz[x] = 1;
	for(auto it : adj[x]){
		if(it.f == p) continue;
		dfsmin(it.f,x);
		sz[x] ^= sz[it.f];
		mn += it.s*sz[it.f];
	}
}

void solve(){
	mx = mn = 0;
	cin>>n;
	for(int i = 1; i < 2*n; i++){
		int u,v,w; cin>>u>>v>>w;
		adj[u].pb({v,w});
		adj[v].pb({u,w});
	}
	dfsmax(1,0);
	dfsmin(1,0);
	deb2(mn,mx)
	for(int i = 1; i <= 2*n; i++) adj[i].clear();
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