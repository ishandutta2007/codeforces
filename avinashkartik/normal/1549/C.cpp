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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
set <int> adj[N], vul;

void add(int u, int v) {
	if (u > v) swap(u, v);
	if (vul.find(u) == vul.end()) vul.insert(u);
	adj[u].insert(v);
	adj[v].insert(u);
}

void rem(int u, int v) {
	if (u > v) swap(u, v);
	adj[u].erase(v);
	adj[v].erase(u);
	if (adj[u].size() == 0) vul.erase(u);
	else {
		auto it = adj[u].rbegin();
		if (*it < u) vul.erase(u);
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		add(u, v);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; cin >> w;
		if (w == 3) {
			deb1(n - vul.size())
		} else {
			cin >> u >> v;
			if (w == 1) add(u, v);
			else rem(u, v);
		}
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