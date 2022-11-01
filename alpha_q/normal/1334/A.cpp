#include <bits/stdc++.h>

using namespace std;

int t, n, a[6969], b[6969];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d %d", a + i, b + i);
    }
    bool bad = 0;
    for (int i = 1; i <= n; ++i) {
      if (i < n and a[i + 1] < a[i]) {
        bad = 1; break;
      }
      if (i < n and b[i + 1] < b[i]) {
        bad = 1; break;
      }
      if (i < n and a[i + 1] - a[i] < b[i + 1] - b[i]) {
        bad = 1; break;
      }
      if (a[i] < b[i]) {
        bad = 1; break;
      }
    }
    puts(bad ? "NO" : "YES");
  }
  return 0;
}