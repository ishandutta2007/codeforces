#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;

ld mxp [MAX_N];
ld mnp [MAX_N];

ld mxpref [MAX_N];
ld mnsuff [MAX_N];

ld p [MAX_N];
ld q [MAX_N];

// solves the equation a + b = u, ab = v
pair<ld, ld> solve (ld v, ld u) {
  ld D = u * u - 4 * v;
  ld sD;
  if (D < 0) {
    sD = 0;
  } else {
    sD = sqrt(D);
  }
  
  ld a = (u + sD) / 2;
  ld b = u - a;
  return make_pair(a, b);
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> mxp[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> mnp[i];
  }

  for (int i = 1; i <= n; i++) {
    mxpref[i] = mxpref[i - 1] + mxp[i];
  }

  for (int i = n; i >= 1; i--) {
    mnsuff[i] = mnsuff[i + 1] + mnp[i];
  }

  for (int i = 1; i <= n; i++) {
    auto sol = solve(mxpref[i], mxpref[i] - mnsuff[i + 1] + 1);
    p[i] = sol.first;
    q[i] = sol.second;

    if (p[i] > q[i]) {
      swap(p[i], q[i]); // probably inadequate
    }
  }

  for (int i = n; i >= 1; i--) {
    p[i] -= p[i - 1];
    q[i] -= q[i - 1];
  }

  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(10) << p[i] << " ";
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << fixed << setprecision(10) << q[i] << " ";
  }
  cout << endl;
}