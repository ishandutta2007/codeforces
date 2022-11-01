#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int t, n, a[N], b[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    int zero = 0, one = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", b + i);
      if (b[i]) one = 1; else zero = 1;
    }
    if (zero and one) {
      puts("Yes");
    } else {
      bool good = 1;
      for (int i = 1; i < n; ++i) if (a[i + 1] < a[i]) {
        good = 0; break;
      }
      puts(good ? "Yes" : "No");
    }
  }
  return 0;
}