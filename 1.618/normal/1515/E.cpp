/*
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

#define maxn 405
int n;
ll mod, c[maxn][maxn], f[maxn][maxn];

int main() {
  scanf("%d%lld", &n, &mod);
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
    }
  }
  f[1][1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j < i; j++) {
      for (int k = 2; k < i; k++) {
        if (i - k > j)
          continue;
        (f[i][j] += f[k - 1][j - (i - k)]
          * f[i - k][i - k] % mod * c[j][i - k]) %= mod;
      }
    }
    f[i][i] = f[i - 1][i - 1] * 2 % mod;
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    (ans += f[n][i]) %= mod;
  printf("%lld\n", ans); 
  return 0;
}