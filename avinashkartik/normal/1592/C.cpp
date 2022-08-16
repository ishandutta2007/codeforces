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

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, x, a[N], v[N];
vector <int> adj[N];

int dfs(int u, int p) {
	int f = 0;
	v[u] = a[u];
	for (auto it : adj[u]) {
		if (it == p) continue;
		f += dfs(it, u);
		v[u] ^= v[it]; 
	}
	if (!f) f += (v[u] == x);
	else f += (v[u] == 0);
	return f;
}

void solve() {
	cin >> n >> k;
	x = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i], x ^= a[i];
		adj[i].clear();
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	if (x && k == 2) {
		deb1("NO")
		return;
	}
	if (x == 0) {
		deb1("YES")
	} else {
		if (dfs(1, 0) >= 2) deb1("YES")
		else deb1("NO")
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}