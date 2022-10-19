#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
  int T;
  cin >> T;
  while (T--) {
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    function<double(double, double, double)> calc = [&] (double x, double y, double z) {
      double ans = 1;
      if (x > EPS) {
        if (x <= v) {
          if (y > EPS) {
            ans += x * calc(0, y+x/2, z+x/2);
          }
          else {
            ans += x;
          }
        }
        else {
          if (y > EPS) {
            ans += x * calc(x-v, y+v/2, z+v/2);
          }
          else {
            ans += x * calc(x-v, 0, z+v);
          }
        }
      }
      if (y > EPS) {
        if (y <= v) {
          if (x > EPS) {
            ans += y * calc(x+y/2, 0, z+y/2);
          }
          else {
            ans += y;
          }
        }
        else {
          if (x > EPS) {
            ans += y * calc(x+v/2, y-v, z+v/2);
          }
          else {
            ans += y * calc(0, y-v, z+v);
          }
        }
      }
      return ans;
    };

    cout << calc(c, m, p) << '\n';
  }
}