#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int x_min, x_max, y_min, y_max;
  int x[4], y[4];
  for (int i = 0; i < 4; ++i) {
    cin >> x[i] >> y[i];
  }

  x_min = *min_element(x, x + 4);
  x_max = *max_element(x, x + 4);

  y_min = *min_element(y, y + 4);
  y_max = *max_element(y, y + 4);

  for (int i = 0; i < 4; ++i) {
    cin >> x[i] >> y[i];
  }
  int X_min, X_max, Y_min, Y_max;
  X_min = *min_element(x, x + 4);
  X_max = *max_element(x, x + 4);

  Y_min = *min_element(y, y + 4);
  Y_max = *max_element(y, y + 4);

  for (int i = x_min; i <= x_max; ++i)
    for (int j = y_min; j <= y_max; ++j) {
      bool inside = true
        && i + j <= (X_max + X_min) / 2 + Y_max
        && i + j >= (X_max + X_min) / 2 + Y_min
        && i - j <= (X_max + X_min) / 2 - Y_min
        && i - j >= (X_max + X_min) / 2 - Y_max;
      if (inside) {
        cout << "Yes\n";
        return 0;
      }
    }
  cout << "No\n";
}