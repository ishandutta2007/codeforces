#include <bits/stdc++.h>

using namespace std;

//#define double long double 

const double eps = 1e-7;
const int M = 100100;
const double pi = acos(-1.0);

double x[M], y[M];
double d[M];
int n;
double mi = 1e16;
double ma = 0;
double px, py;

void relax(double x) {
  ma = max(ma, x);
  mi = min(mi, x);
}

int main() {
  cout.precision(11);
  cout << fixed;
  ios_base::sync_with_stdio(false);


  cin >> n;
  cin >> px >> py;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    x[i] -= px;
    y[i] -= py;
    d[i] = x[i] * x[i] + y[i] * y[i];
  }

  x[n] = x[0];
  y[n] = y[0];
  d[n] = d[0];

  for (int i = 0; i < n; ++i) {
    relax(d[i]);
    
    double dx = x[i + 1] - x[i];
    double dy = y[i + 1] - y[i];
    double dist = sqrt(dx * dx + dy * dy);

    double area = fabs(x[i] * y[i + 1] - y[i] * x[i + 1]);
    double h = area / dist;
    double h2 = h * h;
    if (fabs(sqrt(max(d[i] - h2, 0.0)) + sqrt(max(d[i + 1] - h2, 0.0)) - dist) <= eps) {
      relax(h2);
    }
  }

  double ans = (ma - mi) * pi;
  cout << ans << endl;
  return 0;
}