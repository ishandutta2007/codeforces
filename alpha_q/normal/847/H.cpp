#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

int n;
ll a[N], b[N], c[N];
ll cost[N], tosc[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    b[i] = c[i] = a[i];
  }
  for (int i = 2; i <= n; ++i) {
    cost[i] = cost[i - 1];
    if (b[i] > b[i - 1]) continue;
    cost[i] += (b[i - 1] + 1 - b[i]);
    b[i] = b[i - 1] + 1;
  }
  for (int i = n - 1; i; --i) {
    tosc[i] = tosc[i + 1];
    if (c[i] > c[i + 1]) continue;
    tosc[i] += (c[i + 1] + 1 - c[i]);
    c[i] = c[i + 1] + 1;
  }
  ll ans = 1e18 + 5;
  for (int i = 1; i <= n; ++i) {
    ll now = cost[i - 1] + tosc[i + 1];
    ll mx = max(b[i - 1], c[i + 1]);
    now += max(0LL, mx + 1LL - a[i]);
    ans = min(ans, now);
  }
  printf("%lld\n", ans);
  return 0;
}