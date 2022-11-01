#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;

int t, n;
ll a[N], b[N], c[N], x[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    ll tmp = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%lld", a + i);
      tmp += a[i];
    }
    for (int i = 0; i < n; ++i) {
      scanf("%lld", b + i);
      tmp -= b[i];
    }
    if (tmp > 0) {
      puts("NO");
      continue;
    }
    tmp = -tmp;
    for (int i = 0; i < n; ++i) {
      c[i] = a[i] - b[i ? i - 1 : n - 1];
    }
    bool bad = 0;
    ll cur = b[0], mn = b[0]; x[0] = b[0];
    for (int i = 1; i < n; ++i) {
      cur += c[i];
      if (cur > b[i]) {
        ll down = cur - b[i];
        if (down > mn) {
          bad = 1;
          break;
        }
        mn -= down, cur = b[i];
      }
      if (cur < 0) {
        tmp += cur, cur = 0;
        if (tmp < 0) {
          bad = 1;
          break;
        }
      }
      x[i] = cur, mn = min(mn, x[i]);
    }
    if (bad) {
      puts("NO");
      continue;
    }
    puts("YES");
  }
  return 0;
}

// x[0], x[1], x[2]
// 0 <= x[0], x[1], x[2] <= 3
// x[0] >= x[2] - 1
// x[1] >= x[0]
// x[2] >= x[1] + 1