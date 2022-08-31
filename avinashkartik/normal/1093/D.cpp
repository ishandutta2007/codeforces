#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, vis[N], ans, ok, o, e, p2[N];
vll adj[N];

void dfs(int x, int f){
	if(f == 0) vis[x] = 2, e++;
	else vis[x] = 1, o++;
	for(auto it : adj[x]){
		if(!vis[it]){
			dfs(it, 1 - f);
		} else if(vis[it] == vis[x]) ok = 0;
	}
}

void solve(){
	ok = 1, ans = 1;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[v].pb(u);
		adj[u].pb(v);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			o = e = 0;
			dfs(i, 0);
			ans = ans * (p2[o] + p2[e]) % mod;
		}
	}
	if(ok) deb1(ans)
	else deb1(0)
	for(int i = 1; i <= n; i++) vis[i] = 0, adj[i].clear();
}

int main(){
	GODSPEED;
	p2[0] = 1;
	for(int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % mod;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}