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
    vector<pair<int, int>> ans;
    if (a[0] != a[n-1]) {
      ans.emplace_back(0, n-1);
      if (a[0]%2 == a[n-1]%2) {
        a[0] = a[n-1];
      }
      else {
        a[n-1] = a[0];
      }
    }
    for (int i = 1; i < n; i++) {
      if (a[i]%2 != a[0]%2) {
        ans.emplace_back(0, i);
        a[i] = a[0];
      }
    }
    for (int i = 0; i < n-1; i++) {
      if (a[i] != a[n-1]) {
        ans.emplace_back(i, n-1);
        a[i] = a[n-1];
      }
    }
    cout << ans.size() << '\n';
    for (auto& [l, r]: ans) {
      cout << l+1 << ' ' << r+1 << '\n';
    }
  }
}