#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x;
#define print(a) {\
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
const int mod = 998244353, x = 864197532, N = 100087;

int dsu[N];

int find(int v) {
    if (dsu[v] == v) return v; 
    return dsu[v] = find(dsu[v]);
}

bool Union(int u, int v) {
    int x = find(u), y = find(v);
    if (x == y) return false;
    dsu[x] = y;
    return true;
}

int main () {
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    int id[n], now = 0, tmp[k];
    fop (i,0,k) {
        cin >> tmp[i];
        fop (j,now,now+tmp[i]) id[j] = i;
        now += tmp[i];
    }
    int dp[k][k];
    fop (i,0,n) dsu[i] = i;
    fop (i,0,k) fop (j,0,k) dp[i][j] = i == j ? 0 : x;
    fop (i,0,m) {
        cin >> u >> v >> w;
        u--; v--;
        dp[id[u]][id[v]] = min(dp[id[u]][id[v]], w);
        dp[id[v]][id[u]] = min(dp[id[v]][id[u]], w);
        if (w == 0) Union(u, v);
    }
    now = 0;
    bool is = true;
    fop (i,0,k) {
        vector <int> aa;
        fop (j,now,now+tmp[i]) aa.pb(find(j));
        sort(all(aa));
        if (unique(all(aa)) - aa.begin() != 1) is = false;
        now += tmp[i];
    }
    if (!is) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        fop (l,0,k) fop (i,0,k) fop (j,0,k) {
            dp[i][j] = min(dp[i][j], dp[i][l] + dp[l][j]);
        }
        fop (i,0,k) fop (j,0,k) cout << (dp[i][j] == x ? -1 : dp[i][j]) << " \n"[j == k - 1]; 
    }
}