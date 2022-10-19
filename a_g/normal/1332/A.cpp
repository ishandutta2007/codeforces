#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    int fx = x+b-a;
    int fy = y+d-c;
    bool win = x1 <= fx && fx <= x2 && y1 <= fy && fy <= y2;
    if (y1 == y2 && d > 0) win = 0;
    if (x1 == x2 && a > 0) win = 0;
    cout << (win ? "Yes" : "No") << '\n';
  }
}