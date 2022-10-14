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
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 200000, logN = 17, K = 350;

vector <pii> adj[N];

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, u, v, w;
    lli all = 0;
    cin >> n >> m >> k;
    vector <lli> ha(n);
    fop (i,0,n) ha[i] = uniform_int_distribution<lli>(0ll, (1ll << 60) - 1)(rng), all ^= ha[i];
    fop (i,0,m) {
        cin >> u >> v >> w; u--; v--;
        adj[u].eb(w, v);
    }
    lli pre[k][k];
    fop (i,0,k) fop (j,0,k) pre[i][j] = 0;
    fop (i,0,n) {
        sort(all(adj[i]));
        int a = adj[i].size();
        fop (j,0,a) {
            pre[a - 1][j] ^= ha[adj[i][j].Y];
        }
    }
    int ans = 0;
    vector <int> p(k, 0);
    while (true) {
        lli cur = 0;
        fop (i,0,k) cur ^= pre[i][p[i]];
        if (cur == all) ans++;
        int now = k - 1;
        while (~now) {
            p[now]++;
            if (p[now] <= now) break;
            p[now--] = 0;
        }
        if (now == -1) break;
    }
    cout << ans << endl;
}