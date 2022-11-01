#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

pair <int, int> p[N];
int t, a, b, k, f[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d %d", &a, &b, &k);
    for (int i = 1; i <= k; ++i) scanf("%d", &p[i].first);
    for (int i = 1; i <= k; ++i) scanf("%d", &p[i].second);
    sort(p + 1, p + k + 1);
    for (int i = 1; i <= b; ++i) f[i] = 0;
    ll ans = 0;
    for (int i = 1, j = 1; i <= k; i = j) {
      while (j <= k and p[j].first == p[i].first) ++j;
      for (int it = i; it < j; ++it) {
        int gal = p[it].second;
        ans += (i - 1 - f[gal]);
      }
      for (int it = i; it < j; ++it) {
        int gal = p[it].second; ++f[gal];
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}