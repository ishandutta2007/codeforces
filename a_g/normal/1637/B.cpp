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
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += (n+1-i)*i;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        ans += (i+1)*(n-i);
      }
    }
    cout << ans << '\n';
  }
}