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

int n, c[N], d[N], ans = INFi;
vector <int> adj[N];
set <pll, greater<>> s[N];

void changepar(int x, int p) {
	if (c[x] == c[p]) s[p].erase({d[x], x});
	else s[p].erase({d[x] + 1, x});
	s[p].insert({1, x});
	d[p] = s[p].begin()->f;
	s[x].erase({1, p});
	if (c[x] == c[p]) s[x].insert({d[p], p});
	else s[x].insert({d[p] + 1, p});
	d[x] = s[x].begin()->f;
}

void reroot (int x, int p) {
	if (p) changepar(x, p);
	ans = min(ans, d[x] - 1);
	for (auto it : adj[x]) {
		if (it == p) continue;
		reroot(it, x);
	}
	if (p) changepar(p, x);
}

void dfs(int x, int p) {
	d[x] = 1;
	for (auto it : adj[x]) {
		if (it == p) {
			s[x].insert({1, it});
			continue;
		}
		dfs(it, x);
		if (c[it] == c[x]) {
			s[x].insert({d[it], it});
		} else {
			s[x].insert({d[it] + 1, it});
		}
	}
	if (s[x].size()) d[x] = s[x].begin()->f;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	reroot(1, 0);
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