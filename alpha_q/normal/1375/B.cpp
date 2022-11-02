#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    bool bad = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int ok = 4, x;
        if (i + 1 > n) --ok;
        if (i - 1 < 1) --ok;
        if (j + 1 > m) --ok;
        if (j - 1 < 1) --ok;
        scanf("%d", &x);
        if (x > ok) bad = 1; 
      }
    }
    if (bad) {
      puts("NO");
      continue;
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int ok = 4, x;
        if (i + 1 > n) --ok;
        if (i - 1 < 1) --ok;
        if (j + 1 > m) --ok;
        if (j - 1 < 1) --ok;
        printf("%d ", ok);
      }
      puts("");
    }
  }
  return 0;
}