#include <iostream>

using namespace std;

void solve () {
  int n;
  cin >> n;

  cout << n - 3 << " " << 1 << " " << 1 << " " << 1 << '\n';
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