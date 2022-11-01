#include <bits/stdc++.h>

using namespace std;

int t, n, k;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int ans = 0;
    if (n < k) ans += k - n, n = k;
    if ((n + k) & 1) ++ans;
    cout << ans << '\n';
  }
  return 0;
}

// OB + BA = n 
// OB - BA = k
// --> n + k even, n >= k