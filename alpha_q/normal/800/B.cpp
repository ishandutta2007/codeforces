#include <bits/stdc++.h> 

using namespace std;

typedef pair <double, double> point;

#define x first
#define y second

const int N = 1010;
const double INF = 1e19;
const double PI = acos(-1.0);

int n;
point p[N];

double dist (point a, point b) {
  return hypot(a.x - b.x, a.y - b.y);
}

double dot (point a, point b) {
  return a.x * b.x + a.y * b.y;
}

point subtract (point a, point b) {
  return point(a.x - b.x, a.y - b.y);
}

double angle (point a, point b, point c) {
  return acos(dot(subtract(b, a), subtract(b, c))/(dist(b, a) * dist(b, c)));
}

double area (point a, point b, point c) {
  return fabs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

int main (int argc, char const *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf", &p[i].x, &p[i].y);
  }
  p[n + 1] = p[1], p[n + 2] = p[2];
  double hi = INF;
  for (int i = 1; i <= n; ++i) {
    hi = min(hi, dist(p[i], p[i + 1])/2.0);
  }
  // cout << hi << endl;
  for (int i = 2; i <= n + 1; ++i) {
    double cur = area(p[i - 1], p[i], p[i + 1]);
    double base = dist(p[i - 1], p[i + 1]);
    double hyt = cur/base;
    hi = min(hi, hyt/2.0);
  }
  printf("%0.12f\n", hi);
  return 0;
}