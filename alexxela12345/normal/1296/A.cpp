#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  bool has1 = 0, has2 = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      has1 = 1;
    } else {
      has2 = 1;
    }
    sum = (sum + x) % 2;
  }
  if (sum % 2 == 1) {
    cout << "YES" << endl;
    return;
  }
  if (has1 && has2) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

signed main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}