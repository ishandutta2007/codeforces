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
const int mod = 998244353, x = 864197532, N = 2000, logN = 17;

int main () {
  int n, m;
  cin >> n >> m;
  vector <int> a(n), b(m);
  fop (i,0,n) cin >> a[i];
  fop (i,0,m) cin >> b[i];
  vector <int> p[m];
  fop (i,0,m) p[i].pb(-1);
  FOP (i,n - 1,0) {
    a[i] = min(a[i], a[i + 1]);
  }
  lli ans = 1;
  fop (i,1,m) {
    auto A = equal_range(all(a), b[i]);
    ans = ans * (A.Y - A.X) % mod;
  }
  ans *= (a[0] == b[0]);
  cout << ans << endl;
}