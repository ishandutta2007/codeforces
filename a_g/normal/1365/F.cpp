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
    if (n&1 && a[n/2] != b[n/2]) ok = 0;
    vector<pair<int, int>> sa, sb;
    for (int i = 0; i < n/2; i++) {
      int u = a[i];
      int v = a[n-1-i];
      if (u > v) swap(u, v);
      sa.emplace_back(u, v);
    }
    for (int i = 0; i < n/2; i++) {
      int u = b[i];
      int v = b[n-1-i];
      if (u > v) swap(u, v);
      sb.emplace_back(u, v);
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    if (sa != sb) ok = 0;
    cout << (ok ? "Yes" : "No") << '\n';
  }
}