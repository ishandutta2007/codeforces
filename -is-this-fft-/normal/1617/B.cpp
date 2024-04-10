#include <iostream>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

void solve () {
  int n;
  cin >> n;

  n--;

  for (int i = 2; true; i++) {
    if (gcd(i, n - i) == 1) {
      cout << i << " " << n - i << " " << 1 << '\n';
      return;
    }
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