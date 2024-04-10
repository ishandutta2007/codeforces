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

lli solve(vector <int> &a, int l, int r) {
  lli ans = 1ll << 60, now = 0;
  for (int i = l; i < r; i += 2) now += a[i];
  ans = min(ans, now);
  for (int i = r - 1; i - 1 >= l; i -= 2) {
    now += a[i] - a[i - 1];
    ans = min(ans, now);
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  fop (i,0,n) cin >> a[i];
  if (n == 1) {
    cout << a[0] << endl;
    return 0;
  }
  cout << accumulate(all(a), 0ll) - min(solve(a, 2, n - 1) + a[0], solve(a, 1, n)) << endl;
}