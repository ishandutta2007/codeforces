#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;

char to_chick (int idx) {
  if (idx < 26) return 'a' + idx;
  else if (idx < 52) return 'A' + idx - 26;
  else return '0' - 52 + idx;
}

char grid [MAX_N][MAX_N];

void solve () {
  int height, width, chickc;
  cin >> height >> width >> chickc;

  int ricec = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'R') {
        ricec++;
      }
    }
  }

  vector<int> to_ith (chickc, 0);
  for (int i = 0; i < ricec; i++) {
    to_ith[i % chickc]++;
  }

  int ptr = 0, cnt = 0;
  for (int i = 0; i < height; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < width; j++) {
        if (grid[i][j] == 'R') {
          if (cnt == to_ith[ptr]) {
            ptr++;
            cnt = 0;
          }
          cnt++;
        }
        grid[i][j] = to_chick(ptr);
      }
    } else {
      for (int j = width - 1; j >= 0; j--) {
        if (grid[i][j] == 'R') {
          if (cnt == to_ith[ptr]) {
            ptr++;
            cnt = 0;
          }
          cnt++;
        }
        grid[i][j] = to_chick(ptr);
      }
    }
  }

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cout << grid[i][j];
    }
    cout << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int t = 0; t < testc; t++) {
    solve();
  }
}