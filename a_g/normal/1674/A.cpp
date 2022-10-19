#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if (y % x == 0) {
      cout << 1 << " " << y/x << '\n';
    }
    else {
      cout << "0 0\n";
    }
  }
}