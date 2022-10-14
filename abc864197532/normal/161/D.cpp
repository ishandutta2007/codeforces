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
const int mod = 998244353, x = 864197532, N = 50000, logN = 16;

vector <int> adj[N], cdadj[N];
vector <int> sz(N, 0), cd_pa(N, -1);
map <int, int> now[N], tmp[N];
int cd_root = -1;
lli ans = 0;
int vertex[N][logN]; // vertex[i][j]= 2^j 
int in[N], out[N], depth[N], t = 0;

void dfs(int v, int pa) {
	in[v] = t++;
	vertex[v][0] = pa;
	depth[v] = ~pa ? depth[pa] + 1 : 0;
	for (int u : adj[v]) if (u != pa) {
		dfs(u, v);
	}
	out[v] = t++;
}

void build_lca() {
	for (int i = 0; i < N; ++i) vertex[i][0] = -1;
	dfs(0, -1);
	for (int i = 1; i < logN; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = vertex[j][i - 1];
            if (k != -1) vertex[j][i] = vertex[k][i - 1];
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

int length(int u, int v) {
	int k = lca(u, v);
	return depth[u] + depth[v] - 2 * depth[k];
}
void dfs1 (int v, int pa) { // count size
	sz[v] = 1;
	for (int u : adj[v]) if (u != pa and cd_pa[u] == -1) {
		dfs1(u, v);
		sz[v] += sz[u];
	}
}

int dfs2 (int v, int pa, int n) { // find cd
	for (int u : adj[v]) if (u != pa and cd_pa[u] == -1 and sz[u] > n / 2) {
		return dfs2(u, v, n);
	}
	return v;
}

void cd (int v, int pa) { // build cdt
	dfs1(v, pa);
	int c = dfs2(v, pa, sz[v]);
	cd_pa[c] = ~pa ? pa : -2;
	for (int u : adj[c]) if (cd_pa[u] == -1) {
		cd(u, c);
	}
    if (pa == -1) {
    	cd_pa[c] = -1;
		cd_root = c;
	} else {
    	cdadj[pa].pb(c);
    	cdadj[c].pb(pa);
	}
}

void dfs3(int v, int pa, int l) {
	for (int u : cdadj[v]) if (u != pa) {
		dfs3(u, v, l);
		for (auto A : tmp[v]) {
			now[v][A.X] += A.Y;
		}
		tmp[v].clear();
	}
	int k = v;
	while (k != -1) {
		int kk = length(v, k);
		tmp[k][kk]++;
		if (now[k].count(l - kk)) ans += now[k][l - kk];
		k = cd_pa[k];
	}
}
/*
5 2
1 2
2 3
3 4
2 5
*/
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, u, v;
	cin >> n >> k;
	fop (i,0,n - 1) {
		cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cd(0, -1);
	build_lca();
	dfs3(cd_root, -1, k);
	cout << ans << endl;
}