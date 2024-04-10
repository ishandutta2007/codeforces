#include <iostream>

using namespace std;

int gcd (int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve () {
  int a, b;
  cin >> a >> b;

  if (gcd(a, b) == 1) {
    cout << "Finite" << '\n';
  } else {
    cout << "Infinite" << '\n';
  }
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;
  for (int i = 0; i < testc; i++) {
    solve();
  }
}