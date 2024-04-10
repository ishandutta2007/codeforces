#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, h, w;
  string s;
  cin >> n >> h >> w >> s;

  int min_dx = 0;
  int max_dx = 0;
  int min_dy = 0;
  int max_dy = 0;
  int dx = 0;
  int dy = 0;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == 'U') {
      if (dy == max_dy) {
        add(ans, 1LL*(i+1)*max(0, w-(max_dx-min_dx)) % MOD);
        max_dy++;
      }
      dy++;
    }
    if (c == 'D') {
      if (dy == min_dy) {
        add(ans, 1LL*(i+1)*max(0, w-(max_dx-min_dx)) % MOD);
        min_dy--;
      }
      dy--;
    }
    if (c == 'L') {
      if (dx == min_dx) {
        add(ans, 1LL*(i+1)*max(0, h-(max_dy-min_dy)) % MOD);
        min_dx--;
      }
      dx--;
    }
    if (c == 'R') {
      if (dx == max_dx) {
        add(ans, 1LL*(i+1)*max(0, h-(max_dy-min_dy)) % MOD);
        max_dx++;
      }
      dx++;
    }
    if (max_dx-min_dx >= w || max_dy-min_dy >= h) break;
  }
  if (dx == 0 && dy == 0 && max_dx-min_dx < w && max_dy-min_dy < h) {
    cout << "-1\n";
    return 0;
  }

  int sum_dx = dx;
  int sum_dy = dy;

  min_dx = 0;
  max_dx = 0;
  min_dy = 0;
  max_dy = 0;
  dx = 0;
  dy = 0;
  int pre_x = 0;
  int pre_y = 0;
  vector<tuple<int, int, int>> milestones; // steps, dx, dy
  for (int i = 0; i < n; i++) {
    char c = s[i];
    bool flag = 0;
    if (c == 'U') {
      if (dy == max_dy) {
        flag = (sum_dy > 0);
        max_dy++;
      }
      dy++;
    }
    if (c == 'D') {
      if (dy == min_dy) {
        flag = (sum_dy < 0);
        min_dy--;
      }
      dy--;
    }
    if (c == 'L') {
      if (dx == min_dx) {
        flag = (sum_dx < 0);
        min_dx--;
      }
      dx--;
    }
    if (c == 'R') {
      if (dx == max_dx) {
        flag = (sum_dx > 0);
        max_dx++;
      }
      dx++;
    }
    if (flag || i == n-1) {
      milestones.emplace_back(i+1, dx-pre_x, dy-pre_y);
      pre_x = dx;
      pre_y = dy;
    }
  }


  dx = sum_dx;
  dy = sum_dy;
  int offset = n;
  while (1) {
    if (max_dx-min_dx >= w || max_dy-min_dy >= h) break;
    for (auto& [steps, ldx, ldy]: milestones) {
      if (dx+ldx > max_dx || dx+ldx < min_dx) {
        add(ans, 1LL*(offset+steps)*max(0, h-(max_dy-min_dy)) % MOD);
      }
      if (dy+ldy > max_dy || dy+ldy < min_dy) {
        add(ans, 1LL*(offset+steps)*max(0, w-(max_dx-min_dx)) % MOD);
      }
      dx += ldx;
      dy += ldy;
      min_dx = min(min_dx, dx);
      max_dx = max(max_dx, dx);
      min_dy = min(min_dy, dy);
      max_dy = max(max_dy, dy);
      if (max_dx-min_dx >= w || max_dy-min_dy >= h) break;
    }
    add(offset, n);
  }
  cout << ans << '\n';
}