/*


Q.E.D.

CF1468G

BULB: Instant.
result of thinking: Pure.

start coding: 23:28
AC:
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> bool chmin(T &x, const T &y) {
  return x > y ? (x = y, true) : false;
}
template<class T> bool chmax(T &x, const T &y) {
  return x < y ? (x = y, true) : false;
}

const double EPS = 1e-10;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator + (Point p) {
    return Point(x + p.x, y + p.y);
  }
  Point operator - (Point p) {
    return Point(x - p.x, y - p.y);
  }
  Point operator * (double k) {
    return Point(k * x, k * y);
  }
  Point operator / (double k) {
    return Point(x / k, y / k);
  }
  bool operator == (const Point &p) const {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
  }
  bool operator < (const Point &p) const {
    if (abs(x - p.x) < EPS)
      return y < p.y;
    return x < p.x;
  }
  double len() {
    return sqrt(x * x + y * y);
  }
};
typedef Point Vector;
double det(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}
struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};
typedef Segment Line;
Point crossPoint(Line a, Line b) {
  double r = det(a.p1 - b.p1, b.p2 - b.p1) / det(b.p2 - b.p1, a.p2 - a.p1);
  return a.p1 + (a.p2 - a.p1) * r;
}

#define maxn 200005
int n, h;
Point A[maxn];

int main() {
  scanf("%d%d", &n, &h);
  for (int i = 1; i <= n; i++)
    scanf("%lf%lf", &A[i].x, &A[i].y);
  Point eye = Point(A[n].x, A[n].y + h), ka = A[n];
  double ans = 0;
  for (int i = n - 1; i >= 1; i--) {
    if (det(A[i + 1] - eye, ka - eye) > EPS)
      ka = A[i + 1];
    if (det(A[i] - eye, ka - eye) < -EPS)
      continue;
    if (abs(det(A[i] - eye, A[i + 1] - eye)) < EPS) {
      ans += (A[i] - A[i + 1]).len();
    } else {
      Point Q = crossPoint(Line(A[i], A[i + 1]), Line(ka, eye));
      ans += (Q - A[i]).len();
    }
  }
  printf("%.10f\n", ans);
  return 0;
}