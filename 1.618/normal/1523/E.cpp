/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
const ll mod = 1000000007;
ll modpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1) res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
ll inv(ll x) {
  return modpow(x, mod - 2);
}
ll fct[maxn], invFct[maxn];
ll nCr(ll x, ll y) {
  if (y < 0 || y > x)
    return 0;
  return fct[x] * invFct[y] % mod * invFct[x - y] % mod;
}

void solve() {
  ll n, k;
  scanf("%lld%lld", &n, &k);
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    (ans += nCr(n - (k - 1) * (i - 1), i) * inv(nCr(n, i))) %= mod;
  }
  printf("%lld\n", (ans + mod) % mod);
}

int main() {
  fct[0] = 1;
  for (int i = 1; i <= 100000; i++)
    fct[i] = fct[i - 1] * i % mod;
  invFct[100000] = inv(fct[100000]);
  for (int i = 100000; i >= 1; i--)
    invFct[i - 1] = invFct[i] * i % mod;
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  return 0;
}