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

const ll   N     =  3e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
};

ll n, a[N], add[N], subt[N];

void dfs(graph &g, int x, int p) {
	for (auto i : g.adj[x]) {
		if (g.v[i] == p) continue;
		dfs(g, g.v[i], x);
		add[x] = max(add[x], add[g.v[i]]);
		subt[x] = max(subt[x], subt[g.v[i]]);
	}
	a[x] += add[x] - subt[x];
	if (a[x] < 0) add[x] -= a[x];
	else subt[x] += a[x];
}

void solve() {
	cin >> n;
	graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
		g.add_edge(v, u);
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll ans = 0;
	dfs(g, 1, 0);
	deb1(add[1] + subt[1])
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}