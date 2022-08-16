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

const ll   N     =  1e6 + 1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
vector <int> adj[N], o, e;

void dfs(int x, int p, int f) {
	if (f) o.pb(x);
	else e.pb(x);
	for (auto it : adj[x]) {
		if (it != p) dfs(it, x, 1 - f);
	}
}

void solve() {
	cin >> n;
	vector <int> ans(n + 1), vis(n + 1, 0);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0, 0);

	if (o.size() > e.size()) o.swap(e);

	int sz = o.size();
	int st = log2(sz);
	int i = (1 << st), ct = 0;
	for (auto it : o) {
		if (ct == i) {
			st = log2(sz);
			i = (1 << st), ct = 0;
		}
		ans[it] = i + ct;
		vis[i + ct] = 1;
		ct++;
		sz--;
	}

	i = 1;
	for (auto it : e) {
		while (vis[i] == 1) i++;
		ans[it] = i;
		i++;
	}

	vector <int> ind(n + 1);
	for (int i = 1; i <= n; i++) ind[i] = ans[i];

	for (int i = 1; i <= n; i++) cout << ind[i] << " ";
	newl;

	for (int i = 1; i <= n; i++) adj[i].clear();
	o.clear();
	e.clear();
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}