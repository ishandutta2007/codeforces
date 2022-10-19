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
    for (int& x: a) cin >> x;
    if (k == 1) {
      cout << (n-1)/2 << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 1; i < n-1; i++) {
      if (a[i] > a[i-1] + a[i+1]) ans++;
    }
    cout << ans << '\n';
  }
}