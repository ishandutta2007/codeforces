#include <iostream>

using namespace std;

const int MAX_N = 2e3 + 5;
const int MOD = 1e9 + 7;

class Fenwick {
  int tree [MAX_N];

public:
  void add (int idx, int val) {
    for (int i = idx; i < MAX_N; i += i & -i) {
      tree[i] += val;
      tree[i] %= MOD;
    }
  }

  int get (int idx) {
    int ans = 0;
    for (int i = idx; i > 0; i -= i & -i) {
      ans += tree[i];
      ans %= MOD;
    }
    return ans;
  }

  int range (int l, int r) {
    if (r < l) {
      return 0;
    }

    return (get(r) + (MOD - get(l - 1))) % MOD;
  }
};

char grid [MAX_N][MAX_N];
int row_kth [MAX_N][MAX_N];
int col_kth [MAX_N][MAX_N];
Fenwick dp [2][MAX_N];

int main () {
  ios::sync_with_stdio(false);
  
  int height, width;
  cin >> height >> width;

  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 1; i <= height; i++) {
    int rockc = 0;
    for (int j = width; j >= 1; j--) {
      if (grid[i][j] == 'R') {
        rockc++;
        row_kth[i][rockc] = j;
      }
    }
  }

  for (int j = 1; j <= width; j++) {
    int rockc = 0;
    for (int i = height; i >= 1; i--) {
      if (grid[i][j] == 'R') {
        rockc++;
        col_kth[j][rockc] = i;
      }
    }
  }

  dp[0][1].add(1, 1);
  dp[1][1].add(1, 1);
  for (int i = 1; i <= height; i++) {
    for (int j = 1; j <= width; j++) {
      if (i != 1 || j != 1) {
        // calculate dp i j 0
        int ans = dp[1][i].range(row_kth[i][width - j + 1], j - 1);
        dp[0][j].add(i, ans);

        ans = dp[0][j].range(col_kth[j][height - i + 1], i - 1);
        dp[1][i].add(j, ans);
      }
    }
  }

  if (height == 1 && width == 1) {
    cout << 1 << endl;
  } else {
    cout << (dp[0][width].range(height, height) + dp[1][height].range(width, width)) % MOD << endl;
  }
}