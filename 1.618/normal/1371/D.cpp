#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 305

using namespace std;
typedef long long ll;
int t, n, k, a[maxn][maxn];
void solve() {
  scanf("%d%d", &n, &k);
  int res = k % n ? 2 : 0;
  memset(a, 0, sizeof(a));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (k) {
        a[(i + j) % n][j] = 1;
        k--;
      }
    }
  }
  printf("%d\n", res);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d", a[i][j]);
    puts("");
  }
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}