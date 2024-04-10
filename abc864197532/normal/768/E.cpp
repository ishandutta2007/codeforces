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
const int mod = 998244353, x = 864197532, N = 1 << 21, logN = 17, K = 100;

map <pair<int, lli>, int> dp;

int mex(vector <int> a) {
  sort(all(a));
  a.resize(unique(all(a)) - a.begin());
  fop (i,0,a.size()) {
    if (i ^ a[i]) return i;
  }
  return a.size();
}

int sg(int n, lli s) {
  if (n == 0) return 0;
  if (dp.count({n, s})) return dp[{n, s}];
  vector <int> v;
  fop (i,1,n + 1) if (!(s & (1 << i))) {
    v.pb(sg(n - i, s | (1 << i)));
  }
  return dp[{n, s}] = mex(v);
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, all = 0, tmp;
  cin >> n;
  fop (i,0,n) cin >> tmp, all ^= sg(tmp, 0);
  cout << (all ? "NO\n" : "YES\n") << endl;
}