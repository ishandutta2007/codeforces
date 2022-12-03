/*
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

#define maxn 405
const int mod = 1000000007;
int n, f[maxn][maxn];

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d", &n);
  f[1][0] = f[1][1] = 1;
  for (int k = 2; k <= n; k++) {
    for (int i = 0; i <= n - k + 1; i++) {
      for (int j = 0; j <= i; j++) {
        f[k][i] = (f[k][i] + (ll)f[k - 1][j] * f[k - 1][i - j]) % mod;
      }
      for (int j = 1; j <= i; j++) {
        f[k][i] = (f[k][i] + 2ll * j * (i + 1 - j) % mod 
                    * f[k - 1][j] % mod * f[k - 1][i + 1 - j]) % mod;
      }
      for (int j = 0; j <= i; j++) {
        f[k][i] = (f[k][i] + 4ll * j * f[k - 1][j] % mod * f[k - 1][i - j]) % mod;
      }
      for (int j = 0; j < i; j++) {
        f[k][i] = (f[k][i] + (ll)f[k - 1][j] * f[k - 1][i - 1 - j]) % mod;
      }
      for (int j = 2; j <= i + 1; j++) {
        f[k][i] = (f[k][i] + 2ll * j * (j - 1) % mod * f[k - 1][j] % mod 
                    * f[k - 1][i + 1 - j]) % mod;
      }
    }
  }
  printf("%d\n", (f[n][1] + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}