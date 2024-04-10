#include <iostream>
#include <vector>

using namespace std;

void solve () {
  int height, width;
  cin >> height >> width;

  vector<int> rcnt (height, 0);
  vector<int> ccnt (width, 0);
  vector<vector<char>> grid (height, vector<char> (width));
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> grid[i][j];

      if (grid[i][j] == '*') {
        rcnt[i]++;
        ccnt[j]++;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      ans = max(ans, rcnt[i] + ccnt[j] - (grid[i][j] == '*'));
    }
  }

  cout << height + width - 1 - ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  
  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}