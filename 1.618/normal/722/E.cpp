/*
start thinking:
BULB:
result of thinking: Pure.

Endless Knightk, (1,1)-(n,m)O(k^2)(n, m >> k).
0/>=1.
0/1/.../>=logSO(logS).
O(k^2logS).
pair(x, y), f(i, j): #ij, .

start coding: 8:15
AC: 9:00

WA_on_14, B21, : dp<B, =B, <Bdp
<Bdp, B20, l.97.
*/
#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

#define maxn 100005
#define maxk 2005
const int mod = 1000000007;
const int B = 21;
int modpow(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1)
      res = (ll)res * x % mod;
    y >>= 1;
    x = (ll)x * x % mod;
  }
  return res;
}

int n, m, k, fct[maxn << 1], invfct[maxn << 1], s, f[maxk][25];
P a[maxk];

int binom(int x, int y) {
  return (ll)fct[x] * invfct[y] % mod * invfct[x - y] % mod;
}

int path(P x, P y) {
  if (x.first > y.first || x.second > y.second)
    return 0;
  return binom(y.first - x.first + y.second - x.second, y.first - x.first);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  fct[0] = 1;
  for (int i = 1; i <= 200000; i++)
    fct[i] = (ll)fct[i - 1] * i % mod;
  invfct[200000] = modpow(fct[200000], mod - 2);
  for (int i = 200000; i >= 1; i--)
    invfct[i - 1] = (ll)invfct[i] * i % mod;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 1; i <= k; i++)
    scanf("%d%d", &a[i].first, &a[i].second);
  sort(a + 1, a + k + 1);
  for (int i = 1; i <= k; i++) {
    f[i][1] = path({1, 1}, a[i]);
    for (int j = 1; j < i; j++) {
      f[i][1] = (f[i][1] - (ll)f[j][1] * path(a[j], a[i])) % mod;
    }
    for (int j = 1; j < i; j++) {
      for (int l = 2; l < B; l++) {
        f[i][l] = (f[i][l] + ll(f[j][l - 1] - f[j][l]) * path(a[j], a[i])) % mod;
      }
    }
    for (int j = 1; j < i; j++) {
      f[i][B] = (f[i][B] + (ll)f[j][B - 1] * path(a[j], a[i])) % mod;
    }
  }
  f[0][0] = path({1, 1}, {n, m});
  for (int i = 1; i <= k; i++) {
    f[0][0] = (f[0][0] - (ll)f[i][1] * path(a[i], {n, m})) % mod;
  }
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j < B; j++) {
      f[0][j] = (f[0][j] + ll(f[i][j] - f[i][j + 1]) * path(a[i], {n, m})) % mod;
    }
  }
  for (int i = 1; i <= k; i++) {
    f[0][B] = (f[0][B] + (ll)f[i][B] * path(a[i], {n, m})) % mod;
  }
  int ans = 0;
  for (int i = 0; i <= B; i++) {
    ans = (ans + (ll)s * f[0][i]) % mod;
    s = (s + 1) / 2;
  }
  printf("%lld\n", ((ll)ans * modpow(binom(n + m - 2, n - 1), mod - 2) % mod
                    + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}