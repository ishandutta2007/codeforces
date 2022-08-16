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

ll p[N], sz[N], n, m, cntv, cnte, vis[N];
vector <pair<ll,pll>> edge;
vll adj[N];

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

void dfs(int x){
	vis[x] = 1;
	cntv++;
	cnte += adj[x].size();
	for(auto it : adj[x]){
		if(!vis[it]) dfs(it);
	}
}

void solve(){
	cin>>n>>m;
	make(n);
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.pb({w,{u,v}});
	}
	sort(edge.begin(), edge.end());
	int ans = 0;
	for(int i = 0; i < m;){
		int j = i;
		set <ll> vertices;
		while(j < m and edge[j].f == edge[i].f){
			int x = find(edge[j].s.f);
			int y = find(edge[j].s.s);
			if(x != y){
				vertices.insert(x);
				vertices.insert(y);
				adj[x].pb(y);
				adj[y].pb(x);
			}
			j++;
		}
		for(auto it : vertices){
			if(!vis[it]){
				cntv = cnte = 0;
				dfs(it);
				cnte /= 2;
				ans += cnte - (cntv-1);
			}
			adj[it].clear();
			vis[it] = 0;
		}
		for(int k = i; k < j; k++){
			merge(edge[k].s.f,edge[k].s.s);
		}
		i = j;
	}
	deb1(ans)
}

int main(){
	fastio;
	ll test = 1;
	//cin>>t;
	while(test--){
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}