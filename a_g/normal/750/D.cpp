#include <bits/stdc++.h>
using namespace std;

pair<int, int> dirs[8] =
  {{0, 1}, {1, 1}, {1, 0}, {1, -1},
  {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

const int N = 500;
vector<pair<int, int>> pts[8], newpts[8];
bool vis[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x: a) cin >> x;
  pts[0].emplace_back(N/2, N/2);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      sort(pts[j].begin(), pts[j].end());
      pts[j].resize(unique(pts[j].begin(), pts[j].end())-pts[j].begin());
      for (auto& [x, y]: pts[j]) {
        for (int k = 0; k < a[i]; k++) {
          vis[x+k*dirs[j].first][y+k*dirs[j].second] = 1;
        }
        for (int newj: {j-1, j+1}) {
          if (newj == 8) newj = 0;
          if (newj == -1) newj = 7;
          newpts[newj].emplace_back(x+(a[i]-1)*dirs[j].first+dirs[newj].first,
              y+(a[i]-1)*dirs[j].second+dirs[newj].second);
        }
      }
    }
    for (int j = 0; j < 8; j++) {
      pts[j] = newpts[j];
      newpts[j].clear();
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans += vis[i][j];
    }
  }
  cout << ans << '\n';
}