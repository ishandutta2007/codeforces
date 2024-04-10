#include <iostream>

using namespace std;

const int MAX_N = 305;

int grid [MAX_N][MAX_N];
int ans [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = 4;
    }
  }

  for (int i = 0; i < n; i++) {
    ans[i][0]--;
    ans[i][m - 1]--;
  }

  for (int j = 0; j < m; j++) {
    ans[0][j]--;
    ans[n - 1][j]--;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] < grid[i][j]) {
        cout << "NO" << '\n';
        return;
      }
    }
  }

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}