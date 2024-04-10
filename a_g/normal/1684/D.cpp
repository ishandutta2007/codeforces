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
    long long tot = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      tot += x;
      a[i] = (n-1-i)-x;
    }
    sort(a.begin(), a.end());
    long long ans = tot;
    for (int j = 1; j <= k; j++) {
      tot += a[j-1];
      tot -= (j-1);
      ans = min(ans, tot);
    }
    cout << ans << '\n';
  }
}