#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;
const int MAX_IT = 200;

ld x [MAX_N], y [MAX_N];

ld sq (ld p) {
  return p * p;
}

ld minrad (ld x0, int i) {
  return (sq(x[i]) + sq(y[i]) + sq(x0) - 2 * x0 * x[i]) / (2 * y[i]);
}

int n;

ld tryx0 (ld x0) {
  ld r = 0;
  for (int i = 0; i < n; i++) {
    r = max(r, minrad(x0, i));
  }
  return r;
}

ld ternary (ld l, ld u, int k) {
  if (k > MAX_IT) return tryx0((l + u) / 2);
  
  ld m1 = l + (u - l) / 3;
  ld m2 = u - (u - l) / 3;

  ld r1 = tryx0(m1);
  ld r2 = tryx0(m2);

  if (r1 < r2) return ternary(l, m2, k + 1);
  else return ternary(m1, u, k + 1);
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n;

  int seenn = 0, seenp = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];

    if (y[i] < 0) {
      y[i] *= -1;
      seenn = 1;
    } else if (y[i] > 0) {
      seenp = 1;
    }
  }

  if (seenn && seenp) {
    cout << -1 << endl;
    return 0;
  }

  cout << fixed << setprecision(12) << ternary(-1e7, 1e7, 0) << endl;
}