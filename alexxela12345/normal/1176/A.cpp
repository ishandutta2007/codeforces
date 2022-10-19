#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n;
  cin >> n;
  int cnt = 0;
  while (n % 5 == 0) {
    cnt++;
    n /= 5;
    n *= 4;
  }
  while (n % 3 == 0) {
    cnt++;
    n /= 3;
    n *= 2;
  }
  while (n % 2 == 0) {
    cnt++;
    n /= 2;
  }
  if (n != 1) {
    cout << -1 << endl;
  } else {
    cout << cnt << endl;
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--)
    solve();
}