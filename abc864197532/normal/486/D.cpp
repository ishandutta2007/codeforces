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
const int mod = 1e9 + 7, x = 864197532, N = 2000, logN = 17;

vector <int> adj[N];
vector <int> a;
vector <lli> dp;
int n;

void dfs(int v, int pa, int l, int r) {
    dp[v] = 1;
    for (int u : adj[v]) if (u != pa && l <= a[u] && a[u] <= r) {
        dfs(u, v, l, r);
        (dp[v] *= (dp[u] + 1)) %= mod;
    }
}

lli solve(int l, int r) {
    dp.assign(n, -1);
    fop (i,0,n) if (l <= a[i] && a[i] <= r && dp[i] == -1) {
        dfs(i, -0, l, r);
    }
    lli ans = 0;
    fop (i,0,n) if (~dp[i]) (ans += dp[i]) %= mod;
    return ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int u, v, d;
    cin >> d >> n;
    a.resize(n);
    fop (i,0,n) cin >> a[i];
    fop (i,0,n - 1) {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lli ans = 0;
    fop (i,1,N + 1) {
        (ans += solve(i, i + d)) %= mod;
        (ans += mod - solve(i + 1, i + d)) %= mod;
    }
    cout << ans << endl;
}