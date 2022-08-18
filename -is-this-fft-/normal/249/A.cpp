#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef complex<ld> Vec;

ld cross (Vec P, Vec Q) {
  return (conj(P) * Q).imag();
}

struct Line {
  Vec v;
  ld c;

  Line (Vec P, Vec Q) {
    v = Q - P;
    c = cross(v, P);
  }
};

ld side (Line l, Vec P) {
  return cross(l.v, P) - l.c;
}

ld dist (Line l, Vec P) {
  return side(l, P) / abs(l.v);
}

Vec inters (Line l, Line m) {
  return (l.c * m.v - m.c * l.v) / cross(l.v, m.v);
}

const ld EPS = 1e-8;

int main () {
  ld y1, y2, yw, xb, yb, r;
  cin >> y1 >> y2 >> yw >> xb >> yb >> r;

  ld ywr = yw - r;
  Vec ball (xb, yb);
  Vec target (0, 2 * ywr - (y1 + r + EPS));
  Line trajectory (ball, target);
  Vec oth_post (0, 2 * ywr - y2);

  if (dist(trajectory, oth_post) < r + EPS) {
    cout << -1 << endl;
    return 0;
  }
  
  Line edge (Vec(0, ywr), Vec(1, ywr));
  Vec ans = inters(trajectory, edge);
  cout << fixed << setprecision(12) << ans.real() << endl;
}