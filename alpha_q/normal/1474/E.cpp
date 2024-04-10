#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int t, n, p[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    vector <int> cyc;
    int half = n >> 1;
    for (int i = half; i >= 1; --i) {
      cyc.emplace_back(i);
    }
    for (int i = half + 1; i <= n; ++i) {
      cyc.emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
      p[cyc[i]] = cyc[i + 1 < n ? i + 1 : 0];
    }
    vector <pair <int, int>> ops;
    ll ans = 0;
    for (int i = half; i > 1; --i) {
      ops.emplace_back(i, n);
      ans += (ll) (i - n) * (i - n);
    }
    for (int i = half + 1; i <= n; ++i) {
      ops.emplace_back(i, 1);
      ans += (ll) (i - 1) * (i - 1);
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) printf("%d ", p[i]); puts("");
    printf("%d\n", (int) ops.size());
    for (auto [x, y] : ops) printf("%d %d\n", x, y);
  }
  return 0;
}