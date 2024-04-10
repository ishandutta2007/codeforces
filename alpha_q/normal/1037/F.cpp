#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 1000005;
const int MOD = 1e9 + 7;

ll a[N];
set <int> done;
int n, k, id[N];

bool cmp (int i, int j) {
  return a[i] > a[j];
}

int main() {
  scanf("%d %d", &n, &k); --k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    id[i] = i;
  }
  sort(id + 1, id + n + 1, cmp);
  ll ans = 0;
  done.insert(0);
  done.insert(n + 1);
  for (int j = 1; j <= n; ++j) {
    int i = id[j];
    auto it = done.lower_bound(i);
    int y = *it - 1, x = *(--it) + 1;
    if (i - x < y - i) {
      for (int p = x; p <= i; ++p) {
        int l = max(1, (i - p + k - 1) / k);
        int r = (y - p) / k;
        if (l <= r) ans += (r - l + 1) * a[i], ans %= MOD; 
      }
    } else {
      for (int p = i; p <= y; ++p) {
        int l = max(1, (p - i + k - 1) / k);
        int r = (p - x) / k;
        if (l <= r) ans += (r - l + 1) * a[i], ans %= MOD;
      }
    }
    done.insert(i);
  }
  printf("%lld\n", ans);
  return 0;
}