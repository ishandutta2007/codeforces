#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const bool testing = 0;
int tx, ty;

const int N = 8;
bool done;
int x, y;
int dx, dy;
string s;

void place() {
  cout << x << " " << y << endl;
  dx = 0;
  dy = 0;
  if (testing) {
    bool good = 0;
    int trials = 50;
    while (!good && trials) {
      dx = rng()%3-1;
      dy = rng()%3-1;
      if (1 <= tx + dx && tx + dx <= N && 1 <= ty + dy && ty + dy <= N && (dx | dy)
          && tx + dx != x && ty + dy != y && tx + dx + ty + dy != x + y && tx + dx - ty - dy != x - y) {
        good = 1;
      }
      trials--;
    }
    if (!trials) {
      done = 1;
      return;
    }
    tx += dx;
    ty += dy;
    cout << "king pos is now (" << tx << "," << ty << ")\n";
    if (tx == x || ty == y || tx-ty == x-y || tx+ty == x+y) done = 1;
  }
  else {
    cin >> s;
    if (s == "Done") done = 1;
    if (s.find("Left") != string::npos) dy = -1;
    if (s.find("Right") != string::npos) dy = 1;
    if (s.find("Up") != string::npos) dx = -1;
    if (s.find("Down") != string::npos) dx = 1;
  }
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    done = 0;
    if (testing) {
      tx = rng()%N+1;
      ty = rng()%N+1;
      cout << "starting location is (" << tx << "," << ty << ")\n";
    }
    y = 1;
    for (int row = 1; row <= N && !done; row++) {
      x = row;
      place();
      bool has_moved_down = (row != 1 && dx == 1);
      while (!has_moved_down && !done) {
        for (int j = 1; j <= N && !has_moved_down && !done; j++) {
          if (j != y) {
            y = j;
            place();
            if (dx == 1) {
              has_moved_down = 1;
            }
            else if (dx == -1) {
              j = 1;
            }
          }
        }
        has_moved_down = 1;
      }
    }
  }
}