#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
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
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17;

vector <int> adj[N], c(N);
vector <map <int, lli>> ans(N);
vector <map <int, int>> cnt(N);
vector <int> sz(N, 1);
vector <int> now(N, -1);
vector <lli> tans(N, 0);

void dfs(int v, int pa) {
	cnt[v][c[v]]++;
	ans[v][cnt[v][c[v]]] += c[v];
	now[v] = max(now[v], cnt[v][c[v]]);
	for (int u : adj[v]) if (u != pa) {
		dfs(u, v);
		if (sz[u] > sz[v]) {
			swap(ans[u], ans[v]);
			swap(cnt[u], cnt[v]);
			swap(now[u], now[v]);
			swap(sz[u], sz[v]);
		}
		sz[v] += sz[u];
		for (auto A : cnt[u]) {
			ans[v][cnt[v][A.X]] -= A.X;
			cnt[v][A.X] += A.Y;
			ans[v][cnt[v][A.X]] += A.X;
			now[v] = max(now[v], cnt[v][A.X]);
		}
	}
	tans[v] = ans[v][now[v]];
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v;
    cin >> n;
    fop (i,0,n) cin >> c[i];
    fop (i,0,n - 1) {
    	cin >> u >> v;
    	u--; v--;
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	dfs(0, -1);
	fop (i,0,n) cout << tans[i] << " \n"[i == n - 1];
}