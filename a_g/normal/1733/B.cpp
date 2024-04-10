#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (x < y) swap(x, y);
    if (y != 0) {
      cout << "-1\n";
      continue;
    }
    if (x == 0 || (n-1)%x != 0) {
      cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n-1; i++) {
      cout << 2+x*(i/x) << ' ';
    }
    cout << '\n';
  }
}