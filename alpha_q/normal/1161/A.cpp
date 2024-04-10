#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

set <int> s;
int n, k, a[N], f[N], l[N];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    f[i] = k + k; l[i] = -k;
  }
  for (int i = 1; i <= k; ++i) {
    scanf("%d", a + i);
    s.emplace(a[i]);
    f[a[i]] = min(f[a[i]], i);
    l[a[i]] = max(l[a[i]], i);
  }
  int ans = n - s.size();
  for (int i = 1; i <= n; ++i) {
    if (i > 1) {
      int j = i - 1;
      if (f[i] >= l[j]) ++ans;
    } if (i < n) {
      int j = i + 1;
      if (f[i] >= l[j]) ++ans;
    }
  }
  cout << ans << endl;
  return 0;
}