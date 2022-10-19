#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    int ans = a[0];
    for (int i = 1; i < n; i++) {
      while (a[i] && d >= i) {
        d -= i;
        a[i]--;
        ans++;
      }
    }
    cout << ans << '\n';
  }
}