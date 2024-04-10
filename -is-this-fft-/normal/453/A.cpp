#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

const int MAX_N = 1e5 + 5;

ld prob [MAX_N];

int main () {
  ios::sync_with_stdio(false);

  int m, n;
  cin >> m >> n;

  for (int i = 1; i <= m; i++) {
    prob[i] = exp((ld) n * (log((ld) i) - log((ld) m)));
  }

  for (int i = m; i >= 1; i--) {
    prob[i] -= prob[i - 1];
  }

  ld ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += i * prob[i];
  }
  cout << fixed << setprecision(12) << ans << endl;
}