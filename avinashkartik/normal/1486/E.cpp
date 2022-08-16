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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m;
vpll adj[N];

struct D{
	ll s, f, i;
};

struct comp{
	bool operator() (const D& lhs, const D& rhs) const {
		if(lhs.s == rhs.s && lhs.f == rhs.f) return lhs.i < rhs.i;
		if(lhs.s == rhs.s) return lhs.f < rhs.f;
		return lhs.s < rhs.s;
	}
};

void dijkstra(int s) {
    vector <vector<ll>> d(n+1, vector<ll>(51, INF));
    d[s][0] = 0;
    set<D, comp> q; q.insert({0, 0, 1});
    ll ct = 0;
    while (!q.empty()) {
        auto v = *q.begin();
        q.erase(q.begin());
        for(auto i : adj[v.i]){
            ll to = i.f;
            ll len = i.s;
            if(v.f){
	            if (d[v.i][v.f] + (v.f + i.s) * (v.f + i.s) < d[to][0]) {
	                q.erase({d[to][0], 0, to});
	            	d[to][0] = d[v.i][v.f] + (v.f + i.s) * (v.f + i.s);
	                q.insert({d[to][0], 0, to});
	            }
		    } else {
		    	if (d[v.i][v.f] < d[to][i.s]) {
	                q.erase({d[to][i.s], i.s, to});
	            	d[to][i.s] = d[v.i][v.f];
	                q.insert({d[to][i.s], i.s, to});
	            }
		    }
        }
    }
    for(int i = 1; i <= n; i++) {
    	if(d[i][0] >= INF) d[i][0] = -1;
    	cout << d[i][0] << " ";
    }
    newl;
}
void solve() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	dijkstra(1);
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}