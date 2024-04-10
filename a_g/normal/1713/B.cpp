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
    bool ok = 1;
    bool decr = 0;
    for (int i = 0; i < n-1; i++) {
      if (a[i+1]-a[i] > 0) {
        if (decr) ok = 0;
      }
      else if (a[i+1]-a[i] < 0) {
        decr = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}