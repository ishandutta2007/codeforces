#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> prefx(n + 1);
  vector<int> prefy(n + 1);
  for (int i = 0; i < n; i++) {
    prefx[i + 1] = prefx[i];
    prefy[i + 1] = prefy[i];
    if (s[i] == 'U') {
      prefy[i + 1]++;
    }
    if (s[i] == 'D') {
      prefy[i + 1]--;
    }
    if (s[i] == 'R') {
      prefx[i + 1]++;
    }
    if (s[i] == 'L') {
      prefx[i + 1]--;
    }
  }
  int l = 0;
  int r = 1e16;
  bool good = 0;
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    int dx = prefx[n] * (m / n);
    int dy = prefy[n] * (m / n);
    dx += prefx[m % n];
    dy += prefy[m % n];
    int k = abs(x2 - (x1 + dx)) + abs(y2 - (y1 + dy));
    if (k <= m) {
      good = 1;
      r = m;
    } else {
      l = m;
    }
  }
  if (!good)
    r = -1;
  cout << r << endl;
}