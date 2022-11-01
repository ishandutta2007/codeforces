#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int n, k;
long long x, last;

int main() {
  scanf("%d %d", &n, &k);
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    scanf("%lld", &x);
    if (last > 0) {
      x += last;
      ++ans, x -= k;
      if (x > 0) {
        ans += x / k;
        last = x % k;
      } else {
        last = 0;
      }
    } else {
      ans += x / k;
      last = x % k;
    }
  }
  scanf("%lld", &x);
  x += last;
  ans += (x + k - 1) / k;
  cout << ans << '\n';
  return 0;
}