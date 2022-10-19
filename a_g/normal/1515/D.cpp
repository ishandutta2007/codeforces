#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, l, r;
    cin >> n >> l >> r;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      c--;
      a[c] += (i < l ? 1 : -1);
    }
    int d = r-l;
    for (int &x: a) {
      while (x >= 2 && d < 0) {
        d += 2;
        x -= 2;
        ans++;
      }
      while (x <= -2 && d > 0) {
        d -= 2;
        x += 2;
        ans++;
      }
    }
    for (int &x: a) {
      if (x >= 1 && d < 0) {
        d += 2;
        x -= 2;
        ans++;
      }
      else if (x <= -1 && d > 0) {
        d -= 2;
        x += 2;
        ans++;
      }
      if (x > 0) ans += x;
    }

    assert(!d);

    cout << ans << '\n';
  }
}