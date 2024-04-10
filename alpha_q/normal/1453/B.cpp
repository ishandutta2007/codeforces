#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int t, n;
long long a[N];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
    }
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
      ans += abs(a[i] - a[i + 1]);
    }
    long long maxOut = max(abs(a[1] - a[2]), abs(a[n - 1] - a[n]));
    for (int i = 2; i < n; ++i) maxOut = max(maxOut, abs(a[i] - a[i - 1]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
    ans -= maxOut;
    cout << ans << '\n';
  }
  return 0;
}