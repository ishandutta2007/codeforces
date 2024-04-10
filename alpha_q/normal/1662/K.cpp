#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int MAGIC = 100;
const ld PI = acosl(-1);

ld x[3], y[3];

ld angle (ld Ax, ld Ay, ld Bx, ld By) {
  ld dot = Ax * Bx + Ay * By;
  return acosl(dot / hypotl(Ax, Ay) / hypotl(Bx, By));
}

ld fermat (ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy) {
  ld a = hypotl(Ax - Bx, Ay - By);
  ld b = hypotl(Bx - Cx, By - Cy);
  ld c = hypotl(Cx - Ax, Cy - Ay);
  ld ret = min({a + b, b + c, c + a});
  ld s = 0.5 * (a + b + c), area = sqrtl(s * (s - a) * (s - b) * (s - c));
  ld ang = max({angle(Bx - Ax, By - Ay, Cx - Ax, Cy - Ay), angle(Ax - Bx, Ay - By, Cx - Bx, Cy - By), angle(Ax - Cx, Ay - Cy, Bx - Cx, By - Cy)});
  if (ang < 2 * PI / 3) ret = min(ret, sqrtl(0.5 * (a * a + b * b + c * c) + 2 * sqrtl(3) * area));
  return ret;
}

ld dist (ld x_fix, ld y_fix) {
  ld ret = 0;
  for (int i = 0; i < 3; ++i) {
    ret = max(ret, fermat(x_fix, y_fix, x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3]));
  }
  return ret;
}

ld get (ld x_fix) {
  ld lo = min({y[0], y[1], y[2]}), hi = max({y[0], y[1], y[2]});
  for (int it = 0; it < MAGIC; ++it) {
    ld y_l = (lo + lo + hi) / 3, y_r = (lo + hi + hi) / 3;
    if (dist(x_fix, y_l) < dist(x_fix, y_r)) hi = y_r; else lo = y_l;
  }
  return dist(x_fix, lo);
}

int main() {
  for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
  ld lo = min({x[0], x[1], x[2]}), hi = max({x[0], x[1], x[2]});
  for (int it = 0; it < MAGIC; ++it) {
    ld x_l = (lo + lo + hi) / 3, x_r = (lo + hi + hi) / 3;
    if (get(x_l) < get(x_r)) hi = x_r; else lo = x_l;
  }
  printf("%0.16f\n", (double) get(lo));
  return 0;
}