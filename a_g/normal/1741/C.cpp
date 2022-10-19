#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), s(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s[i+1] = s[i]+a[i];
    }
    int ans = n;
    for (int i = 1; i < n; i++) {
      if (s[n]%s[i] != 0) continue;
      bool ok = 1;
      for (int j = s[i]; j < s[n]; j += s[i]) {
        if (*lower_bound(s.begin(), s.end(), j) != j) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        int t = 0;
        for (int k = 0; k < s[n]; k += s[i]) {
          t = max<int>(t, lower_bound(s.begin(), s.end(), k+s[i]) - 
              lower_bound(s.begin(), s.end(), k));
        }
        ans = min(ans, t);
      }
    }
    cout << ans << '\n';
  }
}