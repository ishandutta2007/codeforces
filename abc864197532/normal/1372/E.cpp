#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
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
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 500000, logN = 17, K = 350;

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k, l, r;
  cin >> n >> m;
  vector <pii> range[m];
  fop (i,0,n) {
    cin >> k;
    while (k--) {
      cin >> l >> r; l--;
      fop (j,l,r) range[j].eb(l, r);
    }
  }
  int dp[m + 1][m + 1];
  fop (i,0,m + 1) fop (j,0,m + 1) dp[i][j] = 0;
  for (int d = 1; d <= m; ++d) for (int i = 0; i + d <= m;++i) {
    int j = i + d;
    for (int k = i; k < j; ++k) {
      int now = 0;
      for (pii A : range[k]) now += (i <= A.X && A.Y <= j);
      dp[i][j] = max(dp[i][j], dp[i][k] + now * now + dp[k + 1][j]);
    }
  }
  cout << dp[0][m] << endl;
}