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
const int mod = 998244353, x = 864197532, N = 200087;

lli frac[N], fracp[N];

lli modpow(lli a, int b) {
  lli ans = 1;
  for (; b; b >>= 1, a = a * a % mod) {
    if (b & 1) ans = ans * a % mod;
  }
  return ans;
}

lli C(int n, int m) {
  return frac[n] * fracp[m] % mod * fracp[n - m] % mod;
}

int main () {
  frac[0] = fracp[0] = 1;
  fop (i,1,N) frac[i] = frac[i - 1] * i % mod;
  fop (i,1,N) fracp[i] = modpow(frac[i], mod - 2);
  int n;
  lli k;
  cin >> n >> k;
  lli ans = (k == 0 ? 1 : 2);
  if (k >= n) cout << 0 << endl;
  else {
    ans = ans * C(n, k) % mod;
    lli tmp = 0;
    FOP (i,n-k+1,1) {
      lli aa = modpow(i, n) * C(n - k, i) % mod;
      if (i % 2 == (n - k) % 2) tmp = (tmp + aa) % mod;
      else tmp = (tmp + mod - aa) % mod;
    }
    cout << ans * tmp % mod << endl;
  }
}