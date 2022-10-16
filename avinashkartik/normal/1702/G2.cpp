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

struct ancestors {
    int n, level, root, tin;
    vector <vector <int>> st;
    graph g;
    vector <int> p, d, t;

    ancestors() {}
    ancestors(graph &g, int r) : n(g.n), g(g), root(r) {
    	tin = 0;
        level = log2(n) + 1;
        st.assign(n + 1, vector <int> (level, -1));
        p.assign(n + 1, 0);
        d.assign(n + 1, 0);
        t.assign(n + 1, 0);
        fillst();
    }

    void findpar(int x, int par) {
        p[x] = par;
        for (auto it : g.adj[x]) {
            if (g.v[it] == par) continue;
            d[g.v[it]] = d[x] + 1;
            findpar(g.v[it], x);
        }
        t[x] = tin++;
    }

    void fillst() {
        findpar(root, 0);
        for (int j = 0; j < level; j++) {
            for (int i = 1; i <= n; i++) {
                if (j == 0) st[i][j] = p[i];
                else if (st[i][j - 1] != -1) st[i][j] = st[st[i][j - 1]][j - 1];
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
};

int n, q;

void solve() {
	cin >> n;
	graph g(n);
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		g.add_edge(u, v);
		g.add_edge(v, u);
	}
	ancestors lca(g, 1);
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int m; cin >> m;
		vector <int> v(m);
		for (auto &it : v) cin >> it;
		if (m < 3) {
			deb1("YES")
			continue;
		}
		
		sort(all(v), [&](int i, int j) {
			return lca.t[i] < lca.t[j];
		});
		int f = 0, flag = 0, cnt = 0;
		for (int j = 1; j < m; j++) {
			int ff = lca.lca(v[0], v[j]);
			if (f == 0 && ff == v[j]) continue;
			if (f == 0) f = ff;
			else if (lca.lca(f, ff) != f) {
				flag = 1;
				deb1("NO");
				break;
			}
		}
		
		for (int j = 1; j < m; j++) {
			int ff = lca.lca(v[j - 1], v[j]);
			if (ff == v[j - 1] || ff == v[j]) continue;
			cnt++;
		}
		
		if (!flag) {
			if (cnt < 2) deb1("YES")
			else deb1("NO")
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