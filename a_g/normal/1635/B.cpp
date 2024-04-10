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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    for (int i = 1; i < n-1; i++) {
      if (a[i] > a[i-1] && a[i] > a[i+1]) {
        b.push_back(i);
      }
    }
    int ans = 0;
    while (!b.empty()) {
      int j = b.back();
      b.pop_back();
      ans++;
      if (!b.empty() && b.back() == j-2) {
        a[j-1] = max(a[j], a[j-2]);
        b.pop_back();
      }
      else {
        a[j] = max(a[j+1], a[j-1]);
      }
    }
    cout << ans << '\n';
    for (int x: a) cout << x << ' ';
    cout << '\n';
  }
}