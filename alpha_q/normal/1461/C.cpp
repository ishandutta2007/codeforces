#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

double p[N];
int t, n, m, a[N], r[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d %lf", r + i, p + i);
    }
    int firstBad = n;
    while (firstBad and a[firstBad] == firstBad) --firstBad;
    if (!firstBad) {
      puts("1");
      continue;
    }
    long double ans = 1;
    for (int i = 1; i <= m; ++i) {
      if (r[i] >= firstBad) ans *= 1 - p[i];
    }
    ans = 1 - ans;
    printf("%0.16f\n", (double) ans);
  }
  return 0;
}