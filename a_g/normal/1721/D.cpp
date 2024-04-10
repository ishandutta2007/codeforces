#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    auto check = [&] (int m) {
      vector<int> ap(n), bp(n);
      for (int i = 0; i < n; i++) {
        ap[i] = a[i]&m;
      }
      for (int i = 0; i < n; i++) {
        bp[i] = (~b[i])&m;
      }
      sort(ap.begin(), ap.end());
      sort(bp.begin(), bp.end());
      return ap == bp;
    };
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
      if (check(ans|(1<<i))) ans |= 1<<i;
    }
    cout << ans << '\n';
  }
}