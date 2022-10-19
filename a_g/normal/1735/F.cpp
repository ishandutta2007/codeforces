#include <bits/stdc++.h>
using namespace std;

const long double EPS = 1e-11;

struct seg {
  long double x, y;
  int id;
};

bool operator < (const seg& a, const seg& b) {
  //long double d = (a.x*b.y - a.y*b.x);
  return (a.x/a.y > b.x/b.y > 0 || a.x/a.y == b.x/b.y && a.id < b.id);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(12);
  int T;
  cin >> T;
  while (T--) {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n), q(n);
    for (int& x: p) cin >> x;
    for (int& x: q) cin >> x;
    if (a+b == 0) {
      // precision issues or something
      while (n--) {
        cout << "0\n";
      }
      continue;
    }
    set<seg> hull;
    long double sum_x = 0;
    long double sum_y = 0;
    long double start_x = a;
    long double start_y = b;
    for (int i = 0; i < n; i++) {
      start_x += p[i];
      start_y -= q[i];
      hull.insert(seg{-2.0*p[i], 2.0*q[i], i});
      sum_x -= 2.0*p[i];
      sum_y += 2.0*q[i];
      while (start_y < 0) {
        auto it = hull.begin();
        auto [x, y, z] = *it;
        if (start_y + y < EPS) {
          hull.erase(it);
          sum_x -= x;
          sum_y -= y;
          start_x += x;
          start_y += y;
          continue;
        }
        long double dy = -start_y;
        long double dx = dy*x/y;
        sum_x -= dx;
        sum_y -= dy;
        start_x += dx;
        start_y = 0;
        hull.erase(it);
        if (min(abs(x-dx), abs(y-dy)) > EPS) hull.insert(seg{x-dx, y-dy, z});
        break;
      }

      while (start_x + sum_x < 0) {
        auto it = prev(hull.end());
        auto [x, y, z] = *it;
        if (start_x  + sum_x - x < EPS) {
          hull.erase(it);
          sum_x -= x;
          sum_y -= y;
          continue;
        }
        long double dx = start_x+sum_x;
        long double dy = dx*y/x;
        sum_x = -start_x;
        sum_y -= dy;
        hull.erase(it);
        if (min(abs(x-dx), abs(y-dy)) > EPS) hull.insert(seg{x-dx, y-dy, z});
        break;
      }

      /*
      for (auto& [x, y, z]: hull) {
        cout << x << ' ' << y << ' ' << z << '\n';
      }
      cout << start_x << ' ' << start_y << '\n';
      */
      cout << start_x << '\n';
    }
  }
}