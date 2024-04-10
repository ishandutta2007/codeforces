#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 5;

int grid [MAX_N][MAX_N];
bool mark [MAX_N][MAX_N];

void solve () {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<pair<int, int>> arr;
  for (int j = 0; j < n; j++) {
    int i = 0;
    if ((i + j) % 2 == 1) {
      arr.emplace_back(i, j);
    }
  }

  for (int i = 1; i < n; i++) {
    int j = n - 1;
    if ((i + j) % 2 == 1) {
      arr.emplace_back(i, j);
    }
  }

  for (int j = n - 2; j >= 0; j--) {
    int i = n - 1;
    if ((i + j) % 2 == 1) {
      arr.emplace_back(i, j);
    }
  }

  for (int i = n - 2; i > 0; i--) {
    int j = 0;
    if ((i + j) % 2 == 1) {
      arr.emplace_back(i, j);
    }
  }

  for (int i = 0; i < (int) arr.size(); i++) {
    if (i % 2 == 0) {
      mark[arr[i].first][arr[i].second] = true;
    }
  }

  for (int i = 2; i < n; i++) {
    for (int j = 2; j < n; j++) {
      mark[i][j] |= mark[i - 2][j - 2];
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mark[i][j] || mark[i][n - j - 1]) {
        ans ^= grid[i][j];
      }
    }
  }
  cout << ans << '\n';
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