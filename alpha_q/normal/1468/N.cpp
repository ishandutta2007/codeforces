#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t; ll c[69], a[69];

int main() {
  cin >> t;
  while (t--) {
    for (int i = 0; i < 3; ++i) scanf("%lld", c + i);
    for (int i = 0; i < 5; ++i) scanf("%lld", a + i);
    for (int i = 0; i < 3; ++i) c[i] -= a[i];
    if (c[0] < 0 or c[1] < 0 or c[2] < 0) {
      puts("NO");
      continue;
    }
    ll tmp = min(a[3], c[0]); a[3] -= tmp, c[0] -= tmp;
    tmp = min(a[4], c[1]); a[4] -= tmp, c[1] -= tmp;
    puts(a[3] + a[4] > c[2] ? "NO" : "YES");
  }
  return 0;
}