#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

map <int, vector <int>> f;
int n, a[N], b[N], rev[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    rev[b[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    a[i] = rev[a[i]], a[n + i] = a[i];
  }
  for (int i = 1; i <= n + n; ++i) {
    a[i] = i + 1 - a[i];
    f[a[i]].emplace_back(i);
  }
  int ans = 0;
  for (int k = 1; k <= n; ++k) {
    int cur = upper_bound(f[k].begin(), f[k].end(), k + n - 1) - lower_bound(f[k].begin(), f[k].end(), k);
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}