#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (string& row: grid) cin >> row;
    int low = -1;
    int high = n+m;
    int tx, ty;
    while (high-low > 1) {
      int mid = (low+high)/2;
      int a = -INF; // lower bound x+y
      int b = INF; // upper bound x+y
      int c = -INF; // lower bound x-y
      int d = INF; // upper bound x-y
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 'B') {
            a = max(a, i+j-mid);
            b = min(b, i+j+mid);
            c = max(c, i-j-mid);
            d = min(d, i-j+mid);
          }
        }
      }
      //cout << mid << " " << a << "  " << b << " " << c << " " << d << endl;
      if (a > b || c > d) {
        low = mid;
        continue;
      }
      if (a == b && c == d && (a%2 != abs(c)%2)) {
        low = mid;
        continue;
      }
      int u = a;
      int v = c;
      if (u%2 != abs(v)%2) {
        if (u != b) u++;
        else v++;
      }
      tx = (u+v)/2;
      ty = (u-v)/2;
      high = mid;
    }
    cout << tx+1 << " " << ty+1 << '\n';
  }
}