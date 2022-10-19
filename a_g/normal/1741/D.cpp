#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m;
    cin >> m;
    vector<int> p(m);
    for (int& x: p) cin >> x, x--;
    bool ok = 1;
    int ans = 0;
    while (m > 1) {
      vector<int> newp;
      for (int i = 0; i < m; i += 2) {
        if (p[i+1] == (p[i]|1)) {
          newp.push_back(p[i]>>1);
        }
        else if (p[i] == (p[i+1]|1)) {
          newp.push_back(p[i+1]>>1);
          ans++;
        }
        else {
          ok = 0;
        }
      }
      if (!ok) break;
      swap(newp, p);
      m >>= 1;
    }
    if (!ok) ans = -1;
    cout << ans << '\n';
  }
}