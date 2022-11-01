#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

ll k, p[N], lcm;
int t, n, x, a, y, b;

bool ok (int s) {
  ll cur = 0; int at = 1;
  for (ll i = lcm; i <= s; i += lcm) {
    cur += (x + y) * p[at++];
  }
  for (ll i = a; i <= s; i += a) {
    if (i % lcm == 0) continue;
    cur += x * p[at++];
  }
  for (ll i = b; i <= s; i += b) {
    if (i % lcm == 0) continue;
    cur += y * p[at++];
  }
  return cur >= k;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", p + i);
      p[i] /= 100;
    }
    sort(p + 1, p + n + 1, greater <ll> ());
    scanf("%d %d %d %d %lld", &x, &a, &y, &b, &k);
    if (x < y) swap(x, y), swap(a, b);
    lcm = a * 1LL * b / __gcd(a, b);
    int lo = 0, hi = n;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      if (ok(mid)) hi = mid;
      else lo = mid + 1;
    }
    if (!ok(lo)) lo = -1;
    printf("%d\n", lo);
  }
  return 0;
}