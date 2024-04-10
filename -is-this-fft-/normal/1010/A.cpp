#include <iostream>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e3 + 5;

int n, m;
int a [MAX_N], b [MAX_N];

bool can (ld f) {
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      f -= (f + m) / (ld) a[i];
    }
    if (f < 0) return false;

    f -= (f + m) / (ld) b[i];
    if (f < 0) return false;
  }

  f -= (f + m) / (ld) a[0];
  if (f < 0) return false;

  return true;
}

int main () {
  ios::sync_with_stdio(false);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> a[i];

    if (a[i] == 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];

    if (b[i] == 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  ld ans = 0;
  for (ld i = (ld) (1 << 30); i > 1e-12; i /= 2) {
    if (!can(ans + i)) {
      ans += i;
    }
  }

  cout << fixed << setprecision(12) << ans << endl;
}