#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &e : v) {
    cin >> e;
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (v[i] % 2 == 0) {
        ans += v[i];
      }
    } else {
      if (v[i] % 2 == 1) {
        ans -= v[i];
      }
    }
  }
  if (ans == 0) {
    cout << "Tie\n";
  } else if (ans > 0) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}