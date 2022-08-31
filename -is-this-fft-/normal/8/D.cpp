#include <iostream>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

typedef long double ld;

typedef pair<ld, ld> pt;
#define x first
#define y second

ld dot (pt p, pt q) {
  return p.x * q.x + p.y * q.y;
}

ld sq (pt p) {
  return dot(p, p);
}

ld norm (pt p) {
  return sqrt(sq(p));
}

pt operator+ (pt p, pt q) {
  return make_pair(p.x + q.x, p.y + q.y);
}

pt operator- (pt p, pt q) {
  return make_pair(p.x - q.x, p.y - q.y);
}

pt operator* (pt p, ld c) {
  return make_pair(c * p.x, c * p.y);
}

ld dist (pt p, pt q) {
  return norm(p - q);
}

pt perp (pt p) {
  return make_pair(-p.y, p.x);
}

const ld EPS = 1e-10;

int sgn (ld d) {
  if (d < -EPS) return -1;
  if (d > EPS) return 1;
  return 0;
}

int circleCircle (pt o1, ld r1, pt o2, ld r2, pair<pt, pt> &out) {
  pt d = o2 - o1;
  ld d2 = sq(d);
  if (d2 == 0) {
    assert (r1 != r2);
    return 0;
  }
  ld pd = (d2 + r1 * r1 - r2 * r2) / 2;
  ld h2 = r1 * r1 - pd * pd / d2;
  if (h2 >= 0) {
    pt p = o1 + d * (pd / d2) , h = perp(d) * sqrt (h2 / d2);
    out = {p - h, p + h};
  } else if (h2 > -1e-15) {
    pt p = o1 + d * (pd / d2);
    out = {p, p};
    return 1;
  }
  return 1 + sgn (h2);
}

bool inCircle (pt o, ld r, pt p) {
  return dist(p, o) < r + EPS;
}

bool inCircles (pt o1, ld r1, pt o2, ld r2, pt o3, ld r3, pt p) {
  return inCircle(o1, r1, p) && inCircle(o2, r2, p) && inCircle(o3, r3, p);
}

bool ccc (pt o1, ld r1, pt o2, ld r2, pt o3, ld r3) {
  if (r1 < 0 || r2 < 0 || r3 < 0) return false;
  
  vector<pt> toCheck = {o1, o2, o3};

  pair<pt, pt> o12;
  int o12c = circleCircle(o1, r1, o2, r2, o12);
  if (0 < o12c) toCheck.push_back(o12.first);
  if (1 < o12c) toCheck.push_back(o12.second);

  pair<pt, pt> o13;
  int o13c = circleCircle(o1, r1, o3, r3, o13);
  if (0 < o13c) toCheck.push_back(o13.first);
  if (1 < o13c) toCheck.push_back(o13.second);
  
  pair<pt, pt> o23;
  int o23c = circleCircle(o2, r2, o3, r3, o23);
  if (0 < o23c) toCheck.push_back(o23.first);
  if (1 < o23c) toCheck.push_back(o23.second);

  for (pt p : toCheck) {
    if (inCircles(o1, r1, o2, r2, o3, r3, p)) {
      return true;
    }
  }
  return false;
}

int main () {
  int t1, t2;
  cin >> t1 >> t2;

  pt A, C, B;
  cin >> A.x >> A.y;
  cin >> C.x >> C.y;
  cin >> B.x >> B.y;

  if (dist(A, B) + dist(B, C) <= dist(A, C) + t2) {
    ld ans = min(dist(A, C) + t2, dist(A, B) + dist(B, C) + t1);
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
  }
  
  ld ans = 0;
  for (ld k = 1000; k > 1e-14; k /= 2) {
    ld r = ans + k;
    if (ccc(A, r, B, dist(A, B) + t1 - r, C, dist(A, C) + t2 - r)) {
      ans += k;
    }
  }

  cout << fixed << setprecision(12) << ans << endl;
}