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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, a[N], ans[N], k1[N][40];
vector <int> adj[N];

void dfs(int x = 1, int p = 0, int d = 0){
	k1[x][0] = a[x];
	for(auto it : adj[x]) {
		if(it == p) continue;
		dfs(it, x, d + 1);
		for(int i = 0; i < k; i++) {
			k1[x][i] ^= k1[it][(i + k - 1) % k]; 
		}
	}
}

void reroot(int x = 1, int p = 0) {
	if(p) {
		for(int i = 0; i < k; i++) {
			k1[p][i] ^= k1[x][(i + k - 1) % k];
		}
		for(int i = 0; i < k; i++) {
			k1[x][i] ^= k1[p][(i + k - 1) % k];
		}
	}
	ll res = 0;
	for(int i = k / 2; i < k; i++) res ^= k1[x][i];
	ans[x] = (res != 0);
	for(auto it : adj[x]) {
		if(it == p) continue;
		reroot(it, x);
	}
	if(p) {
		for(int i = 0; i < k; i++) {
			k1[x][i] ^= k1[p][(i + k - 1) % k];
		}
		for(int i = 0; i < k; i++) {
			k1[p][i] ^= k1[x][(i + k - 1) % k];
		}
	}
}

void solve() {
	cin >> n >> k;
	k *= 2;
	for(int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs();
	reroot();
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}