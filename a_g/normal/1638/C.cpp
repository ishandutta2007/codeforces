#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      mx = max(mx, a);
      if (mx == i) ans++;
    }
    cout << ans << '\n';
  }
}