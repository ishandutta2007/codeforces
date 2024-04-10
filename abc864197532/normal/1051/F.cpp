#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 100000, logN = 17, K = 350;

vector <pii> adj[N];

struct dijkstra {
	int v;
	vector <lli> dis;
	void build() {
	    dis.assign(N, 1ll << 60);
        priority_queue <pair <lli, int>, vector <pair <lli, int>>, greater <pair <lli, int>>> pq;
		dis[v] = 0;
		pq.push({dis[v], v});
		while (pq.size()) {
			lli d;
			int v;
			tie(d, v) = pq.top(); pq.pop();
			if (dis[v] < d) continue;
			for (pii A : adj[v]) if (dis[A.X] > dis[v] + A.Y) {
				dis[A.X] = dis[v] + A.Y;
				pq.push({dis[A.X], A.X});
			}
		}
	}
};

int in[N], out[N], t = 0, jump[N][logN];
lli depth[N];
vector <dijkstra> dij;

void dfs(int v, int pa, int w) {
	depth[v] = ~pa ? depth[pa] + w : 0;
	jump[v][0] = pa; 
	in[v] = t++;
	for (pii A : adj[v]) if (A.X != pa) {
		if (in[A.X] == -1) {
			dfs(A.X, v, A.Y);
		} else if (depth[v] > depth[A.X]) {
			dij.pb({});
			dij.back().v = A.X;
            dij.back().build();
		}
	}
	out[v] = t++;
}

void build_lca() {
	fop (i,0,N) fop (j,0,logN) jump[i][j] = -1;
	fop (i,0,N) in[i] = out[i] = -1;
	dfs(0, -1, 0);
	fop (i,1,logN) {
		fop (j,0,N) {
			int k = jump[j][i - 1];
			if (~k) jump[j][i] = jump[k][i - 1];
		}
	}
}

int lca(int u, int v) {
	if (in[u] <= in[v] && out[u] >= out[v]) return u;
	if (in[v] <= in[u] && out[v] >= out[u]) return v;
	FOP (i,logN,0) {
		int k = jump[u][i];
		if (~k) {
			if (!(in[k] <= in[v] && out[k] >= out[v])) u = k;
		}
	}
	return jump[u][0];
}

lli get(int u, int v) {
	int k = lca(u, v);
	return depth[u] + depth[v] - depth[k] * 2;
}
	
int main () {
	int n, m, u, v, w, uu, vv, ww, q;
	cin >> n >> m;
	fop (i,0,m) {
		cin >> u >> v >> w; u--; v--;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	fop (i,0,n) random_shuffle(all(adj[i]));
	build_lca();
	int nn = dij.size();
	cin >> q;
	lli ans = 0;
	while (q--) {
		cin >> u >> v; u--; v--;
		ans = get(u, v);
		fop (i,0,nn) {
			ans = min(ans, dij[i].dis[v] + dij[i].dis[u]);
		}
		cout << ans << '\n';
	}
}