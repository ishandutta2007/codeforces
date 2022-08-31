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

const ll   N     =  1e6 + 1;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m;
vector <pair <int, int>> adj[N];
vector <int> w[N];

int find(int i, int j) {
	auto ind = lower_bound(all(w[i]), j) - w[i].begin();
	if (ind == w[i].size() || w[i][ind] != j) return j;
	int l = ind, r = w[i].size() - 1, ans = w[i].back() + 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (w[i][mid] - w[i][ind] == mid - ind) {
			ans = w[i][mid] + 1;
			l = mid + 1;
		} else r = mid - 1;
	}
	return ans;
}

void dijkstra(int s) {
	vector <int> d(n + 1, INFi);
	d[s] = find(1, 0);
	set<pair<int, int>> q; q.insert({d[s], s});
	while (!q.empty()) {
		int v = q.begin()->s;
		q.erase(q.begin());
		for (auto i : adj[v]) {
			int to = i.f;
			int len = i.s;
			if (find(to, d[v] + len) < d[to]) {
				q.erase({d[to], to});
				d[to] = find(to, d[v] + len);
				q.insert({d[to], to});
			}
		}
	}
	if (d[n] == INFi) d[n] = -1;
	deb1(d[n])
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x;
		for (int j = 1; j <= x; j++) {
			cin >> y;
			w[i].pb(y);
		}
		sort(all(w[i]));
	}
	dijkstra(1);
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}