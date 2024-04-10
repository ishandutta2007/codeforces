#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x: a) cin >> x;
    if (n&1) {
      cout << "Mike\n";
      continue;
    }
    int b[2] = {INF, INF};
    for (int i = 0; i < n; i++) {
      b[i&1] = min(b[i&1], a[i]);
    }
    int xp, yp;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == b[0]) {
        xp = i;
        break;
      }
    }
    for (int i = 1; i < n; i+= 2) {
      if (a[i] == b[1]) {
        yp = i;
        break;
      }
    }
    cout << (b[0] > b[1] || (b[0] == b[1] && xp > yp) ? "Mike" : "Joe") << '\n';
  }
}