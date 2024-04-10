#include <iostream>

using namespace std;

int gcd (int p, int q) {
  if (q == 0) return p;
  return gcd(q, p % q);
}

int main () {
  int n;
  cin >> n;

  int gc = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    gc = gcd(gc, x);
    mx = max(mx, x);
  }

  int ans = (mx / gc) - n;
  if (ans % 2 == 0) {
    cout << "Bob" << '\n';
  } else {
    cout << "Alice" << '\n';
  }
}