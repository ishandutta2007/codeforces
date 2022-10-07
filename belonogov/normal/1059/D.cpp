#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>

#define F first
#define S second
#define pb push_back
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define pw(x) (1LL<<(x))

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl

using namespace std;

typedef long long ll;
typedef double dbl;
const int INF = 1.01e9;

struct pt {
  double x, y;
};


int main() {
#define TASK "A"
#ifdef HOME
  assert(freopen(TASK".in", "r", stdin));
#endif
  int n;
  scanf("%d", &n);
  vector<pt> p(n);
  bool have_down = 0;
  bool have_up = 0;
  double mn_x = INF;
  double mx_x = -INF;
  for (int i = 0; i < n; i++) {
    scanf("%lf%lf", &p[i].x, &p[i].y);
    mn_x = min(mn_x, p[i].x);
    mx_x = max(mx_x, p[i].x);
    if (p[i].y < 0) {
      have_down = 1;
    }
    if (p[i].y > 0) {
      have_up = 1;
    }
  }
  if (have_up && have_down) {
    puts("-1");
    return 0;
  }

  if (have_down) {
    for (auto& A: p) {
      A.y *= -1;
    }
  }


  auto f = [&](double cur_x) {
    double r = 0;
    for (auto A: p) {
      double dx = abs(A.x - cur_x);
      r = max(r, A.y / 2 + dx / 2 * dx / A.y);
    }
    return r;
  };

  double FI = (sqrt(5) - 1) / 2;

  double L = mn_x;
  double R = mx_x;

  double fl = f(R - (R - L) * FI);
  double fr = f(L + (R - L) * FI);

  for (int it = 0; it < 100; it++) {
    if (fl < fr) {
      R = L + (R - L) * FI;
      fr = fl;
      fl = f(R - (R - L) * FI);
    }
    else {
      L = R - (R - L) * FI;
      fl = fr;
      fr = f(L + (R - L) * FI);
    }
  }

  printf("%.17f\n", fl);
  return 0;
}