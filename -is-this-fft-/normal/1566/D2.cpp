#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 305;
const int MAX_MN = MAX_N * MAX_N;

int arr [MAX_MN];
int grid [MAX_N][MAX_N];

void solve () {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> ord; // arr, idx
  for (int i = 0; i < n * m; i++) {
    cin >> arr[i];
    ord.push_back({arr[i], i});
  }

  sort(ord.begin(), ord.end());
  vector<vector<int>> groups;
  for (int i = 0; i < n * m; i++) {
    if (i == 0 || ord[i].first != ord[i - 1].first) {
      groups.push_back(vector<int> ());
    }
    groups.back().push_back(ord[i].second);
  }

  int row = 0, col = 0;
  for (const auto &grp : groups) {
    int pos = 0;
    while (pos < (int) grp.size()) {
      int rem = (int) grp.size() - pos;
      
      if (col + rem >= m) {
        rem = m - col;
      }

      for (int i = 0; i < rem; i++) {
        grid[row][col + rem - i - 1] = grp[pos + i];
      }

      pos += rem;
      col += rem;
      if (col == m) {
        col = 0;
        row++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (grid[i][j] < grid[i][k]) {
          ans++;
        }
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