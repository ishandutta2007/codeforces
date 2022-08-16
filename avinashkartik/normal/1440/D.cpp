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

const ll   N     =  1e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, m, k, vis[N], deg[N], nei[N];
vector<int> adj[N];

struct comp {
	bool operator()(int i, int j) const {
		return deg[i] < deg[j] || (deg[i] == deg[j] && i < j);
	}
};

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		vis[i] = 0;
		deg[i] = 0;
		nei[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	set <int, comp> s;
	for(int i = 1; i <= n; i++){
		deg[i] = adj[i].size(), s.insert(i);
		sort(all(adj[i]));
	}
	while(s.size() >= k){
		auto it = *s.begin();
		if(deg[it] >= k){
			deb2(1, s.size())
			for(auto it1 : s) cout << it1 << " ";
			newl;
			return;
		}
		if(deg[it] == k - 1){
			vector <int> v;
			v.pb(it);
			for(auto to : adj[it]){
				if(vis[to] == 1) continue;
				v.pb(to);
			}
			int f = 1;
			for(auto itt : v){
				for(auto it1 : v){
					if(it1 == itt) continue;
					f &= binary_search(adj[itt].begin(), adj[itt].end(), it1);
				}
			}
			if(f){
				deb1(2)
				debv(v)
				return;
			}
		}
		for(auto to : adj[it]){
			if(vis[to] == 1) continue;
			s.erase(to);
			deg[to]--;
			s.insert(to);
		}
		vis[it] = 1;
		s.erase(it);
	}
	deb1(-1)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}