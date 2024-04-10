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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    bool win = 0;
    for (int i = 0; i < n; i++) {
      auto it = lower_bound(a.begin(), a.end(), a[i]+k);
      if (it != a.end() && *it == a[i]+k) {
        win = 1;
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
}