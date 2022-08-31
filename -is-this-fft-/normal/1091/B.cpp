#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second

using namespace std;

typedef pair<int, int> point;

point operator+ (point p, point q) {
  p.x += q.x;
  p.y += q.y;
  return p;
}

point operator- (point p, point q) {
  p.x -= q.x;
  p.y -= q.y;
  return p;
}

int main () {
  int obc;
  cin >> obc;

  vector<point> obelisks (obc);
  vector<point> clues (obc);
  for (int i = 0; i < obc; i++) {
    cin >> obelisks[i].x >> obelisks[i].y;
  }

  for (int i = 0; i < obc; i++) {
    cin >> clues[i].x >> clues[i].y;
  }

  sort(clues.begin(), clues.end());
  for (int i = 0; i < obc; i++) {
    point loc = obelisks[0] + clues[i];

    vector<point> cur_clues (obc);
    for (int j = 0; j < obc; j++) {
      cur_clues[j] = loc - obelisks[j];
    }

    sort(cur_clues.begin(), cur_clues.end());
    bool ok = true;
    for (int j = 0; j < obc; j++) {
      ok &= cur_clues[j] == clues[j];
    }

    if (ok) {
      cout << loc.x << " " << loc.y << endl;
      return 0;
    }
  }
}