#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, a[105], x, ans;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    x = 0;
    ans = 1;
    for (i = 0; i < n; i++) {
      if (a[i] == 0) {
        x++;
        if (x == 2) {
          ans = -1;
          break;
        }
      } else {
        x = 0;
        if (i < n - 1 && a[i + 1] == 1) {
          ans += 5;
        } else {
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}