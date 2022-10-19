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
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans += max(0, (a[i]+2*a[0]-2)/(2*a[0]-1)-1);
    }
    cout << ans << '\n';
  }
}