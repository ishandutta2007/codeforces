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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, c[N], w[N], u = 0, v = 0, ct = 0;
vector <vector <int>> adj;
int vis[N], par[N];
vector <int> path;

void dfs(int x, int p) {
	if (u) return;
	vector <int> down, up;
	for (auto it : adj[x]) {
		if (it == p) continue;
		par[it] = x;
		dfs(it, x);
		if (w[it]) {
			w[x] = w[it];
			if (w[it] == it) up.pb(it);
			else down.pb(w[it]);
		}
	}
	if (c[x] == 1) {
		w[x] = x;
		up.pb(x);
	}
	if (down.size() && up.size()) {
		u = down[0];
		v = up[0];
	} else if (up.size() > 1) {
		u = up[0];
		v = up[1];
	}
}

void mark(int x, int p) {
	if (vis[x]) return;
	vis[x] = 1;
	for (auto it : adj[x]) {
		if (it == p) continue;
		mark(it, x);
	}
}

void count(int x, int p) {
	ct += c[x];
	for (auto it : adj[x]) {
		if (it == p) continue;
		count(it, x);
	}
}

void solve() {
	cin >> n;
	adj.assign(n + 1, vector <int>());
	int st = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i]) st = i;
	}
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(st, 0);
	while (u != v) {
		path.pb(u);
		u = par[u];
	}
	path.pb(v);
	if (path.size() < 5) {
		debv(vector <int>(n, 1))
		return;
	}
	
	for (auto it : adj[path[1]]) {
		if (it == path[2]) continue;
		count(it, path[1]);
	}
	for (auto it : adj[path[path.size() - 2]]) {
		if (it == path[path.size() - 3]) continue;
		count(it, path[path.size() - 2]);
	}
	
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) {
			vis[i] = 1;
			for (auto it : adj[i]) vis[it] = 1;
		}
	}
	mark(path[2], 0);
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) {
			vis[i] = 0;
			for (auto it : adj[i]) vis[it] = 0;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (ct == 2) cout << 1 - vis[i] << " ";
		else cout << "1 ";
	}
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}