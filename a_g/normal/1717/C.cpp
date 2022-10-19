#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& x: a) cin >> x;
    for (int& x: b) cin >> x;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (b[i] < a[i]) ok = 0;
      if (a[i] < b[i] && b[i] > b[(i+1)%n]+1) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}