#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef pair<ld, ld> Point;
#define x first
#define y second

const ld ALPHA = M_PI - 3.0 * M_PI / 5.0;
const ld COSA = cos(ALPHA);
const ld SINA = sin(ALPHA);

Point operator+ (Point p, Point q) {
  return Point(p.x + q.x, p.y + q.y);
}

Point operator- (Point p, Point q) {
  return Point(p.x - q.x, p.y - q.y);
}

Point rotate (Point p) {
  return Point(COSA * p.x - SINA * p.y,
               SINA * p.x + COSA * p.y);
}

vector<Point> make_penta (Point a, Point b) {
  vector<Point> ans (5);
  ans[0] = a;
  ans[1] = b;

  Point dir = b - a;
  for (int i = 2; i < 5; i++) {
    dir = rotate(dir);
    ans[i] = ans[i - 1] + dir;
  }

  return ans;
}

const int MAX_M = 505;

Point pts [MAX_M];

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<Point> base = make_penta(Point(0, 0), Point(10, 0));
  ld width = base[2].x - base[4].x;

  pts[0] = base[4];
  pts[1] = base[1];
  pts[2] = base[3];
  pts[3] = base[0];
  for (int i = 4; i < 4 * n + 1; i++) {
    pts[i] = Point(width * (i / 4) + pts[i % 4].x, pts[i % 4].y);
  }

  cout << 4 * n + 1 << endl;
  for (int i = 0; i < 4 * n + 1; i++) {
    cout << fixed << setprecision(12) << pts[i].x << " " << pts[i].y << '\n';
  }

  for (int i = 0; i < n; i++) {
    int add = 1 + 4 * i;
    cout << add + 0 << " " << add + 2 << " " << add + 4 << " " << add + 1 << " " << add + 3 << '\n';
  }

  for (int i = 0; i < 4 * n + 1; i++) {
    cout << 1 + i << " ";
  }
  for (int i = 4 * (n - 1); i >= 0; i -= 4) {
    cout << 1 + i << " ";
  }
  cout << endl;
}