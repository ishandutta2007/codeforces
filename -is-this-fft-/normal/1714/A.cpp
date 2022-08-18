#include <iostream>

using namespace std;

void solve () {
  int n, H, M;
  cin >> n >> H >> M;

  int sleep = H * 60 + M;
  int ans = 24 * 60;
  for (int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;

    m += 60 * h;
    if (m >= sleep) {
      ans = min(ans, m - sleep);
    } else {
      ans = min(ans, m - sleep + 24 * 60);
    }
  }

  cout << ans / 60 << " " << ans % 60 << '\n';
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