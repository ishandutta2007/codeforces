#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int t, n, a[N], f[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i); ++f[a[i]];
    }
    int at = 0;
    while (f[at]) --f[at], ++at;
    int ans = at; at = 0;
    while (f[at]) --f[at], ++at;
    ans += at;
    cout << ans << '\n';
  }
  return 0;
}