#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int ans = 1e9;
    for (int l = a[0]; l >= 0; l--) {
      int low = 1e9;
      int high = 0;
      for (int x: a) {
        int p = (l ? x/l : x+1);
        p = min(p, k);
        low = min(low, x/p);
        high = max(high, x/p);
      }
      ans = min(ans, high-low);
    }
    cout << ans << '\n';
  }
}