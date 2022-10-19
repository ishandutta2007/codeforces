#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int inf = 1e9;

int main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  int cur = 0;
  int up = inf;
  int down = -inf;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    int c, d;
    cin >> c >> d;
    if (d == 1) {
      down = max(down, 1900 - cur);
    } else {
      up = min(up, 1899 - cur);
    }
    cur += c;
  }

  if (down > up) {
    cout << "Impossible\n";
    return 0;
  }

  if (up == inf) {
    cout << "Infinity\n";
    return 0;
  }

  cout << up + cur << endl;
}