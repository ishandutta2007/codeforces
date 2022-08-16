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

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], ans = 0;
map <ll, vll> fact;
map <ll, ll> ct[N];
vll adj[N];

void dfs(ll x, ll par){
	map <ll, vll> mx;
	for(auto it : adj[x]){
		if(it == par) continue;
		dfs(it,x);
		for(auto p : fact[x]){
			if(a[it]%p) continue;
			mx[p].pb(ct[it][p]);
		}
	}
	for(auto p : fact[x]){
		ct[x][p]++;
		if(mx[p].size() > 1){
			sort(all(mx[p]),greater<>());
			ans = max(ans,mx[p][0]+mx[p][1]+1);
		}
		if(mx[p].size()) ct[x][p] += mx[p][0];
		ans = max(ans,ct[x][p]);
	}
}

void solve(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		int x = a[i];
		for(int j = 2; j*j <= x; j++){
			int ct = 0;
			while(x%j == 0) x /= j, ct++;
			if(ct) fact[i].pb(j);
		}
		if(x > 1) fact[i].pb(x);
	}
	for(int i = 1; i < n; i++){
		int l,r; cin>>l>>r;
		adj[l].pb(r);
		adj[r].pb(l);
	}
	dfs(1,0);
	deb1(ans)
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}