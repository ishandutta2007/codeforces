#include <bits/stdc++.h>

using namespace std;

int t, n;
long long x, a[100010];

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    sort(a + 1, a + n + 1);
    int at = n + 1, ans = 0;
    long long sum = 0;
    while (at > 1 and sum + a[at - 1] >= x * (ans + 1)) sum += a[--at], ++ans;
    cout << ans << '\n';
  }
  return 0;
}