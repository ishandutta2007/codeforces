#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long llong;

struct point {
  llong x, y;

  point () {
    x = 0;
    y = 0;
  }

  point (llong _x, llong _y) {
    x = _x;
    y = _y;
  }
};

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

llong dot (point p, point q) {
  return p.x * q.x + p.y * q.y;
}

llong cross (point p, point q) {
  return p.x * q.y - p.y * q.x;
}

llong orient (point a, point b, point c) {
  return cross(b - a, c - a);
}

point reflect (point a, point b, point p) {
  p = p + (a - p) + (b - p);
  return p;
}

bool operator< (point p, point q) {
  return make_pair(p.x, p.y) < make_pair(q.x, q.y);
}

ostream& operator<< (ostream &out, point p) {
  out << p.x << " " << p.y;
  return out;
}

int main () {
  int pointc;
  llong some_stupid_constant;
  cin >> pointc >> some_stupid_constant;

  vector<point> points (pointc);
  for (int i = 0; i < pointc; i++) {
    cin >> points[i].x >> points[i].y;
  }

  sort(points.begin(), points.end());
  
  vector<point> upper_hull (1, points[0]);
  for (int i = 1; i < pointc; i++) {
    while (true) {
      if ((int) upper_hull.size() < 2) {
        break;
      }

      if (orient(upper_hull[(int) upper_hull.size() - 2], upper_hull.back(), points[i]) >= 0) {
        upper_hull.pop_back();
      } else {
        break;
      }
    }
    upper_hull.push_back(points[i]);
  }

  reverse(points.begin(), points.end());

  vector<point> lower_hull (1, points[0]);
  for (int i = 1; i < pointc; i++) {
    while (true) {
      if ((int) lower_hull.size() < 2) {
        break;
      }

      if (orient(lower_hull[(int) lower_hull.size() - 2], lower_hull.back(), points[i]) >= 0) {
        lower_hull.pop_back();
      } else {
        break;
      }
    }
    lower_hull.push_back(points[i]);
  }

  vector<point> convex_hull = upper_hull;
  for (int i = 1; i < (int) lower_hull.size(); i++) {
    convex_hull.push_back(lower_hull[i]);
  }

  int besti = -1, bestj = -1, bestk = -1;
  llong best_area = -1;
  for (int i = 0; i < (int) convex_hull.size() - 2; i++) {
    int k = i + 2;
    for (int j = i + 1; j < (int) convex_hull.size() - 1; j++) {
      while (k < (int) convex_hull.size() - 1 &&
             abs(orient(convex_hull[i], convex_hull[j], convex_hull[k])) <
             abs(orient(convex_hull[i], convex_hull[j], convex_hull[k + 1]))) {
        k++;
      }

      if (abs(orient(convex_hull[i], convex_hull[j], convex_hull[k])) > best_area) {
        besti = i;
        bestj = j;
        bestk = k;
        best_area = abs(orient(convex_hull[i], convex_hull[j], convex_hull[k]));
      }
    }
  }

  cout << reflect(convex_hull[besti], convex_hull[bestj], convex_hull[bestk]) << endl
       << reflect(convex_hull[besti], convex_hull[bestk], convex_hull[bestj]) << endl
       << reflect(convex_hull[bestj], convex_hull[bestk], convex_hull[besti]) << endl;
}