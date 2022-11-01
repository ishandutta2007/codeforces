#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, d, a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 3; i <= n; ++i) {
      if (a[i] > d) a[i] = a[1] + a[2];
    }
    bool ok = 1;
    for (int i = 1; i <= n; ++i) {
      if (a[i] > d) {
        ok = 0;
        break;
      }
    }
    puts(ok ? "YES" : "NO");
  }
  return 0;
}