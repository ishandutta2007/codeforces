#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    long long ans = 0;
    long long z = a[0];
    for (int i = 0; i < n-1; i++) {
      int d = a[i+1]-a[i];
      if (d > 0) {
        ans += d;
      }
      else {
        ans -= d;
        z += d;
      }
    }
    ans += abs(z);
    cout << ans << '\n';
  }
}