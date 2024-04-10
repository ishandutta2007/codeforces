#include <iostream>

using namespace std;

typedef long long ll;

ll tris (int lines) {
  ll a = lines / 3, b = lines / 3, c = lines / 3;
  if (lines % 3 >= 1) a++;
  if (lines % 3 >= 2) b++;

  return 2 * (a * b + a * c + b * c);
}

void solve () {
  int n;
  cin >> n;

  int ans = 0;
  for (int k = 1 << 29; k != 0; k /= 2) {
    if (tris(ans + k) < n) {
      ans += k;
    }
  }

  cout << ans + 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}