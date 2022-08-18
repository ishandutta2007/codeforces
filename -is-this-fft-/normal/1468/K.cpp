#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Point;
#define x first
#define y second

Point move (Point cur, char dir) {
  if (dir == 'L') cur.x--;
  if (dir == 'R') cur.x++;
  if (dir == 'U') cur.y++;
  if (dir == 'D') cur.y--;
  return cur;
}

vector<Point> path (const string &s) {
  Point cur (0, 0);
  vector<Point> ans;
  for (char c : s) {
    cur = move(cur, c);
    ans.push_back(cur);
  }
  return ans;
}

Point path_obst (const string &s, Point obst) {
  Point cur (0, 0);
  for (char c : s) {
    auto nxt = move(cur, c);
    if (nxt != obst) {
      cur = nxt;
    }
  }
  return cur;
}

void solve () {
  string s;
  cin >> s;

  auto pth = path(s);
  for (Point p : pth) {
    if (p != Point(0, 0)) {
      if (path_obst(s, p) == Point(0, 0)) {
        cout << p.x << " " << p.y << '\n';
        return;
      }
    }
  }

  cout << "0 0" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}