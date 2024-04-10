/*
start thinking:
BULB:
result of thinking: Pure
 
f(i, 0/1, j): ij1
dpn!1*2*...*n

start coding: 21:00
AC:

: modadd; f(n, 0/1, j)j!dp2^(>1)
  O(n^2)int64.
*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast","-funroll-loops")
#pragma GCC target("sse4.1","sse4.2","ssse3","sse3","sse2","sse","avx2","avx","popcnt","tune=native")
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T> bool chmin(T& x, const T& y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T& x, const T& y) {
  return x < y ? (x = y, true) : false;
}

#define maxn 100005
const int mod = 998244353;
// f(i, 0/1, j): ij1
int k, n, a[maxn], f[2][maxn];
bool b[maxn];

int modulo(int x) { return x >= mod ? x - mod : x; }

void modadd(int &x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  for (int i = 1; i <= n; i += a[i]) {
    for (int j = i; j < i + a[i]; j++) {
      if (a[j] != a[i]) {
        puts("0");
        return 0;
      }
    }
    b[++k] = (a[i] == 1);
  }
  f[b[1]][1] = 2 - b[1];
  for (int i = 2; i <= k; i++) {
    if (b[i]) {
      for (int j = i; j >= 1; j--) {
        modadd(f[0][j], modulo(f[1][j] << 1));
        f[1][j] = modulo(f[0][j - 1] + f[1][j - 1]);
      }
    } else {
      for (int j = i; j >= 1; j--) {
        modadd(f[0][j], modulo(f[1][j] << 1));
        modadd(f[0][j], modulo(modulo(f[0][j - 1] + f[1][j - 1]) << 1));
        f[1][j] = 0;
      }
    }
  }
  ll ans = 0, fct = 1;
  for (int i = 1; i <= k; i++) {
    fct = fct * i % mod;
    if ((k ^ i) & 1)
      (ans -= (f[0][i] + f[1][i]) * fct) %= mod;
    else
      (ans += (f[0][i] + f[1][i]) * fct) %= mod;
  }
  printf("%lld\n", (ans + mod) % mod);
  return 0;
}