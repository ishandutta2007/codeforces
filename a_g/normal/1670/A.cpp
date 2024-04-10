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
    int neg = 0;
    for (int x: a) {
      if (x < 0) neg++;
    }
    for (int i = 0; i < neg; i++) {
      a[i] = -abs(a[i]);
    }
    for (int i = neg; i < n; i++) {
      a[i] = abs(a[i]);
    }
    cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
  }
}