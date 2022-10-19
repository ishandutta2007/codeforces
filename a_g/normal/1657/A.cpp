#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << 0 << '\n';
      continue;
    }
    bool good = 0;
    for (int i = 0; i <= 100; i++) {
      if (i*i == x*x+y*y) good = 1;
    }
    cout << (good ? 1 : 2) << '\n';
  }
}