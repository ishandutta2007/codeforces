#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n, k, a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &k);
    bool bad = 1;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      if (a[i] < k) a[i] = -1;
      else if (a[i] == k) a[i] = 0, bad = 0;
      else a[i] = 1;
    }
    if (bad) {
      puts("no");
      continue;
    }
    if (n == 1) {
      puts("yes");
      continue;
    }
    bad = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] >= 0 and a[i + 1] >= 0) {
        bad = 0;
        break;
      }
    }
    for (int i = 1; i < n - 1; ++i) {
      int cnt = (a[i] >= 0) + (a[i + 1] >= 0) + (a[i + 2] >= 0);
      if (cnt >= 2) {
        bad = 0;
        break;
      }
    }
    puts(bad ? "no" : "yes");
  }
  return 0;
}