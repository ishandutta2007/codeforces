#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 1000005;

set <int> d;
bitset <M> vis;
int t, n, a[N], b[N];

int main() {
  scanf("%d", &t);  
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        d.insert(abs(a[i] - a[j]));
      }
    }
    int j = 0;
    for (int i = 1; i < M - 4 and j < n; ++i) {
      if (vis[i]) continue;
      b[++j] = i;
      for (int x : d) {
        if (i + x < M) {
          vis[i + x] = 1;
        }
      }
    }
    vis.reset();
    d.clear();
    if (j < n) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("%d ", b[i]);
    }
    puts("");
  }
  return 0;
}