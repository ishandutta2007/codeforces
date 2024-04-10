#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    int maxr = 0;
    int maxw = 0;
    for (int i = 0; i < m; i++) {
      int r, w;
      cin >> r >> w;
      maxr = max(maxr, r);
      maxw = max(maxw, w);
    }
    if (maxr+maxw > n) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << string(maxr, 'R') << string(maxw, 'W') << string(n-maxr-maxw, 'R') << '\n';
  }
}