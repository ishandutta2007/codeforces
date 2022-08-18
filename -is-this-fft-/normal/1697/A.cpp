#include <iostream>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    m -= x;
  }

  cout << max(0, -m) << '\n';
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