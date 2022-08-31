#include <iostream>

using namespace std;

void solve () {
  int n, x;
  cin >> n >> x;

  int mindx = 0, kill = 0;
  for (int i = 0; i < n; i++) {
    int d, h;
    cin >> d >> h;

    mindx = max(mindx, d - h);
    kill = max(kill, d);
  }

  if (x <= kill) {
    cout << 1 << '\n';
    return;
  }
  if (mindx > 0) {
    cout << 1 + (x - kill + mindx - 1) / mindx << '\n';
    return;
  }
  cout << -1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}