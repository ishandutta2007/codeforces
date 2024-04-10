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
    int g = *min_element(a.begin(), a.end());
    vector<int> b = a;
    sort(b.begin(), b.end());
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (b[i] != a[i] && b[i]%g != 0) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}