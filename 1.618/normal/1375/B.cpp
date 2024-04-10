#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <set>
#define maxn 305

using namespace std;
typedef long long ll;
int t, n, m, a[maxn][maxn];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int b = 4 - (i == 1) - (i == n) - (j == 1) - (j == m);
      if (a[i][j] > b) {
        puts("NO");
        return;
      }
      a[i][j] = b;
    }
  }
  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%d ", a[i][j]);
    }
    puts("");
  }
}
int main() {
  cin >> t;
  while (t--) solve();
  return 0;
}