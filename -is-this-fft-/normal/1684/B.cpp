#include <iostream>

using namespace std;

void solve () {
  int a, b, c;
  cin >> a >> b >> c;

  cout << a + b + c << " " << b + c << " " << c << '\n';
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