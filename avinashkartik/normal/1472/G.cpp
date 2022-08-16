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

const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, m, a[N];
vll adj[N], rev[N];

vll dijkstra(int s) {
    vll d(n+1, INF), p(n+1, -1);
    d[s] = 0;
    set<pll> q; q.insert({0, s});
    ll ct = 0;
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());
        for(auto i : adj[v]){
            ll to = i;
            ll len = 1;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    return d;
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		rev[v].pb(u);
	}
	vll d = dijkstra(1);
	vector <vector<ll>> ans(n + 1, vector <ll> (2, INF));
	for(int i = 1; i <= n; i++) ans[i][0] = ans[i][1] = d[i];
	set <pair<ll, pll>> q;
	for(int i = 1; i <= n; i++) q.insert({d[i], {i, 0}});
    while (!q.empty()) {
        int v = q.begin()->s.f, f = q.begin()->s.s;
        q.erase(q.begin());
        if(f == 1){
	        for(auto i : rev[v]){
	            ll to = i;
	            ll len = 1;
	            if (d[v] > d[to] && ans[v][f] < ans[to][f]) {
	                q.erase({ans[to][f], {to, f}});
	            	ans[to][f] = ans[v][f];
	                q.insert({ans[to][f], {to, f}});
	            }
	        }
	    } else {
	    	for(auto i : rev[v]){
	            ll to = i;
	            ll len = 1;
	            if (d[v] > d[to] && ans[v][f] < ans[to][0]) {
	            	q.erase({ans[to][0], {to, 0}});
	            	ans[to][0] = ans[v][f];
	                q.insert({ans[to][0], {to, 0}});
	            }
	            if (d[v] <= d[to] && ans[v][f] < ans[to][1]) {
	            	q.erase({ans[to][1], {to, 1}});
	            	ans[to][1] = ans[v][f];
	                q.insert({ans[to][1], {to, 1}});
	            }
	        }
	    }
    }
	for(int i = 1; i <= n; i++) cout << min(ans[i][1], ans[i][0]) << " ";
	newl;
	for(int i = 1; i <= n; i++) adj[i].clear(), rev[i].clear();
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}