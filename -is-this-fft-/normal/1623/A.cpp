#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  int x, y, tx, ty;
  cin >> x >> y >> tx >> ty;

  int dx = 1, dy = 1;

  int ans = 0;
  while (true) {
    if (x == tx || y == ty) {
      break;
    }

    if (x + dx > n) {
      dx *= -1;
    }

    if (x + dx < 0) {
      dx *= -1;
    }

    if (y + dy > m) {
      dy *= -1;
    }

    if (y + dy < 0) {
      dy *= -1;
    }

    x += dx;
    y += dy;
    ans++;
  }

  cout << ans << '\n';
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