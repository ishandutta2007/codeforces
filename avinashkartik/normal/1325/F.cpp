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
 
const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1, n, m, lvl[N], par[N], flag = 0, sq;
vll adj[N], cyc;
set <ll> ans;

void dfs(int x){
	int f = 1;
	for (auto it : adj[x]) {
		if(lvl[it] == 0){
			lvl[it] = lvl[x] + 1;
			par[it] = x;
			dfs(it);
		}
		else if (lvl[it] < lvl[x] and lvl[x] - lvl[it] >= sq-1){
			int en = x;
			while(en != it){
				cyc.pb(en);
				en = par[en];
			}
			cyc.pb(it);
			deb1(2)
			deb1(cyc.size())
			debv(cyc)
			exit(0);
		}
		if(ans.find(it) != ans.end()) f = 0;
	}
	if(f == 1) ans.insert(x);
}

void solve(){
	cin>>n>>m;
	sq = ceil((ld)sqrt(n));
	for(int i = 0; i < m; i++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	lvl[1] = 1;
	dfs(1);
	int ct = 0;
	deb1(1)
	for(auto it : ans){
		cout<<it<<" ";
		ct++;
		if(ct == sq) break;
	}
	cout<<endl;
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