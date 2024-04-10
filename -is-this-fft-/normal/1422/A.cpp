#include <iostream>

using namespace std;

void solve () {
  int a, b, c;
  cin >> a >> b >> c;

  cout << max(max(0, a - b - c), max(b - a - c, c - a - b)) + 1 << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}