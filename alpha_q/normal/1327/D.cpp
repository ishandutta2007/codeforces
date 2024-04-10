#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

bitset <N> vis;
vector <int> divs[N];
int t, n, p[N], c[N];

int main() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divs[j].emplace_back(i);
    }
  }
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", p + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", c + i);
      vis[i] = 0;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      if (vis[i]) continue;
      int at = i;
      vector <int> v;
      while (!vis[at]) vis[at] = 1, v.emplace_back(c[at]), at = p[at];
      int len = v.size();
      for (int k : divs[len]) {
        if (k >= ans) break;
        bool good = 0;
        for (int start = 0; start < k; ++start) {
          bool ok = 1;
          for (int j = start; j < len; j += k) {
            if (v[j] != v[start]) {
              ok = 0; break;
            }
          }
          if (ok) {
            good = 1; break;
          }
        }
        if (good) ans = min(ans, k);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}