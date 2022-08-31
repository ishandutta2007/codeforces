#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
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
typedef  vector<pll>           vpll;

const ll   N     =  5e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, k, a[N], b[N], c[N], vis[N], can[N][N];
vll adj[N];

void solve(){
	cin>>n>>m>>k;
	for(int i = 1; i <= n; i++) cin>>a[i]>>b[i]>>c[i], adj[i].pb(i);
	for(int i = 1; i <= m; i++){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		can[u][v] = 1;
	}
	for(int i = n-1; i > 0; i--){
		for(int j = 1; j <= n; j++){
			can[i][j] |= can[i+1][j];
		}
	}
	set <pll> s;
	for(int i = 1; i <= n; i++){
		if(k+s.size() < a[i]){ deb1(-1) return; }
		while(k < a[i]){
			auto it = s.begin();
			vis[(*it).s] = 0;
			k++;
			s.erase(it);
		}
		k += b[i];
		set <pll> s1;
		for(auto it : s){
			int f = (can[i+1][it.s] == 1)? -1 : 1;
			s1.insert({f*c[it.s],it.s});
		}
		s = s1;
		for(auto it : adj[i]){
			if(vis[it] == 0){
				vis[it] = 1;
				int f = (can[i+1][it] == 1)? -1 : 1;
				s.insert({f*c[it],it});
				k--;
			}
		}
	}
	ll ans = 0;
	while(k < 0){
		auto it = s.begin();
		vis[(*it).s] = 0;
		k++;
		s.erase(it);
	}
	for(int i = 1; i <= n; i++) ans += c[i]*vis[i];
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