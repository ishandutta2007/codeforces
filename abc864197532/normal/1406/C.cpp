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
const int mod = 1e9 + 7, x = 864197532, N = 50087, logN = 17, K = 222;

void solve() {
    int n, u, v;
    cin >> n;
    vector <int> adj[n];
    fop (i,0,n - 1) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector <int> sz(n, 1), mxcc(n, 0), leaf(n, 0);
    function<void(int, int)> dfs_sz = [&](int v, int pa) {
        bool is = true;
        for (int u : adj[v]) if (u != pa) {
            dfs_sz(u, v);
            is = false;
            sz[v] += sz[u];
            mxcc[v] = max(mxcc[v], sz[u]);
            leaf[v] = leaf[u];
        }
        if (is) leaf[v] = v;
        mxcc[v] = max(mxcc[v], n - sz[v]);
    };
    dfs_sz(0, -1);
    int mn = *min_element(all(mxcc));
    vector <int> cen;
    fop (i,0,n) if (mxcc[i] == mn) cen.pb(i);
    if (cen.size() == 1) {
        cout << 1 << ' ' << adj[0][0] + 1 << endl;
        cout << 1 << ' ' << adj[0][0] + 1 << endl;
    } else {
        int u = cen[0], v = cen[1];
        sz.assign(n, 1);
        dfs_sz(u, -1);
        int p = -1, q;
        for (int k : adj[u]) {
            if (!~p || sz[p] < sz[k]) p = k;
        }
        sz.assign(n, 1);
        dfs_sz(p, -1);
        for (int k : adj[p]) {
            if (k != u) {
                q = leaf[k];
                break;
            }
        }
        cout << q + 1 << ' ' << adj[q][0] + 1 << endl;
        cout << q + 1 << ' ' << u + 1 << endl;
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}