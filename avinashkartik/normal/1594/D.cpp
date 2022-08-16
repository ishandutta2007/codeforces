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

const ll   N     =  1e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, p[N], sz[N], vis[N], c[2], flag;
string s;
vector <int> adj[N];

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
		adj[i].clear();
		vis[i] = 0;
	}
	flag = 0;
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

void dfs(int x, int f) {
	c[f] += sz[x];
	vis[x] = 1 + f;
	for (auto it : adj[x]) {
		if (!vis[it]) dfs(it, 1 - f);
		else if (vis[it] == vis[x]) flag = 1;
	}
}

void solve() {
	cin >> n >> m;
	vpll e;
	make(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v >> s;
		if (s[0] == 'c') merge(u, v);
		else e.pb({u, v});
	}
	for (auto &[u, v] : e) {
		adj[find(u)].pb(find(v));
		adj[find(v)].pb(find(u));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == i && !vis[i]) {
			c[0] = c[1] = 0;
			dfs(i, 0);
			ans += max(c[0], c[1]);
		}
	}
	if (!flag) deb1(ans)
	else deb1(-1)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}