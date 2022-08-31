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

const ll   N     =  5e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, u[N], v[N];
vector <int> adj[N];
map <pair <int, int>, int> m;

void dfs(int x, int p, int f) {
	if (f == 0) m[{x, p}] = m[{p, x}] = 2;
	else m[{x, p}] = m[{p, x}] = 3;
	for (auto it : adj[x]) {
		if (it == p) continue;
		dfs(it, x, 1 - f);
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) adj[i].clear();
	m.clear();

	for (int i = 1; i < n; i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].pb(v[i]);
		adj[v[i]].pb(u[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() > 2) {
			deb1(-1)
			return;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			dfs(i, 0, 0);
			break;
		}
	}

	for (int i = 1; i < n; i++) cout << m[{u[i], v[i]}] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}