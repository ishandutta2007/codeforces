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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, m, c[505][505], ans[505][505], s[505][505];
vector <int> adj[505];

void bfs(int i, int j) {
	vector <int> d(n + 1, INFi), d1(n + 1, INFi);
	queue <int> q;
	vector <int> no(n + 1), no1(n + 1), cnt(n + 1, 0);
	vector <pll> p;
	d[i] = 0, q.push(i), s[i][0] = 1, no[i] = 1;
	p.pb({i, 0});
	while (q.size()) {
		int x = q.front(); q.pop();
		for (auto it : adj[x]) {
			if (d[it] > d[x] + 1) {
				d[it] = d[x] + 1;
				q.push(it);
			}
			if (d[it] == d[x] + 1) s[it][x] = 1, no[it]++, p.pb({it, x});
		}
	}
	if (i != j) {
		d1[j] = 0, q.push(j), no1[j] = 1;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (auto it : adj[x]) {
				if (d1[it] > d1[x] + 1) {
					d1[it] = d1[x] + 1;
					q.push(it);
				}
				if (d1[it] == d1[x] + 1) no1[it]++, cnt[it] += s[it][x];
			}
		}
		ll res = 1;
		for (int j = 1; j <= n; j++) {
			if (d[j] + d1[j] == d1[i]) {
				if (no[j] > 1 || no1[j] > 1) res = 0;
			} else {
				res = res * (ll) cnt[j] % mod;
			}
		}
		ans[i][j] = ans[j][i] = res;
	} else {
		ll res = 1;
		for (int i = 1; i <= n; i++) res = res * (ll) no[i] % mod;
		ans[i][j] = ans[j][i] = res;
	}
	for (auto it : p) s[it.f][it.s] = 0;
}

void solve() {
	mset(c, 1);
	mset(ans, 0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			bfs(i, j);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << ans[i][j] << " ";
		}
		newl;
	}
}


int main() {
	GODSPEED;
	int test = 1;
	//cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
#ifndef ONLINE_JUDGE
	cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}