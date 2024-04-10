#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int t, n;
long long a[N], b[N], pos[N], neg[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      pos[i] = pos[i - 1] + (a[i] > 0);
      neg[i] = neg[i - 1] + (a[i] < 0);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", b + i);
    }
    if (a[1] != b[1]) {
      puts("NO");
      continue;
    }
    bool bad = 0;
    for (int i = n; i > 1; --i) {
      if (a[i] == b[i]) continue;
      if (a[i] < b[i]) {
        if (!pos[i - 1]) {bad = 1; break;}
      } else {
        if (!neg[i - 1]) {bad = 1; break;}
      }
    }
    puts(bad ? "NO" : "YES");
  }
  return 0;
}