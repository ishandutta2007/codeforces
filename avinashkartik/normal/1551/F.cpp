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

const ll   N     =  1e2 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, k, f[N];
vector <int> adj[N];

ll fastmod(ll x, ll y = mod - 2) {
	ll res = 1;
	while (y) {
		if (y&1) res = res * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return res;
}

ll ncr(ll n, ll r) {
	if (n < r) return 0;
	return f[n] * fastmod(f[r]) % mod * fastmod(f[n - r]) % mod;
}

void dfs(int x, int p, int d, int d1, int v, int &f) {
	if (d == d1 && x > v) f++;
	for (auto it : adj[x]) {
		if (it == p) continue;
		dfs(it, x, d + 1, d1, v, f);
	}
}

ll bfs(int u, int v) {
	vector <int> d1(n + 1, INFi);
	vector <int> d2(n + 1, INFi);
	vector <int> p1(n + 1, 0);
	vector <int> p2(n + 1, 0);
	d1[u] = 0;
	d2[v] = 0;
	queue <int> q;
	q.push(u);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto it : adj[x]) {
			if (d1[it] > d1[x] + 1) {
				d1[it] = d1[x] + 1;
				p1[it] = x;
				q.push(it);
			}
		}
	}
	q.push(v);
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (auto it : adj[x]) {
			if (d2[it] > d2[x] + 1) {
				d2[it] = d2[x] + 1;
				p2[it] = x;
				q.push(it);
			}
		}
	}
	vector <int> p;
	for (int i = 1; i <= n; i++) {
		if (d2[u] == d2[i] * 2 && d1[v] == d1[i] * 2) {
			// deb3(u, v, i)
			for (auto it : adj[i]) {
				if (it == p1[i] || it == p2[i]) continue;
				int f = 0;
				dfs(it, i, 1, d1[i], v, f);
				if (f) p.pb(f);
			}
		}
	}
	if (p.size() < k - 2) return 0;
	vector <vector<ll>> dp(p.size() + 1, vector <ll>(k, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= p.size(); i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= k - 2; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * p[i - 1]) % mod;
		}
	}
	return dp[p.size()][k - 2];
}

void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			// deb3(i, j, bfs(i, j))
			ans = (ans + bfs(i, j)) % mod;
		}
	}
	if (k > 2) deb1(ans)
	else deb1(ncr(n, 2))

	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
}

int main() {
	GODSPEED;
	f[0] = 1;
	for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}