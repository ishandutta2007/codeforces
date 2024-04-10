#include <bits/stdc++.h>
using namespace std;

#define int long long


signed main() {
  int n;
  cin >> n;
  int cur = 10;
  int ans = 0;
  for (int i = 1; i <= 10; i++) {
    ans += max(0LL, min(cur - cur / 10, n - cur / 10 + 1)) * i;
    cur *= 10;
  }
  cout << ans << endl;
}