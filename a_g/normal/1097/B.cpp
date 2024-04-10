#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  bool win = 0;
  for (int mask = 0; mask < (1<<n); mask++) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
      if ((mask>>i)&1) {
        tot += a[i];
      }
      else {
        tot -= a[i];
      }
    }
    if (tot%360 == 0) win = 1;
  }
  cout << (win ? "YES" : "NO") << '\n';
}