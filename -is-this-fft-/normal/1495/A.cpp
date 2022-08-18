#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef long double ld;

ll sq (ll x) {
  return x * x;
}

void solve () {
  int n;
  cin >> n;

  vector<int> xs, ys;
  for (int i = 0; i < 2 * n; i++) {
    int x, y;
    cin >> x >> y;

    if (x == 0) {
      ys.push_back(abs(y));
    } else {
      xs.push_back(abs(x));
    }
  }

  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end());

  ld ans = 0;
  for (int i = 0; i < n; i++) {
    ans += sqrt(sq(xs[i]) + sq(ys[i]));
  }
  cout << fixed << setprecision(12) << ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}