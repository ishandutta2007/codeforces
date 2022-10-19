#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a;
    cin >> a;
    if (__builtin_popcount(a+1) != 1) {
      cout << (1<<(__lg(a)+1))-1 << '\n';
    }
    else {
      int ans = 1;
      for (int d = 2; d*d <= a; d++) {
        if (a%d == 0) {
          ans = a/d;
          break;
        }
      }
      cout << ans << '\n';
    }
  }
}