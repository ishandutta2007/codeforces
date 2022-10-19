#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const vector<pair<int, int>> dirs = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

const int N = 600;
int crossed[N][N][4];
int queued[N][N];

void mark(int r1, int c1, int r2, int c2) {
  //cout << r1 << " " << c1 << " " << r2 << " " << c2 << '\n';
  if (r1 > r2) swap(r1, r2);
  if (c1 > c2) swap(c1, c2);
  if (r2 == r1+1) {
    crossed[r1][c1-1][0]++;
    crossed[r1][c1][2]++;
  }
  else {
    assert(c2 == c1+1);
    crossed[r1-1][c1][3]++;
    crossed[r1][c1][1]++;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      mark(r1, c1, r2, c2);
      mark(k+1-r1, k+1-c1, k+1-r2, k+1-c2);
    }
    /*
    for (int z = 0; z < 4; z++) {
      for (int x = 0; x <= k; x++) {
        for (int y = 0; y <= k; y++) {
          cout << crossed[x][y][z] << ' ';
        }
        cout << '\n';
      }
      cout << '\n';
    }
    */
    vector<vector<int>> dp(k+1, vector<int>(k+1, INF));
    dp[k/2][k/2] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(k/2, k/2));
    while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      queued[x][y] = 0;
      for (int z = 0; z < 4; z++) {
        int dx = dirs[z].first;
        int dy = dirs[z].second;
        if (x+dx < 0 || x+dx > k || y+dy < 0 || y+dy > k) continue;
        if (dp[x][y]+crossed[x][y][z] < dp[x+dx][y+dy]) {
          dp[x+dx][y+dy] = dp[x][y] + crossed[x][y][z];
          if (!queued[x+dx][y+dy]) {
            q.push(make_pair(x+dx, y+dy));
            queued[x+dx][y+dy] = 1;
          }
        }
      }
    }

    int minlost = INF;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        if (i == 0 || i == k || j == 0 || j == k) {
          minlost = min(minlost, dp[i][j]);
        }
        //cout << dp[i][j] << ' ';
        for (int z = 0; z < 4; z++) {
          crossed[i][j][z] = 0;
        }
      }
      //cout << '\n';
    }
    cout << n-minlost << '\n';
  }
}