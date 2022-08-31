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

ll n, l[N], r[N], p[N], sz[N], d[N], ct;
vector <int> adj[N];
map <pair <int, int>, int> vis;

void cl() {
	ct = 0;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		l[i] = r[i] = d[i] = 0;
	}
	vis.clear();
}

void dfs(int x, int p) {
	d[x] = 0;
	for (auto it : adj[x]) {
		if (it == p) continue;
		dfs(it, x);
		if (d[x] == 2 || d[it] == 2) {
			ct++;
			vis[{min(x, it), max(x, it)}] = 1;
		} else {
			d[x]++;
			d[it]++;
		}
	}
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

void solve() {
	cin >> n;
	cl();
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	make(n + 2);
	for (int i = 1; i <= n; i++) {
		for (auto it : adj[i]) {
			if (vis[{min(i, it), max(i, it)}] == 1) continue;
			merge(i, it);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (d[i] <= 1) {
			int x = find(i);
			if (l[x]) r[x] = i;
			else l[x] = r[x] = i;
		}
	}
	deb1(ct)
	for (auto it : vis) {
		if (it.s == 0) continue;
		cout << it.f.f << " " << it.f.s << " ";
		cout << r[find(it.f.f)] << " " << l[find(it.f.s)] << "\n";
		// deb4(l[find(it.f.f)], r[find(it.f.f)], l[find(it.f.s)], r[find(it.f.s)])
		r[find(it.f.f)] = r[find(it.f.s)];
		l[find(it.f.s)] = l[find(it.f.f)];
		merge(it.f.f, it.f.s);
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