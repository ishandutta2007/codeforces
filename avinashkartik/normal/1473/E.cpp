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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e18;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
vpll adj[N];

void dijkstra(int s) {
	vector <vector <ll>> d(n + 1, vector <ll> (4, INF));
	set<tuple <ll, ll, ll>> q;
	d[s][0] = 0;
	q.insert({0, 0, s});
	while (!q.empty()) {
		auto [w, f, v] = *q.begin();
		q.erase(q.begin());
		for (auto i : adj[v]) {
			ll to = i.f;
			ll len = i.s;
			ll dist = d[v][f] + len;
			for (int i = 0; i <= 3; i++) {
				if (i&f) continue;
				ll ndist = dist;
				if (i == 1) ndist -= len;
				if (i == 2) ndist += len;
				if (ndist < d[to][i|f]) {
					q.erase({d[to][i|f], i|f, to});
					d[to][i|f] = ndist;
					q.insert({d[to][i|f], i|f, to});
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << d[i][3] << " ";
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	dijkstra(1);
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}