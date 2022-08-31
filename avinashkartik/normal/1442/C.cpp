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

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, p2[N];
vpll adj[N];

vll dijkstra(int s) {
    vll d(n + 1, INF);
    d[s] = 0;
    set<pll> q; q.insert({0, s});
    ll ct = 0;
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());
        for(auto i : adj[v]){
            ll to = i.f;
            ll len = i.s ^ (d[v]&1);
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    return d;
}

void dijkstra1(int s, vll no) {
    vector <vll> d(n + 1, vll(30, INF));
    d[s][0] = 0;
    set<pair<ll, pll>> q; q.insert({0, {s, 0}});
    ll ct = 0;
    while (!q.empty()) {
        pll v = q.begin()->s;
        q.erase(q.begin());
        for(auto i : adj[v.f]){
            ll to = i.f;
            ll len = 1;
            ll f = v.s + (i.s ^ ((v.s + no[v.f])&1)) + no[v.f] - no[to];
            if(f > 29 || f < 0) continue;
            if (d[v.f][v.s] + 1 < d[to][f]) {
                q.erase({d[to][f], {to, f}});
            	d[to][f] = d[v.f][v.s] + 1;
                q.insert({d[to][f], {to, f}});
            }
        }
    }
    ll mn = 0;
    for(int i = 1; i < 25; i++){
    	if((no[n] + i) > 29) break;
    	ll res = (1ll << (no[n] + i)) + d[n][i] - 1;
    	ll resmn = (1ll << (no[n] + mn)) + d[n][mn] - 1;
    	if(res < resmn) mn = i;
    }
    ll ans = p2[no[n] + mn] + d[n][mn] - 1;
    deb1(ans)
}

void solve(){
	p2[0] = 1;
	for(int i = 1; i < N; i++) p2[i] = p2[i - 1] * 2 % mod;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		ll u, v; cin >> u >> v;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
	}
	vll d = dijkstra(1);
	dijkstra1(1, d);
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}