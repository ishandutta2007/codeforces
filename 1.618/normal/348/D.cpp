/*
start thinking:
BULB:
result of thinking:

CF348D

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

#define maxn 3005
const int mod = 1000000007;

int n, m, f[maxn][maxn];
char s[maxn][maxn];

int calc(int sx, int sy, int tx, int ty) {
  memset(f, 0, sizeof(f));
  for (int i = sx; i <= tx; i++) {
    for (int j = sy; j <= ty; j++) {
      if (s[i][j] == '#')
        f[i][j] = 0;
      else if (i == sx && j == sy)
        f[i][j] = 1;
      else
        f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
    }
  }
  return f[tx][ty];
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.0);
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
  }
  printf("%lld\n", (((ll)calc(1, 2, n - 1, m) * calc(2, 1, n, m - 1)
            - (ll)calc(1, 2, n, m - 1) * calc(2, 1, n - 1, m)) % mod + mod) % mod);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}