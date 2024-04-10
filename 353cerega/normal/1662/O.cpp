#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

const int N = 30, M = 360;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> blockedCirc(N, vector<int>(M));
  vector<vector<int>> blockedWall(N, vector<int>(M));
  vector<vector<int>> dist(N, vector<int>(M));
  for (int i = 0; i < n; i++) {
    char t;
    cin >> t;
    if (t == 'C') {
      int r, t1, t2;
      cin >> r >> t1 >> t2;
      while (t1 != t2) {
        blockedCirc[r][t1] = 1;
        t1 = (t1 + 1) % M;
      }
    } else {
      int r1, r2, theta;
      cin >> r1 >> r2 >> theta;
      for (int j = r1; j < r2; j++) {
        blockedWall[j][theta] = 1;
      }
    }
  }
  dist[0][0] = 1;
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    int leftY = (y - 1 + M) % M;
    int rightY = (y + 1 + M) % M;
    int topX = x - 1;
    int botX = x + 1;
    if (!dist[x][leftY] && !blockedWall[x][y]) {
      dist[x][leftY] = 1;
      q.push({x, leftY});
    }
    if (!dist[x][rightY] && !blockedWall[x][rightY]) {
      dist[x][rightY] = 1;
      q.push({x, rightY});
    }
    if (topX >= 0 && !dist[topX][y] && !blockedCirc[x][y]) {
      dist[topX][y] = 1;
      q.push({topX, y});
    }
    if (botX < N && !dist[botX][y] && !blockedCirc[x + 1][y]) {
      dist[botX][y] = 1;
      q.push({botX, y});
    }
  }
  if (dist[N - 1][0]) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}