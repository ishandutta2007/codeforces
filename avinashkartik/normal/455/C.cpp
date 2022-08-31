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
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

struct graph {
    int n, m;
    vector <int> v, w, vis;
    vector <vector <int>> adj;

    graph() {}
    graph(int n) : n(n), m(0) {
        adj.resize(n + 1, vector <int>());
        vis.resize(n + 1, 0);
    }

    void add_edge(int ui, int vi, int wi = 0) {
        v.push_back(vi);
        w.push_back(wi);
        adj[ui].push_back(m++);
    }
    
    void dfs(int u, int d, int par, int &p, int &mxd) {
    	if (d > mxd) {
    		mxd = d;
    		p = u;
    	}
    	vis[u] = 1;
    	for (auto i : adj[u]) {
    		if (v[i] == par) continue;
    		dfs(v[i], d + 1, u, p, mxd);
    	}
    }
};

struct union_find {
	int n, components;
	vector <int> p, sz, mx;

	union_find() : n(), components() {}

	union_find(int n) : n(n), components(n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		sz.assign(n + 1, 1);
		mx.assign(n + 1, 0);
	}

	int find(int x) {
		return (p[x] == x) ? x : p[x] = find(p[x]);
	}

	void merge(int x, int y) {
		int a = find(x);
		int b = find(y);
		if (a != b) {
			if (sz[a] >= sz[b]) swap(a, b);
			p[a] = b;
			sz[b] += sz[a];
			mx[b] = max({mx[a], mx[b], (mx[a] + 1) / 2 + (mx[b] + 1) / 2 + 1});
			components--;
		}
	}
};

int n, m, q;

void solve() {
	cin >> n >> m >> q;
	graph g(n);
	union_find dsu(n);
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
		g.add_edge(v, u);
		dsu.merge(u, v);
	}
	
	for (int i = 1; i <= n; i++) {
		if (g.vis[i]) continue;
		int par = i, d = 0;
		g.dfs(i, 0, 0, par, d);
		g.dfs(par, 0, 0, par, d);
		dsu.mx[dsu.find(i)] = d;
	}
	
	for (int i = 1; i <= q; i++) {
		int t, x, y; cin >> t;
		if (t == 2) {
			cin >> x >> y;
			dsu.merge(x, y);
		} else {
			cin >> x;
			deb1(dsu.mx[dsu.find(x)]);
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