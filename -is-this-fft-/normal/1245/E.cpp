#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int N = 10;
int grid [N][N];
double dp [N * N + 5]; // allowed to go up
double dpw [N * N + 5]; 
int idx [N][N];

int main () {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
    }
  }

  vector<pair<int, int>> ord;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < N; j++) {
        ord.push_back({i, j});
      }
    } else {
      for (int j = N - 1; j >= 0; j--) {
        ord.push_back({i, j});
      }
    }
  }

  for (int i = 1; i < (int) ord.size(); i++) {
    int x = ord[i].first;
    int y = ord[i].second;
    idx[x][y] = i;

    dp[i] = 0;
    for (int j = 1; j <= 6 && i - j >= 0; j++) {
      dp[i] += dp[i - j] / min(6, i);
    }

    if (i < 6) {
      dp[i] = 6;
    } else {
      dp[i] += 1;
    }

    dpw[i] = dp[i];
    if (grid[x][y]) {
      int u = idx[x - grid[x][y]][y];
      dp[i] = min(dp[i], dpw[u]);
    }
  }
  
  cout << fixed << setprecision(12) << dp[(int) ord.size() - 1] << endl;
}