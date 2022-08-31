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

ll n, m, basis[65], in_basis[65], val[N], is_set[2], sz_basis = 0;
ll p[N], sz[N];
vector <pll> adj[N];
vector <int> vertices;

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

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

void insert(ll x) {
	for (int j = 59; j >= 0; j--) {
		if (((1ll << j)&x) == 0) continue;
		if (basis[j]) x ^= basis[j];
		else {
			for (int k = 0; k < 60; k++) {
				if ((x >> k) & 1) in_basis[k] = 1;
			}
			basis[j] = x;
			sz_basis++;
			break;
		}
	}
}

void compute_basis(int x, ll v) {
	val[x] = v;
	vertices.pb(x);
	for (auto it : adj[x]) {
		if (val[it.f] != -1) {
			insert(val[x] ^ val[it.f] ^ it.s);
		} else compute_basis(it.f, v ^ it.s);
	}
}

void dfs(int x, int f, ll bit) {
	is_set[f]++;
	val[x] = f;
	for (auto it : adj[x]) {
		if (val[it.f] != -1) continue;
		int nf = f;
		if (bit & it.s) nf = 1 - nf;
		dfs(it.f, nf, bit);
	}
}

void solve() {
	cin >> n >> m;
	make(n + 1);
	for (int i = 1; i <= m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
		merge(u, v);
	}
	ll ans = 0;
	mset(val, -1);
	for (int root = 1; root <= n; root++) {
		if (find(root) != root)  continue;
		ll nc2 = sz[root] * (sz[root] - 1) % mod * fastmod(2) % mod;
		mset(basis, 0);
		mset(in_basis, 0);
		sz_basis = 0;
		vertices.clear();
		compute_basis(root, 0);
		for (int i = 0; i < 60; i++) {
			for (auto it : vertices) val[it] = -1;
			mset(is_set, 0);
			dfs(root, 0, (1ll << i));
			if (in_basis[i] == 1) {
				ll res = fastmod(2, i + sz_basis - 1) * nc2 % mod;
				ans = (ans + res) % mod;
			} else {
				ll res = is_set[1] * is_set[0] % mod * fastmod(2, i + sz_basis) % mod;
				ans = (ans + res) % mod;
			}
		}
		for (auto it : vertices) val[it] = -1;
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