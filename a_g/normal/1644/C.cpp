#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> pref(n+1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pref[i+1] = pref[i] + a[i];
    }
    vector<int> best(n+1, -INF);
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j+i <= n; j++) {
        best[i] = max(best[i], pref[j+i]-pref[j]);
      }
    }
    for (int k = 0; k <= n; k++) {
      int ans = 0;
      for (int j = 0; j <= n; j++) {
        ans = max(ans, best[j]+min(k, j)*x);
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
}