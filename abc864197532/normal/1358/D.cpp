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
const int x = 864197532, N = 1000001, logN = 17;

int main () {
  int n;
  lli x;
  cin >> n >> x;
  lli a[2 * n];
  fop (i,0,n) cin >> a[i], a[i + n] = a[i];
  lli now = a[0], ans = 0, cur = (a[0] * (a[0] + 1)) / 2;
  for (int i = 0, j = 0; j < 2 * n;) {
    while (now > x) {
      now -= a[i];
      cur -= (a[i] * (a[i] + 1) / 2);
      i++;
    }
    lli tmp = 0;
    if (i) {
      lli k = x - now;
      tmp = (2ll * a[i - 1] - k + 1) * k / 2;
    }
    ans = max(ans, tmp + cur);
    j++;
    now += a[j];
    cur += (a[j] * (a[j] + 1) / 2);
  }
  cout << ans << endl;
}