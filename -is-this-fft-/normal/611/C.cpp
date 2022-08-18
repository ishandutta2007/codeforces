#include <iostream>

const int MAX_W = 505;

using namespace std;

bool grid [MAX_W][MAX_W];
bool can [MAX_W][MAX_W][2];
int rowsum [MAX_W][MAX_W][2];
int dp [MAX_W][MAX_W][2];

int getsum (int row1, int col1, int row2, int col2, int ori) {
  int ans = dp[row2][col2][ori];
  ans -= dp[row2][col1 - 1][ori];
  ans -= dp[row1 - 1][col2][ori];
  ans += dp[row1 - 1][col1 - 1][ori];
  return ans;
}

int main () {
  int height, width;
  cin >> height >> width;
  
  char c;
  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      cin >> c;
      if (c == '.') {
	grid[i][j] = true;
      } else if (c == '#') {
	grid[i][j] = false;
      }
    }
  }

  for (int i = 1; i <= height - 1; i++) {
    for (int j = 1; j <= width; j++) {
      if (grid[i][j] && grid[i + 1][j]) {
	can[i][j][0] = true;
      }
    }
  }

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width - 1; j++) {
      if (grid[i][j] && grid[i][j + 1]) {
	can[i][j][1] = true;
      }
    }
  }

  for (int i = 1; i <= height - 1; i++) {
    for (int j = 1; j <= width; j++) {
      rowsum[i][j][0] = rowsum[i][j - 1][0] + can[i][j][0];
    }
  }

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width - 1; j++) {
      rowsum[i][j][1] = rowsum[i][j - 1][1] + can[i][j][1];
    }
  }

  for (int i = 1; i <= height - 1; i++) {
    for (int j = 1; j <= width; j++) {
      dp[i][j][0] = dp[i - 1][j][0] + rowsum[i][j][0];
    }
  }

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width - 1; j++) {
      dp[i][j][1] = dp[i - 1][j][1] + rowsum[i][j][1];
    }
  }

  /*for (int i = 1; i <= height - 1; i++) {
    for (int j = 1; j <= width; j++) {
      cout << dp[i][j][0] << " ";
    }
    cout << endl;
    }*/

  int queryc;
  cin >> queryc;
  for (int i = 0; i < queryc; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << getsum(r1, c1, r2 - 1, c2, 0) + getsum(r1, c1, r2, c2 - 1, 1) << endl;
  }
}