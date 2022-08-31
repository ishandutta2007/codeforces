#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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

const ll   N     =  5e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, l[N], r[N], dp[N][2];
vector <int> adj[N];

void dfs(int u, int p) {
	dp[u][0] = dp[u][1] = 0;
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0] + abs(l[u] - l[v]), dp[v][1] + abs(l[u] - r[v]));
		dp[u][1] += max(dp[v][0] + abs(r[u] - l[v]), dp[v][1] + abs(r[u] - r[v]));
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	deb1(max(dp[1][0], dp[1][1]))
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}