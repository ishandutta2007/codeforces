#include <bits/stdc++.h>

using namespace std;

int t;
long long n;

int main() {
//  freopen("in.txt", "r", stdin);
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    long long at = 1;
    while (at * (at + 1) / 2 <= n) {
      ++ans, n -= at * (at + 1) / 2, at = 2 * at + 1;
    }
    cout << ans << '\n';
  }
  return 0;
}