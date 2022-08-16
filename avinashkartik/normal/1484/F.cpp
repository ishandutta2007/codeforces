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

const ll   N     =  605;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, q, adj[N][N];
vector <pll> Q[N];

struct edge {
	ll u, v, w;
};

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i == j) continue;
			adj[i][j] = 1e16;
		}
	}
	vector <edge> e;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u][v] = adj[v][u] = w;
		e.pb({u, v, w});
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		Q[u].pb({v, l});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (adj[j][k] > adj[j][i] + adj[i][k]) {
					adj[j][k] = adj[j][i] + adj[i][k];
				}
			}
		}
	}
	vector <int> ans(m + 1, 0);
	for (int i = 1; i <= n; i++) {
		vector <ll> d(n + 1, -1e16);
		for(auto it : Q[i]) {
			for(int i = 1; i <= n; i++) {
				d[i] = max(d[i], it.s - adj[it.f][i]);
			}
		}
		for(int j = 0; j < m; j++) {
			if(adj[i][e[j].u] + e[j].w <= d[e[j].v]) ans[j] = 1;
			if(adj[i][e[j].v] + e[j].w <= d[e[j].u]) ans[j] = 1;
		}
	}
	deb1(accumulate(all(ans), 0))
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}