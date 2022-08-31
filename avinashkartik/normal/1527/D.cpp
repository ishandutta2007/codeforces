#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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

ll n, p[N], sz[N], vis[N], ans[N];
vector <int> adj[N];

void dfs(int u, int par) {
	sz[u] = 1;
	for (auto v : adj[u]) {
		if (v == par) continue;
		dfs(v, u);
		if (u == 0) {
			ans[0] += sz[v] * (sz[v] - 1) / 2;
			ans[1] += sz[v] * sz[u];
		}
		p[v] = u;
		sz[u] += sz[v];
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(0, 0);
	vis[0] = 1;
	int a = 0, b = 0, ct = 0, u = 1;
	while (u != 0) {
		ct = sz[u];
		u = p[u];
	}
	for (int i = 2; i <= n; i++) {
		int u = i - 1, x, y;
		if (!vis[u]) {
			while(!vis[u]) {
				vis[u] = 1;
				u = p[u];
			}
			if (u == a) {
				a = i - 1;
			} else if (u == b) {
				b = i - 1;
			} else break;
			if (a > b) swap(a, b);
			if (a == 0) {
				x = n - ct;
			} else x = sz[a];
		}
		y = sz[b];
		// deb3(i, a, ct)
		ans[i] = (ll) x * y;
	}
	for (int i = 1; i <= n; i++) ans[i] -= ans[i + 1];
	for (int i = 0; i <= n; i++) cout << ans[i] << " ";
	newl;
	for (int i = 0; i <= n; i++) {
		adj[i].clear();
		p[i] = 0;
		sz[i] = 0;
		ans[i] = 0;
		vis[i] = 0;
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