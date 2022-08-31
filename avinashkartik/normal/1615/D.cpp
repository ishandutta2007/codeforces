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

const ll   N     =  2e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, p[N], vis[N];
vector <int> adj[N];
vector <pair <int, int>> q[N];

void dfs(int x, int par = 0) {
	p[x] = par;
	for (auto it : adj[x]) {
		if (it == par) continue;
		dfs(it, x);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		q[i].clear();
		vis[i] = -1;
	}
	map <pair <int, int>, int> given;

	for (int i = 1; i < n; i++) {
		int x, y, v; cin >> x >> y >> v;
		adj[x].pb(y);
		adj[y].pb(x);
		if (v != -1) {
			q[x].pb({y, __builtin_popcount(v) % 2});
			q[y].pb({x, __builtin_popcount(v) % 2});
			given[{x, y}] = given[{y, x}] = v;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b, p; cin >> a >> b >> p;
		q[a].pb({b, p});
		q[b].pb({a, p});
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] != -1) continue;
		vis[i] = 0;
		queue <int> qu;
		qu.push(i);
		while (qu.size()) {
			int x = qu.front();
			qu.pop();
			for (auto it : q[x]) {
				if (vis[it.f] == -1) {
					vis[it.f] = vis[x] ^ it.s;
					qu.push(it.f);
				} else if (vis[it.f] != vis[x] ^ it.s) {
					deb1("NO")
					return;
				}
			}
		}
	}
	deb1("YES")
	dfs(1);
	for (int i = 2; i <= n; i++) {
		if (given.find({i, p[i]}) != given.end()) {
			deb3(i, p[i], (given[{i, p[i]}]))
		} else {
			deb3(i, p[i], (vis[i] ^ vis[p[i]]))
		}
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