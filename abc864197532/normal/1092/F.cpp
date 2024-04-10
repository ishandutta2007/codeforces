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
#define ld long double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200001, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

vector <int> adj[N];
vector <int> a(N, 0), depth(N, 0);
vector <lli> cnt(N, 0);
vector <lli> ans(N, 0);

void dfs1 (int v, int pa) {
    cnt[v] = a[v];
    depth[v] = ~pa ? depth[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        cnt[v] += cnt[u];
    }
}

void dfs2(int v, int pa) {
    if (pa == -1) {
        fop (i,0,N) ans[v] += 1ll * a[i] * depth[i];
    } else {
        ans[v] = ans[pa] + (cnt[0] - cnt[v] * 2);
    }
    for (int u : adj[v]) if (u != pa) {
        dfs2(u, v);
    }
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, u, v;
	cin >> n;
	fop (i,0,n) cin >> a[i];
	fop (i,0,n - 1) {
	    cin >> u >> v; u--; v--;
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	dfs1(0, -1);
	dfs2(0, -1);
	cout << *max_element(all(ans)) << endl;
}