#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist (int x1, int y1, int x2, int y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}

int distf (int x, int y, int n, int m) {
  int ans = dist(x, y, 0, 0);
  ans = max(ans, dist(x, y, n - 1, 0));
  ans = max(ans, dist(x, y, 0, m - 1));
  ans = max(ans, dist(x, y, n - 1, m - 1));
  return ans;
}

void solve () {
  int n, m;
  cin >> n >> m;

  vector<int> dfcs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dfcs.push_back(distf(i, j, n, m));
    }
  }

  sort(dfcs.begin(), dfcs.end(), greater<int>());
  while (!dfcs.empty()) {
    cout << dfcs.back() << " ";
    dfcs.pop_back();
  }
  cout << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}