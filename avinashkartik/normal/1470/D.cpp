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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, ans, vis[N], h[N];
vector <int> adj[N];

void dfs(int x){
	vis[x] = 1;
	h[x] = 1;
	for(auto it : adj[x]){
		if(vis[it] != -1){
			if(h[it] == 1) h[x] = 0;
		}
	}
	for(auto it : adj[x]){
		if(vis[it] == -1){
			dfs(it);
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		vis[i] = -1;
		adj[i].clear();
	}
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	vector <int> v;
	for(int i = 1; i <= n; i++){
		if(vis[i] == -1){
			deb1("NO");
			return;
		}
		if(h[i]) v.pb(i);
	}
	deb1("YES")
	deb1(v.size())
	debv(v)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}