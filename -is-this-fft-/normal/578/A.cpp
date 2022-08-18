#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const ld INF = 1e10;

ld fcase (ld a, ld b) {
  ld kx = (a - b) / 2;
  if (kx < b) return INF;

  int k = (int) (kx / b);
  return kx / k;
}

ld scase (ld a, ld b) {
  ld lx = (a + b) / 2;
  if (lx < b) return INF;

  int l = max(1, (int) (lx / b));
  return lx / l;
}

int main () {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << a << endl;
    return 0;
  }

  if (a < b) {
    cout << -1 << endl;
    return 0;
  }

  cout << fixed << setprecision(12) << min(fcase(a, b), scase(a, b)) << endl;
}