#include <bits/stdc++.h>

using namespace std;

int t, n, x, y, od, ev;

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &x);
    od = ev = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &y);
      if (y & 1) ++od; else ++ev;
    }
    bool ok = 0;
    for (int i = 1; i <= od and i <= x; i += 2) {
      if (x - i <= ev) {
        ok = 1; break;
      }
    }
    puts(ok ? "Yes" : "No");
  }
  return 0;
}