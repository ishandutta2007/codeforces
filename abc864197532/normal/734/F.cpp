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
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, y = 111222333, N = 500;

lli modpow(lli a, int b) {
    lli ans = 1;
    for (; b; b >>= 1, a = a * a % mod) {
        if (b & 1) ans = ans * a % mod;
    }
    return ans;
}

int main () {
  int n;
  cin >> n;
  lli a[n], b[n], c[n];
  lli all = 0;
  fop (i,0,n) cin >> b[i], all += b[i];
  fop (i,0,n) cin >> c[i], all += c[i];
  bool is = all % (2 * n) == 0;
  if (is) {
    fop (i,0,n) {
      lli now = all / (2 * n);
      if ((b[i] + c[i] - now) % n == 0) {
        a[i] = (b[i] + c[i] - now) / n;
      } else {
        is = false;
        break;
      }
    }
  }
  if (is) {
    vector <int> count(30, 0);
    fop (i,0,n) fop (j,0,30) if (a[i] & (1 << j)) count[j]++;
    bool is3 = true;
    fop (i,0,n) {
      lli tmp1 = 0, tmp2 = ((1ll << 30) - 1) * n;
      fop (j,0,30) {
        if (a[i] & (1 << j)) {
          tmp1 += (1ll << j) * count[j];
        } else {
          tmp2 -= (1ll << j) * (n - count[j]);
        }
      }
      is3 &= (tmp1 == b[i] and tmp2 == c[i]);
    }
    if (is3)  fop (i,0,n) cout << a[i] << " \n"[i == n - 1];
    else cout << -1 << endl;
  } else {
    cout << -1 << endl;
  }
}