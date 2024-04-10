#include <bits/stdc++.h>

using namespace std;

int t, ang;

int main() {
  cin >> t;
  while (t--) {
    cin >> ang;
    for (int n = 3; ; ++n) {
      int cur = ang * n;
      if (cur % 180 == 0) {
        int yo = cur / 180;
        if (1 <= yo and yo <= n - 2) {
          printf("%d\n", n);
          break;
        }
      }
    }
  }
  return 0;
}