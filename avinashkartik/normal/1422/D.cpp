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
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, sx, sy, fx, fy, f = 1;
map <pll, vpll> adj;
vpll X, Y;

ll dist(pll x, pll y){
	if(y.f == fx and y.s == fy and f == 1){
		return abs(x.f - y.f) + abs(x.s - y.s);
	}
	return min(abs(x.f - y.f), abs(x.s - y.s));
}

void djikstras(){
	map <pll, ll> d;
	for(auto it : X) d[it] = INF;
	d[{fx, fy}] = INF;
    d[{sx, sy}] = 0;
    set<pair<ll, pll>> q; q.insert({0, {sx, sy}});
    while (!q.empty()) {
        pll v = q.begin()->s;
        q.erase(q.begin());
        for(auto i : adj[v]){
            pll to = i;
            ll len = dist(v, to);
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
            	d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    cout << d[{fx, fy}] << endl;
}

void solve(){
	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;
	adj[{sx, sy}].pb({fx, fy});
	for(int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		X.pb({x, y});
		Y.pb({y, x});
		adj[{sx, sy}].pb({x, y});
		adj[{x, y}].pb({fx, fy});
		if(x == fx and y == fy) f = 0;
	}
	sort(all(X));
	sort(all(Y));
	for(int i = 0; i < m; i++){
		if(i != 0){
			adj[X[i]].pb(X[i - 1]);
			adj[{Y[i].s, Y[i].f}].pb({Y[i - 1].s, Y[i - 1].f});
		}
		if(i != n-1){
			adj[X[i]].pb(X[i + 1]);
			adj[{Y[i].s, Y[i].f}].pb({Y[i + 1].s, Y[i + 1].f});
		}
	}
	djikstras();
}

int main(){
	//GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}