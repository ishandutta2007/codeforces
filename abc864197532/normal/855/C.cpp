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
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100087, logN = 17, K = 500;

int m, k;
vector <int> adj[N];
lli dp[N][3][11];

void dfs(int v = 0, int pa = -1) {
    fop (i,0,3) fop (j,0,11) dp[v][i][j] = 0;
    vector <lli> cha0(11, 0), cha1(11, 0), cha2(11, 0);
    cha0[0] = cha1[0] = cha2[0] = 1;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        // 0
        vector <lli> cur(11, 0);
        fop (i,0,11) fop (j,0,11) if (i + j <= 10) {
            cur[i + j] = (cur[i + j] + (dp[u][0][j] + dp[u][1][j] + dp[u][2][j]) % mod * cha0[i] % mod) % mod;
        }
        swap(cha0, cur);
        cur.assign(11, 0);
        // 1
        fop (i,0,11) fop (j,0,11) if (i + j <= 10) {
            cur[i + j] = (cur[i + j] + dp[u][0][j] * cha1[i] % mod) % mod;
        }
        swap(cha1, cur);
        cur.assign(11, 0);
        // 2
        fop (i,0,11) fop (j,0,11) if (i + j <= 10) {
            cur[i + j] = (cur[i + j] + (dp[u][0][j] + dp[u][2][j]) % mod * cha2[i] % mod) % mod;
        }
        swap(cha2, cur);
        cur.assign(11, 0);
    }
    fop (i,0,11) {
        dp[v][0][i] = cha0[i] * (k - 1) % mod;
        if (i) dp[v][1][i] = cha1[i - 1];
        dp[v][2][i] = cha2[i] * (m - k) % mod;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, u, v, x;
    cin >> n >> m;
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    cin >> k >> x;
    dfs();
    lli ans = 0;
    fop (i,0,3) fop (j,0,x + 1) ans = (ans + dp[0][i][j]) % mod;
    cout << ans << endl;
}