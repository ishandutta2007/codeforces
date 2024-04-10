#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n+2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      int d = a[i] - max(a[i-1], a[i+1]);
      if (d > 0) {
        a[i] -= d;
        ans += d;
      }
    }
    for (int i = 0; i <= n; i++) {
      ans += abs(a[i+1]-a[i]);
    }
    cout << ans << '\n';
  }
}