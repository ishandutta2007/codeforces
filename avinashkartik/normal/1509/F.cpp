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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, p[N], sz[N];
vpll adj[N], g[N];

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void merge(ll x, ll y){
	ll a = find(x);
	ll b = find(y);
	if(a != b){
		if(sz[a] >= sz[b]) swap(a,b);
		p[a] = b;
		sz[b] += sz[a];
	}
}

bool dfs(int x, int v, int f, int p) {
	bool ans = 0;
	if (x == v) ans = f;
	for (auto [to, w] : g[x]) {
		if (to == p) continue;
		ans += dfs (to, v, (f | (w == 0)), x);
	}
	return ans;
}

void solve() {
	cin >> n >> m;
	make(n + 2);
	vector <tuple <ll, int, int, int>> e;
	ll x = 0, ans = 0, l = 0;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		e.pb({w, u, v, 0});
		x ^= w;
	}
	int root = 1;
	for (int i = 2; i <= n; i++) {
		if(adj[i].size() < adj[root].size()) root = i;
	}
	vector <int> f(n + 1, 0);
	for (auto it : adj[root]) f[it.f] = 1;
	f[root] = 1;
	for (int i = 1; i <= n; i++) {
		if (f[i] == 1) continue;
		p[i] = root;
		sz[root]++;
		l++;
		g[root].pb({i, 0});
		g[i].pb({root, 0});
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) == root) continue;
		vector <int> f(n + 1, 0);
		f[i] = 1;
		for (auto it : adj[i]) f[it.f] = 1;
		for (int j = 1; j <= n; j++) {
			if (f[j] == 1) continue;
			e.pb({0, min(i, j), max(i, j), 0});
		}
	}
	sort(all(e));
	uniq(e);
	for (auto &[w, u, v, f] : e) {
		int a = find(u), b = find(v);
		if(a == b) continue;
		f = 1;
		ans += w;
		if(w == 0) l++;
		merge(a, b);
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	if (m + l == n * (n - 1) / 2) {
		ll mn = INF;
		for (auto &[w, u, v, f] : e) {
			if (f == 0) {
				bool x = dfs(u, v, 0, 0);
				if (x) {
					mn = w;
					break;
				}
			}
		}
		if (l) ans += min(mn, x);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}