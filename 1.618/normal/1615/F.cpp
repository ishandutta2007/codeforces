/*
start thinking:
BULB:
result of thinking: Lost.

: 0100<->11, ?, .

.
00, 11flip01. /ll.
trivial: f(i, j) / g(i, j)s[1:i], t[1:j]1,  / 

start coding: 19:50
AC: 20:08
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

#define maxn 2005
const int mod = 1000000007;

int n, f[maxn][maxn], g[maxn][maxn];
char s[maxn], t[maxn];

void solve() {
  scanf("%d%s%s", &n, s + 1, t + 1);
  for (int i = 2; i <= n; i += 2) {
    if (s[i] != '?')
      s[i] = '0' + '1' - s[i];
    if (t[i] != '?')
      t[i] = '0' + '1' - t[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++)
      f[i][j] = g[i][j] = 0;
  }
  f[0][0] = 1, g[0][0] = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (i && s[i] != '1') {
        (f[i][j] += f[i - 1][j]) %= mod;
        (g[i][j] += g[i - 1][j]) %= mod;
      }
      if (j && t[j] != '1') {
        (f[i][j] += f[i][j - 1]) %= mod;
        (g[i][j] += g[i][j - 1]) %= mod;
      }
      if (i && s[i] != '1' && j && t[j] != '1') {
        (f[i][j] -= f[i - 1][j - 1]) %= mod;
        (g[i][j] -= g[i - 1][j - 1]) %= mod;
      }
      if (i && s[i] != '0' && j && t[j] != '0') {
        (f[i][j] += f[i - 1][j - 1]) %= mod;
        g[i][j] = (g[i][j] + g[i - 1][j - 1] + abs(i - j) * (ll)f[i - 1][j - 1]) % mod;
      }
    }
  }
  printf("%d\n", (g[n][n] + mod) % mod);
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  int t;
  scanf("%d", &t);
  while (t--)
    solve();
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}