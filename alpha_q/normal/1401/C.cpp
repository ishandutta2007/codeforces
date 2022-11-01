#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
long long a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      b[i] = a[i];
    }
    long long mn = *min_element(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    bool bad = 0;
    int m = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] % mn == 0) {
        int cur = a[i] / mn;
        a[++m] = cur;
        continue;
      }
      if (a[i] != b[i]) {
        bad = 1;
        break;
      }
    }
    if (bad) {
      puts("NO");
      continue;
    }
    puts("YES");
  }
  return 0;
}