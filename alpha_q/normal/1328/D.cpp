#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n, a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    bool all = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[i] != a[1]) all = 0;
    }
    if (all) {
      puts("1");
      for (int i = 1; i <= n; ++i) printf("1 "); puts("");
      continue;
    }
    if ((n % 2 == 0) or (a[1] == a[n])) {
      puts("2");
      for (int i = 1, col = 1; i <= n; ++i) printf("%d ", col), col = 3 - col;
      puts("");
      continue;
    }
    int pos = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i + 1]) {
        pos = i; break;
      }
    }
    if (pos == -1) {
      puts("3");
      for (int i = 1, col = 1; i < n; ++i) printf("%d ", col), col = 3 - col;
      puts("3");
    } else {
      puts("2");
      int col = 1;
      for (int i = 1; i <= pos; ++i) printf("%d ", col), col = 3 - col;
      printf("%d ", 3 - col);
      for (int i = pos + 2; i <= n; ++i) printf("%d ", col), col = 3 - col;
      puts("");
    }
  }
  return 0;
}