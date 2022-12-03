/*
BULB: 20min.
result of thinking: Pure.

, , 
.

start coding:
AC:
*/
#include <bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
template<class T1, class T2> bool chmin(T1 &x, const T2 &y) {
  return x > y ? (x = y, true) : false;
}
template<class T1, class T2> bool chmax(T1 &x, const T2 &y) {
  return x < y ? (x = y, true) : false;
}
bool Mbe;

const double EPS = 1e-10;
struct Point {
  double x, y;
  Point(double xx = 0.0, double yy = 0.0) : x(xx), y(yy) {}
  Point operator+(Point p) {
    return Point(x + p.x, y + p.y);
  }
  Point operator-(Point p) {
    return Point(x - p.x, y - p.y);
  }
  Point operator*(double lambda) {
    return Point(x * lambda, y * lambda);
  }
  Point operator/(double lambda) {
    return Point(x / lambda, y / lambda);
  }
  Point operator-() {
    return Point(-x, -y);
  }
  double norm() {
    return x * x + y * y;
  }
  double len() {
    return sqrt(norm());
  }
  bool operator==(const Point &p) const {
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS;
  }
  bool operator<(const Point &p) const {
    if (abs(x - p.x) < EPS)
      return y < p.y;
    return x < p.x;
  }
};
typedef Point Vector;
struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};
typedef Segment Line;
struct Circle {
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};
typedef vector<Point> Polygon;
double dot(Vector a, Vector b) {
  return a.x * b.x + a.y * b.y;
}
double det(Vector a, Vector b) {
  return a.x * b.y - a.y * b.x;
}
Vector rot(Vector a, double theta) {  // rotate.
  double x1 = cos(theta) * a.x - sin(theta) * a.y;
  double y1 = sin(theta) * a.x + cos(theta) * a.y;
  return Point(x1, y1);
}
int coTanNum(Circle a,Circle b){
	if(a.r < b.r) swap(a,b);
	double d = (a.c - b.c).len(),rdif = a.r - b.r,rsum = a.r + b.r;
	if(d < rdif - EPS) return 0;
	if(abs(d - rdif) < EPS) return 1;
	if(d < rsum - EPS) return 2;
	if(abs(d - rsum) < EPS) return 3;
	return 4;
}

int n, V, E, C;
Circle a[5];
vector<Point> onBound[5];

void crossCC(vector<Point> &res, Circle o1, Circle o2) {  // make sure crossing.
  Vector a = o2.c - o1.c;
  int fl = coTanNum(o1, o2);
  if (fl == 0 || fl == 4)
    return;
  C++;
  double foo = (o1.r * o1.r + a.norm() - o2.r * o2.r) / (2 * o1.r * a.len());
  chmax(foo, -1.0);
  chmin(foo, 1.0);
  double alpha = acos(foo);
  Vector b = a / a.len() * o1.r;
  res.push_back(o1.c + rot(b, alpha));
  res.push_back(o1.c + rot(b, -alpha));
}

int quChong(const vector<Point> vec) {
  int res = 0;
  for (int i = 0; i < (int)vec.size(); i++) {
    bool ok = false;
    for (int j = 0; j < i; j++) { 
      if (vec[j] == vec[i])
        ok = true;
    }
    if (!ok)
      res++;
  }
  return res;
}

bool Med;
int main() {
  fprintf(stderr, "%.2fMB\n", (&Mbe - &Med) / 1048576.);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf%lf", &a[i].c.x, &a[i].c.y, &a[i].r);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (j == i)
        continue;
      crossCC(onBound[i], a[i], a[j]);
      crossCC(onBound[0], a[i], a[j]);
    }
  }
  C /= 4;
  C = max(n - C, 1);
  for (int i = 1; i <= n; i++)
    E += quChong(onBound[i]);
  V = quChong(onBound[0]);

  // cout << V << " " << E << " " << C << endl;
  // system("pause");

  printf("%d\n", E + 2 - V + C - 1);
  cerr << "time: " << clock() << "ms" << endl;
  return 0;
}
/*
3
4 0 1
-1 1 9
0 3 6

F = E + 2 - V
*/