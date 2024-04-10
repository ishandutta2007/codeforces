#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pdd pair<ld,ld> 
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int x = 864197532, N = 200087, logN = 18;

vector <int> adj[N], W[N];
int vertex[N][logN], va[N][logN];
int in[N], out[N], depth[N], t = 0;

void dfs(int v, int pa, int w) {
	in[v] = t++;
	vertex[v][0] = pa;
	va[v][0] = w;
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	fop (i,0,adj[v].size()) if (adj[v][i] != pa) {
		dfs(adj[v][i], v, W[v][i]);
	}
	out[v] = t++;
}

void build_lca() {
	for (int i = 0; i < N; ++i) vertex[i][0] = -1, va[i][0] = -1;
	dfs(0, -1, -1);
	for (int i = 1; i < logN; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = vertex[j][i - 1];
            if (k != -1) vertex[j][i] = vertex[k][i - 1], va[j][i] = max(va[k][i - 1], va[j][i - 1]);
        }
    }
}

int lca(int u, int v) {
	if (in[u] <= in[v] and out[u] >= out[v]) return u;
	if (in[v] <= in[u] and out[v] >= out[u]) return v;
	for (int i = logN - 1; i >= 0; --i) {
		int k = vertex[u][i];
		if (k != -1 and !(in[k] <= in[v] and out[k] >= out[v])) u = k;
	}
	return vertex[u][0];
}

int ask(int u, int k) {
    int now = 0;
    FOP (i,logN,0) {
        if (k & (1 << i)) {
            now = max(now, va[u][i]);
            u = vertex[u][i];
        }
    }
    return now;
}

int length(int u, int v) {
	int k = lca(u, v);
	return max(ask(u, depth[u] - depth[k]), ask(v, depth[v] - depth[k]));
}

struct Dsu {
	int n;
	vector <int> dsu, size;
	Dsu (int n): n(n) {
		dsu.resize(n);
		size.resize(n);
		for (int i = 0; i < n; ++i) {
			dsu[i] = i;
			size[i] = 1;
		}
	}
	int Find(int a) {
		if (dsu[a] == a) return a;
		return dsu[a] = Find(dsu[a]);
	}
	bool Union(int a, int b) {
		int x = Find(a), y = Find(b);
		if (x == y) return false;
		if (size[x] < size[y]) swap(x, y);
		dsu[y] = x;
		size[x] += size[y];
		size[y] = 0;
		return true;
	}
};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector <pair<pair<int, pii>, int>> edges(m);
	fop (i,0,m) {
	    cin >> edges[i].X.Y.X >> edges[i].X.Y.Y >> edges[i].X.X;
	    edges[i].X.Y.X--; edges[i].X.Y.Y--;
	    edges[i].Y = i;
	}
	Dsu dsu(n);
	sort(all(edges));
	vector <bool> in_tree(m, false);
	lli ans = 0;
    fop (i,0,m) {
        bool is = dsu.Union(edges[i].X.Y.X, edges[i].X.Y.Y);
        if (is) {
            adj[edges[i].X.Y.X].pb(edges[i].X.Y.Y);
            adj[edges[i].X.Y.Y].pb(edges[i].X.Y.X);
            W[edges[i].X.Y.X].pb(edges[i].X.X);
            W[edges[i].X.Y.Y].pb(edges[i].X.X);
            in_tree[i] = true;
            ans += edges[i].X.X;
        }
    }
    build_lca();
    vector <lli> anss(m);
    fop (i,0,m) {
        if (in_tree[i]) {
            anss[edges[i].Y] = ans;
        } else {
            anss[edges[i].Y] = ans + edges[i].X.X - length(edges[i].X.Y.X, edges[i].X.Y.Y);
        }
    }
    for (lli i : anss) cout << i << '\n';
}