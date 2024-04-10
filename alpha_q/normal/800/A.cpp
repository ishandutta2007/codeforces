#include <bits/stdc++.h> 

using namespace std;

const int N = 100010;
const double INF = 1e18;

int n;
double p, a[N], b[N], tot = 0.0;

bool ok (double x) {
  double tot = 0.0;
  for (int i = 1; i <= n; ++i) {
    tot += max(0.0, a[i] * x - b[i]);
  }
  return tot <= p * x;
}

int main (int argc, char const *argv[]) {
  scanf("%d %lf", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf %lf", a + i, b + i);
    tot += a[i];
  }
  if (tot <= p) {
    puts("-1");
    return 0;
  }
  int it = 100; 
  double lo = 0, hi = INF;
  while (it--) {
    double mid = (lo + hi)/2.0;
    if (ok(mid)) lo = mid;
    else hi = mid;
  }
  if (lo >= INF/2.0) {
    puts("-1");
    return 0;
  }
  printf("%0.12f\n", lo);
  return 0;
}