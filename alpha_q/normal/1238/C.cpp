#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int t, n; 
long long h, p[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld %d", &h, &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", p + i);
    }
    p[++n] = 0;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
      int j = i;
      while (j < n and p[j + 1] == p[j] - 1) ++j;
      if (j == n) break;
      int cnt = j - i;
      if (cnt % 2 == 0) ++ans; i = j;
    }
    printf("%d\n", ans);
  }
  return 0;
}