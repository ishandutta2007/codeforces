#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, a[N];
bitset <N> vis;

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    for (int j = i; j <= n; ++j) {
      if (a[j] % a[i] == 0) vis[j] = 1;
    }
    ++ans;
  }
  cout << ans << '\n';
  return 0;
}