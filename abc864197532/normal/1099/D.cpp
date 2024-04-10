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
const int x = 864197532, N = 100001, logN = 17, K = 1000;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, v;
  cin >> n;
  vector <int> adj[n], p(n);
  fop (i,1,n) cin >> p[i], p[i]--;
  vector <int> s(n, -1), now(n, 1 << 30);
  fop (i,0,n) cin >> s[i];
  fop (i,1,n) {
    if (s[i] != -1)
      adj[p[p[i]]].pb(i);
  }

  function<void(int)> dfs = [&](int v) {
    if (v)
      now[p[v]] = min(now[p[v]], s[v] - s[p[p[v]]]);
    for (int u : adj[v])
      dfs(u);
  };

  dfs(0);
  fop (i,0,n) {
    if (s[i] == -1) {
      if (now[i] < 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  lli ans = 0;
  fop (i,0,n) {
    if (s[i] == -1) {
      ans += (now[i] == 1 << 30 ? 0 : now[i]);
    } else {
      ans += (s[i] - (i ? s[p[p[i]]] + now[p[i]] : 0));
    }
  }
  cout << ans << endl;
}