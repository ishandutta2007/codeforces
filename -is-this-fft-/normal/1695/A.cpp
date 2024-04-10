#include <iostream>

using namespace std;

const int INF = 1e9 + 5;

void solve () {
  int n, m;
  cin >> n >> m;

  pair<int, pair<int, int>> mx = {-INF, {0, 0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;

      mx = max(mx, make_pair(x, make_pair(i, j)));
    }
  }

  int x = mx.second.first;
  int y = mx.second.second;

  cout << max(1 + x, n - x) * max(1 + y, m - y) << '\n';
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