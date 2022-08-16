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
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, k, d[N], ans[N], ct = 1;
vpll adj[N];
vll edge[N];

void bfs(){
	mset(d,-1);
	queue <ll> q;
	q.push(1);
	d[1] = 0;
	while(q.size()){
		ll x = q.front(); q.pop();
		for(auto it : adj[x]){
			if(d[it.f] == -1) q.push(it.f), d[it.f] = d[x]+1;
			if(d[it.f] == d[x]+1) edge[it.f].pb(it.s);
		}
	}
}

void rec(int i){
	if(ct == 0) return;
	if(i == n+1){
		for(int i = 0; i < m; i++) cout<<ans[i];
		cout<<endl;
		ct--;
		return;
	}
	for(auto it : edge[i]){
		ans[it] = 1;
		rec(i+1);
		ans[it] = 0;
	}
}

void solve(){
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb({v,i});
		adj[v].pb({u,i});
	}
	bfs();
	for(int i = 2; i <= n; i++){
		ct *= edge[i].size();
		if(ct > k){
			ct = k;
			break;
		}
	}
	deb1(ct)
	rec(2);
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