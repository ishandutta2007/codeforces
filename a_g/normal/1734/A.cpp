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
    sort(a.begin(), a.end());
    int ans = 2e9;
    for (int i = 1; i < n-1; i++) {
      ans = min(ans, a[i+1]-a[i-1]);
    }
    cout << ans << '\n';
  }
}