#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 305;

char grid [MAX_N][MAX_N];

void solve () {
  int n;
  cin >> n;

  vector<int> cnt (3, 0);
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'X') {
        cnt[(i + j) % 3]++;
      }
    }
  }

  pair<int, int> mn = make_pair(MAX_N * MAX_N, -1);
  for (int i = 0; i < 3; i++) {
    mn = min(mn, make_pair(cnt[i], i));
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == 'X' && (i + j) % 3 == mn.second) {
        grid[i][j] = 'O';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j];
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