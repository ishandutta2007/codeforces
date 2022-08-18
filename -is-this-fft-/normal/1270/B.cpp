#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  int prev = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;

    if (i != 1) {
      if (x - prev > 1 || x - prev < - 1) {
        cout << "YES" << '\n' << i - 1 << " " << i << '\n';
        for (int j = i + 1; j <= n; j++) {
          cin >> x;
        }
        return;
      }
    }

    prev = x;
  }

  cout << "NO" << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}