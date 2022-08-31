#include <iostream>
#include <deque>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

const int maxn = 305;

deque<int> cur [maxn][maxn];
deque<int> target [maxn][maxn];
int orig_len [maxn][maxn];
int cnt [maxn][2];

vector<pair<pair<int, int>, pair<int, int>>> ans;
void mv_chip (int x1, int y1, int x2, int y2) {
  assert(make_pair(x1, y1) != make_pair(x2, y2));
  ans.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
  int bk = cur[x1][y1].back();
  cur[x1][y1].pop_back();
  cur[x2][y2].push_front(bk);
}

int main () {
  ios::sync_with_stdio(false);
  
  int height, width;
  cin >> height >> width;

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      string s;
      cin >> s;

      for (char c : s) {
        cur[i][j].push_back(c - '0');
      }

      orig_len[i][j] = s.size();
    }
  }
  
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      string s;
      cin >> s;

      for (char c : s) {
        target[i][j].push_back(c - '0');
        if (c == '0') {
          if (i == 0) {
            cnt[(j + 1 + width) % width][0]++;
          } else {
            cnt[j][0]++;
          }
        } else {
          if (i == 1) {
            cnt[(j + 1 + width) % width][1]++;
          } else {
            cnt[j][1]++;
          }
        }
      }
    }
  }
  
  for (int j = 0; j < width; j++) {
    /* remove all ones */
    for (int k = 0; k < orig_len[0][j]; k++) {
      if (cur[0][j].back() == 1) {
        mv_chip(0, j, 1, j);
      } else {
        mv_chip(0, j, 0, (j + 1) % width);
      }
    }
  }

  for (int j = 0; j < width; j++) {
    for (int k = 0; k < orig_len[1][j]; k++) {
      if (cur[1][j].back() == 0) {
        mv_chip(1, j, 0, j);
      } else {
        mv_chip(1, j, 1, (j + 1) % width);
      }
    }
  }

  for (int i = 2; i < height; i++) {
    for (int j = 0; j < width; j++) {
      while (!cur[i][j].empty()) {
        int bit = cur[i][j].back();
        mv_chip(i, j, bit, j);
      }
    }
  }
  
  for (int g = 0; g < 2; g++) {
    deque<int> surplus;
    for (int j = 0; j < width; j++) {
      if ((int) cur[g][j].size() > cnt[j][g]) {
        for (int k = 0; k < (int) cur[g][j].size() - cnt[j][g]; k++) {
          surplus.push_back(j);
        }
      }
    }

    for (int j = 0; j < width; j++) {
      while ((int) cur[g][j].size() < cnt[j][g]) {
        mv_chip(g, surplus.back(), g, j);
        surplus.pop_back();
      }
    }
  }
  
  for (int i = 2; i < height; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = (int) target[i][j].size() - 1; k >= 0; k--) {
        int bit = target[i][j][k];
        mv_chip(bit, j, i, j);
      }
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < width; j++) {
      for (int k = (int) target[i][j].size() - 1; k >= 0; k--) {
        int bit = target[i][j][k];
        if (bit == i) {
          mv_chip(i, (j + 1) % width, i, j);
        } else {
          mv_chip(bit, j, i, j);
        }
      }
    }
  }
  
  cout << (int) ans.size() << '\n';
  for (pair<pair<int, int>, pair<int, int>> pr : ans) {
    cout << pr.first.first + 1 << " " << pr.first.second + 1 << " " << pr.second.first + 1 << " " << pr.second.second + 1 << '\n';
  }
}