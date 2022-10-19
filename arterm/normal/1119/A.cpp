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

  int n;
  int x = -1, y = -1;
  int px = 1e9, py = 1e9;

  int ans = 0;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int cur;
    cin >> cur;
    if (x == -1) {
      x = cur;
      px = i;
    } else if (cur != x && y == -1) {
      y = cur;
      py = i;
    }

    if (x != cur && x != -1) {
      ans = max(ans, i - px);
    }

    if (y != cur && y != -1) {
      ans = max(ans, i - py);
    }
  }

  cout << ans << "\n";

}