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

ll test = 1, n, depth[N], ans = 0, ind = 0;
vll adj[N];
multiset <ll, greater<>> s[N];

void calc(int x){
	int ct = 3, res = 0;
	for(auto it : s[x]){
		if(ct == 0) break;
		res += it;
		ct--;
	}
	if(res > ans){
		ans = res;
		ind = x;
	}
}

void reroot(int x, int p){
	if(p){
		auto it = s[p].lower_bound(*s[x].begin()+1); s[p].erase(it);
		s[x].insert(*s[p].begin()+1);
		calc(x);
	}
	for(auto it : adj[x]){
		if(it == p) continue;
		reroot(it,x);
	}
	if(p){
		auto it = s[x].lower_bound(*s[p].begin()+1); s[x].erase(it);
		s[p].insert(*s[x].begin()+1);
	}
}

void dfs(int x, int p){
	depth[x] = depth[p] + 1;
	s[x].insert(0);
	for(auto it : adj[x]){
		if(it == p) continue;
		dfs(it,x);
		s[x].insert(*s[it].begin()+1);
	}
}

int getabc(ll x, ll p){
	depth[x] = depth[p] + 1;
	int mx = x;
	set <pll, greater<>> S;
	for(auto it : adj[x]){
		if(it == p) continue;
		ll y = getabc(it,x);
		if(p){
			if(depth[mx] < depth[y]) mx = y; 
		}
		else{
			S.insert({depth[y],y});
		}
	}
	if(p == 0){
		int a = 0, b = 0, c = 0;
		for(auto it : S){
			if(c) break;
			if(a == 0) a = it.s;
			else if(b == 0) b = it.s;
			else c = it.s;
		}
		for(int i = 1; i <= n; i++){
			if(c) break;
			if(a != i and b != i and b != 0) c = i;
			else if(a != i and b == 0) b = i;
		}
		deb3(a,b,c)
	}
	return mx;
}

void solve(){
	cin>>n;
	for(int i = 1; i < n; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,0);
	calc(1);
	reroot(1,0);
	deb1(ans)
	getabc(ind,0);
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