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
    int l = 0;
    int r = n-1;
    while (l < n && a[l] == 0) l++;
    while (r >= 0 && a[r] == 0) r--;
    if (l == n) {
      cout << "0\n";
      continue;
    }
    int ans = 1;
    for (int i = l; i <= r; i++) {
      if (a[i] == 0) {
        ans = 2;
        break;
      }
    }
    cout << ans << '\n';
  }
}