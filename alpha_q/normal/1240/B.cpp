#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int t, n, a[N], lt[N], rt[N], dp[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    vector <int> v;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      v.emplace_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int m = v.size();
    for (int i = 1; i <= n; ++i) {
      a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for (int i = 1; i <= m; ++i) {
      lt[i] = INT_MAX, rt[i] = INT_MIN;
    }
    for (int i = 1; i <= n; ++i) {
      lt[a[i]] = min(lt[a[i]], i);
      rt[a[i]] = max(rt[a[i]], i);
    }
    dp[m] = m;
    for (int i = m - 1; i >= 1; --i) {
      dp[i] = i;
      if (lt[i + 1] > rt[i]) dp[i] = dp[i + 1];
    }
    int ans = n;
    for (int i = 1; i <= m; ++i) {
      int j = dp[i];
      ans = min(ans, i - 1 + m - j);
    }
    printf("%d\n", ans);
  }
  return 0;
}