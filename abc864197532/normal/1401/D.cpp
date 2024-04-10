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
#define ld double
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 587, logN = 17;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, u, v, m;
    cin >> n;
    vector <int> adj[n], sz(n, 1);
    fop (i,0,n - 1) {
      cin >> u >> v; u--, v--;
      adj[u].pb(v);
      adj[v].pb(u);
    }
    vector <lli> cnt;
    function<void(int, int)> dfs = [&](int v, int pa) {
      for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        sz[v] += sz[u];
      }
      if (~pa) cnt.pb(1ll * sz[v] * (n - sz[v]));
    };
    dfs(0, -1);
    cin >> m;
    vector <int> p(m);
    fop (i,0,m) cin >> p[i];
    sort(all(p));
    sort(rall(cnt));
    while (p.size() > n - 1) p[n - 2] = 1ll * p[n - 2] * p.back() % mod, p.pop_back();
    reverse(all(p));
    while (p.size() < n - 1) p.pb(1);
    lli ans = 0;
    fop (i,0,n - 1) ans = (ans + cnt[i] % mod * p[i]) % mod;
    cout << ans << endl;
  }
}