#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, a[N], b[N], p[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    p[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    b[i] = p[b[i]];
    // cout << b[i] << " ";
  }
  // cout << '\n';
  int mn = b[n], ans = 0;
  for (int i = n - 1; i >= 1; --i) {
    if (b[i] > mn) ++ans;
    mn = min(mn, b[i]);
  }
  cout << ans << '\n';
  return 0;
}