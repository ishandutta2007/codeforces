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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m, q, vis[N], a[N], b[N];
vector <int> s, t;
vector <int> adj[N];

void dfs(int x, int w) {
	vis[x] = 1;
	s.push_back(x);
	if (x == w) t = s;
	for (auto it : adj[x]) {
		if (vis[it]) continue;
		dfs(it, w);
	}
	s.pop_back();
}

vector <int> path(int x) {
	for (int i = 1; i <= n; i++) vis[i] = 0;
	dfs(1, x);
	return t;
}

void solve() {
	cin >> n >> m;
	vector <int> ct(n + 1, 0);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> a[i] >> b[i];
		ct[a[i]] ^= 1;
		ct[b[i]] ^= 1;
	}

	int total = accumulate(all(ct), 0);
	if (total == 0) {
		deb1("Yes")
		for (int i = 1; i <= q; i++) {
			vector <int> pa = path(a[i]), pb = path(b[i]);
			int c = 0;
			for (int i = 0; i < min(pb.size(), pa.size()); i++) {
				if (pa[i] == pb[i]) c++;
				else break;
			}
			reverse(all(pa));
			deb1(pa.size() + pb.size() - 2 * c + 1);
			for (int i = 0; i < pa.size() - c + 1; i++) cout << pa[i] << " ";
			for (int i = c; i < pb.size(); i++) cout << pb[i] << " ";
			newl;
		}
	} else {
		deb1("No")
		deb1(total / 2);
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}