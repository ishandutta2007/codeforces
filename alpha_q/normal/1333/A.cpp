#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (i == 1 and j == 1) putchar('W');
        else putchar('B');
      }
      cout << '\n';
    }
  }
  return 0;
}