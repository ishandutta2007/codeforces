/*


Q.E.D.

start thinking:
BULB:
result of thinking:

start coding:
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

#define maxn 25
#define maxm 50005
const ll mod = 998244353;
int n, m, d[maxn][maxm];
ll fct[maxn];

ll modpow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = res * x % mod;
    y >>= 1;
    x = x * x % mod;
  }
  return res;
}
ll inv(ll x) {
  return modpow(x, mod - 2);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &d[i][j]);
    }
  }
  fct[0] = 1;
  for (int i = 1; i <= n; i++)
    fct[i] = fct[i - 1] * i % mod;
  ll ans = 0;
  for (int i = 1; i <= m; i++) {
    vector<int> ds;
    for (int j = 1; j <= n; j++)
      ds.push_back(d[j][i]);
    sort(ds.begin(), ds.end());
    ll bad = 1;
    for (int j = 0; j < n; j++) {
      if (ds[j] <= j + 1)
        bad = 0;
      else
        (bad *= ds[j] - 1 - j) %= mod;
    }
    (ans += fct[n] - bad) %= mod;
  }
  (ans *= inv(fct[n])) %= mod;
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}