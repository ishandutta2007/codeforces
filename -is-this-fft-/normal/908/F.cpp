#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX_POINT = 300005;

int greens [MAX_POINT];

int main () {
  int pointc;
  cin >> pointc;

  vector<vector<int>> red_blocks (1, vector<int> (0));
  vector<vector<int>> blue_blocks (1, vector<int> (0));
  for (int i = 0; i < pointc; i++) {
    int loc;
    char col;
    cin >> loc >> col;

    if (col == 'G') {
      red_blocks.push_back(vector<int> (0));
      blue_blocks.push_back(vector<int> (0));
      greens[red_blocks.size() - 1] = loc;
    } else if (col == 'R') {
      red_blocks.back().push_back(loc);
    } else if (col == 'B') {
      blue_blocks.back().push_back(loc);
    }
  }

  int ans = 0;
  for (int i = 1; i < (int) red_blocks.size() - 1; i++) {
    int red_gap = 0;
    if (red_blocks[i].empty()) {
      red_gap = greens[i + 1] - greens[i];
    } else {
      red_gap = max(red_gap, red_blocks[i].front() - greens[i]);
      red_gap = max(red_gap, greens[i + 1] - red_blocks[i].back());
      for (int j = 0; j < (int) red_blocks[i].size() - 1; j++) {
        red_gap = max(red_gap, red_blocks[i][j + 1] - red_blocks[i][j]);
      }
    }

    int blue_gap = 0;
    if (blue_blocks[i].empty()) {
      blue_gap = greens[i + 1] - greens[i];
    } else {
      blue_gap = max(blue_gap, blue_blocks[i].front() - greens[i]);
      blue_gap = max(blue_gap, greens[i + 1] - blue_blocks[i].back());
      for (int j = 0; j < (int) blue_blocks[i].size() - 1; j++) {
        blue_gap = max(blue_gap, blue_blocks[i][j + 1] - blue_blocks[i][j]);
      }
    }

    // cout << red_gap << " " << blue_gap << " " << greens[i + 1] << " " << greens[i] << endl;
    ans += min(3 * (greens[i + 1] - greens[i]) - red_gap - blue_gap,
               2 * (greens[i + 1] - greens[i]));
  }
  
  if (red_blocks.size() == 1) { // no greens
    if (!red_blocks[0].empty()) {
      ans += red_blocks[0].back() - red_blocks[0].front();
    }

    if (!blue_blocks[0].empty()) {
      ans += blue_blocks[0].back() - blue_blocks[0].front();
    }
  } else {
    if (!red_blocks[0].empty()) {
      ans += greens[1] - red_blocks[0].front();
    }

    if (!blue_blocks[0].empty()) {
      ans += greens[1] - blue_blocks[0].front();
    }

    if (!red_blocks.back().empty()) {
      ans += red_blocks.back().back() - greens[red_blocks.size() - 1];
    }

    if (!blue_blocks.back().empty()) {
      ans += blue_blocks.back().back() - greens[blue_blocks.size() - 1];
    }
  }

  cout << ans << endl;
}