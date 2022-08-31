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
const ll   mod   =  1e9 + 7;
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
        v.pb(vi);
        w.pb(wi);
        adj[ui].pb(m++);
    }
};

struct ancestors {
	int n, level, root;
	graph g;
	vector <vector <int>> st, mx;
	vector <int> p, d;

	ancestors() : n() {}
	ancestors(int n, graph &g, int r) : n(n), g(g), root(r) {
		level = log2(n) + 1;
		st.assign(n + 1, vector <int> (level, -1));
		mx.assign(n + 1, vector <int> (level, -1));
		p.assign(n + 1, 0);
		d.assign(n + 1, 0);
		fillst();
	}

	void findpar(int x, int par) {
		p[x] = par;
		for (auto it : g.adj[x]) {
			if (g.v[it] == par) continue;
			mx[g.v[it]][0] = g.w[it];
			d[g.v[it]] = d[x] + 1;
			findpar(g.v[it], x);
		}
	}

	void fillst() {
		findpar(root, 0);
		for (int j = 0; j < level; j++) {
			for (int i = 1; i <= n; i++) {
				if (j == 0) st[i][j] = p[i];
				else if (st[i][j - 1] != -1) {
					st[i][j] = st[st[i][j - 1]][j - 1];
					mx[i][j] = max(mx[i][j - 1], mx[st[i][j - 1]][j - 1]);
				}
			}
		}
	}

	int kth(int x, int k) {
		for (int i = level - 1; i >= 0; i--) {
			if (k >= (1 << i)) {
				x = st[x][i];
				k -= (1 << i);
			}
		}
		return x;
	}

	int lca(int x, int y) {
		if (d[y] < d[x]) swap(x, y);
		y = kth(y, d[y] - d[x]);
		if (x == y) return x;

		for (int i = level - 1; i >= 0; i--) {
			if (st[x][i] != -1 && st[x][i] != st[y][i]) {
				x = st[x][i];
				y = st[y][i];
			}
		}
		return st[x][0];
	}

	int distance(int u, int v) {
		return d[u] + d[v] - 2 * d[lca(u, v)];
	}
	
	int maxx(int x, int k) {
		int ans = 0;
		for (int i = level - 1; i >= 0; i--) {
			if (k >= (1 << i)) {
				ans = max(ans, mx[x][i]);
				x = st[x][i];
				k -= (1 << i);
			}
		}
		return ans;
	}
};

struct union_find {
	int n, components;
	vector <int> p, sz;

	union_find() : n(), components() {}

	union_find(int n) : n(n), components(n) {
		p.assign(n + 1, 0);
		iota(p.begin(), p.end(), 0);
		sz.assign(n + 1, 1);
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
			components--;
		}
	}
};

int n, m, u[N], v[N], w[N], ans[N];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> u[i] >> v[i] >> w[i];
	vector <int> ind(m);
	iota(all(ind), 0);
	sort(all(ind), [&](int i, int j) {
		return w[i] < w[j];
	});

	graph g(n);
	union_find dsu(n);
	ll mst = 0;
	for (auto it : ind) {
		if (dsu.find(u[it]) != dsu.find(v[it])) {
			mst += w[it];
			dsu.merge(u[it], v[it]);
			g.add_edge(u[it], v[it], w[it]);
			g.add_edge(v[it], u[it], w[it]);
		}
	}

	ancestors lca(n, g, 1);
	for (int i = 0; i < m; i++) {
		int l = lca.lca(u[i], v[i]);
		ans[i] = w[i] - max(lca.maxx(u[i], lca.distance(u[i], l)), lca.maxx(v[i], lca.distance(v[i], l)));
	}

	for (int i = 0; i < m; i++) {
		deb1(ans[i] + mst)
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