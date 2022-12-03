#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 28
using namespace std;
typedef long long ll;
typedef long double ldouble;

int n, q;
ll a[maxn][maxn], k;

void solve() {
  scanf("%lld", &k);
  int x = 0, y = 0;
  printf("%d %d\n", x + 1, y + 1);
  fflush(stdout);
  for (ll i = 1; i < n + n - 2; i++) {
    ll col = (k & (1ll << i));
    if (x < n - 1 && a[x + 1][y] == col) x++;
    else y++;
    printf("%d %d\n", x + 1, y + 1);
    fflush(stdout);
  }
  printf("%d %d\n", n, n);
  fflush(stdout);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i += 2) {
    for (int j = 0; j < n - i; j++) a[i][j] = (1ll << (i + j));
    for (int j = i; j < n; j++) a[j][n - i - 1] = (1ll << (j + n - i - 1));
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%lld%c", a[i][j], j == n - 1 ? '\n' : ' ');
    }
    fflush(stdout);
  }
  scanf("%d", &q);
  while (q--) solve();
  return 0;
}