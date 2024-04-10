#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int t, n, a[N];
bitset <N> vis;

int mex() {
  int ret = 0;
  for (int i = 0; i < n; ++i) vis[i] = 0;
  for (int i = 0; i < n; ++i) if (a[i] < n) vis[a[i]] = 1;
  while (ret < n and vis[ret]) ++ret; return ret;
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    vector <int> ans;
    for (int i = 0; i < n; ++i) {
      int cur = mex();
      if (cur == n) {
        bool ok = 1;
        for (int j = 0; j < n; ++j) {
          if (a[j] != j) {
            ans.emplace_back(j), a[j] = cur, ok = 0;
            break;
          }
        }
        if (ok) break; cur = mex();
      }
      ans.emplace_back(cur), a[cur] = cur;
    }
    printf("%d\n", (int) ans.size());
    for (int x : ans) printf("%d ", x + 1); puts("");
  }
  return 0;
}