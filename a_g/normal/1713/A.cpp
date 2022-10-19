#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int max_x = 0, min_x = 0, max_y = 0, min_y = 0;
    while (n--) {
      int x, y;
      cin >> x >> y;
      max_x = max(max_x, x);
      min_x = min(min_x, x);
      max_y = max(max_y, y);
      min_y = min(min_y, y);
    }
    cout << 2*(max_x+max_y-min_x-min_y) << '\n';
  }
}