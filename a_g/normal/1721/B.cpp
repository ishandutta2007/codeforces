#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    if ((sx-d <= 1 && sy-d <= 1) || (sx+d >= n && sy+d >= m)) {
      cout << "-1\n";
      continue;
    }
    if ((sx-d <= 1 && sx+d >= n) || (sy-d <= 1 && sy+d >= m)) {
      cout << "-1\n";
      continue;
    }
    cout << n+m-2 << '\n';
  }
}