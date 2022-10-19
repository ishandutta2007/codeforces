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
    int s = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      s += x;
    }
    bool ok = 1;
    if (s == 0 || s == n) {
      ok = is_sorted(a.begin(), a.end());
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}