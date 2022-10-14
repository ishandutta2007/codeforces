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
const int mod = 998244353, x = 864197532, N = 1000087, logN = 17, K = 500;

lli modpow(lli a, int b) {
  lli ans = 1;
  for (; b; a = a * a % mod, b >>= 1) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, x, y;
  cin >> n >> q;
  vector <lli> a(n), pre(n + 1, 0);
  fop (i,0,n) cin >> a[i];
  sort(all(a));
  fop (i,0,n) pre[i + 1] = pre[i] + a[i];
  while (q--) {
    cin >> x >> y;
    int s = lower_bound(all(a), y) - a.begin(), b = n - s;
    lli alls = pre[s], allb = pre[n] - alls;
    if (b == 0) {
      cout << 0 << endl;
      continue;
    }
    lli A = allb % mod * max(b - x, 0) % mod * modpow(b, mod - 2) % mod;
    lli B = alls % mod * max(b + 1 - x, 0) % mod * modpow(b + 1, mod - 2) % mod;
    cout << (A + B) % mod << endl;
  }
}