/*


Q.E.D.

result of thinking: Pure. 
.
 
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 1000005
const ll mod = 998244353;
const ll inv2 = 499122177;
const ll inv6 = 166374059;
int n;
ll f[maxn], r[maxn], df[maxn];

int main() {
  scanf("%d", &n);
  f[0] = r[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = (f[i - 1] * f[i - 1] % mod * inv2 + 3 * f[i - 1] * inv2 + 1) % mod;
    r[i] = (f[i] + (f[i - 1] * f[i - 1] % mod * f[i - 1]
                    + f[i - 1] * f[i - 1] * 3
                    + f[i - 1] * 2) % mod * inv6) % mod;
  }
  ll ans = ((r[n] - r[n - 1]) * 2 - 1) % mod;
  df[0] = f[0];
  for (int i = 1; i <= n; i++)
    df[i] = f[i] - f[i - 1];
  for (int i = 1; i <= n - 2; i++) {
    (ans += (df[i] - df[i - 1]) * (df[n - 1 - i] - 1)) %= mod;
  }
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}