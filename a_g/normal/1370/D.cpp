#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  auto check = [&] (int y) {
    for (int z = 0; z < 2; z++) {
      int len = 0;
      bool b = z;
      for (int x: a) {
        if (b) {
          b = 1-b;
          len++;
        }
        else if (x <= y) {
          b = 1-b;
          len++;
        }
      }
      if (len >= k) return true;
    }
    return false;
  };
  int ans = 1<<30;
  for (int i = 30; i >= 0; i--) {
    if (check(ans-(1<<i))) ans -= 1<<i;
  }
  cout << ans << '\n';
}