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

const ll   N     =  1e3+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, k, a[N], b[N], cost[N][N], u[N], v[N], w[N];
vpll adj[N];

void dijkstra(int s) {
    vll d(n+1, INF);
    d[s] = 0;
    set<pll> q; q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());
        for(auto i : adj[v]){
            ll to = i.f;
            ll len = i.s;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    for(int i = 1; i <= n; i++) cost[s][i] = d[i];
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		adj[u[i]].pb({v[i], w[i]});
		adj[v[i]].pb({u[i], w[i]});
	}
	for(int i = 1; i <= n; i++) dijkstra(i);
	for(int i = 1; i <= k; i++) cin >> a[i] >> b[i];
	ll ans = INF;
	for(int i = 1; i <= m; i++){
		ll d = 0;
		for(int j = 1; j <= k; j++){
			d += min({cost[u[i]][a[j]] + cost[v[i]][b[j]], cost[v[i]][a[j]] + cost[u[i]][b[j]], cost[a[j]][b[j]]});
		}
		ans = min(ans, d);
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}