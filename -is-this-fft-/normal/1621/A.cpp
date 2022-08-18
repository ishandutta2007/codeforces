#include <iostream>

using namespace std;

void solve () {
  int n, K;
  cin >> n >> K;

  if (2 * (K - 1) >= n) {
    cout << -1 << '\n';
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j && i % 2 == 0 && i / 2 < K) {
        cout << 'R';
      } else {
        cout << '.';
      }
    }
    cout << '\n';
  }
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