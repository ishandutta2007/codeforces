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

ll n, m, q, vis[N], p[N];
vector <tuple <int, int>> adj[N], rev[N];
stack <int> st;

void dfs(int x) {
	vis[x] = 1;
	for (auto [v, w] : adj[x]) {
		if (!vis[v]) dfs(v);
	}
	st.push(x);
}

void scc(int x, int par) {
	p[x] = par;
	vis[x] = 1;
	for (auto [v, w] : rev[x]) {
		if (!vis[v]) scc(v, par);
	}
}

class cycleBasis {
	ll g, par;
	map <int, ll> d;
	public:

	cycleBasis () {
		g = 0;
	}

	cycleBasis (int p) {
		g = 0;
		par = p;
	}

	void dfs(int x) {
		for (auto [v, w] : adj[x]) {
			if (p[v] != par) continue;
			if (d.find(v) != d.end()) {
				ll val = abs(d[x] + w - d[v]);
				g = __gcd(g, val);
			} else {
				d[v] = d[x] + w;
				dfs(v);
			}
		}
	}

	void compute(ll s, ll t) {
		if (s % __gcd(t, g) != 0) deb1("NO")
		else deb1("YES")
	}
};

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({v, w});
		rev[v].pb({u, w});
	}
	mset(vis, 0);
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
	mset(vis, 0);
	while (st.size()) {
		int v = st.top();
		st.pop();
		if (!vis[v]) scc(v, v);
	} 
	vector <cycleBasis> c(n + 1);
	for (int i = 1; i <= n; i++) {
		if (p[i] == i) {
			c[i] = cycleBasis(i);
			c[i].dfs(i);
		}
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		ll v, s, t;
		cin >> v >> s >> t;
		c[p[v]].compute(s, t);
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}