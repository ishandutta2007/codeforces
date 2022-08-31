#include <iostream>
#include <map>

using namespace std;

int sq (int x) {
  return x * x;
}

int main () {
  int a, b;
  cin >> a >> b;

  map<int, int> sqrts;
  for (int i = 0; i <= 1000; i++) {
    sqrts[sq(i)] = i;
  }

  int p = -1, q = -1;
  for (int d = 1; d <= min(a, b); d++) {
    if (a % d == 0 && b % d == 0) {
      for (int i = 1; i < d; i++) {
        if (sqrts.count(sq(d) - sq(i))) {
          p = i;
          q = sqrts[sq(d) - sq(i)];

          int ma = a / d;
          int mb = b / d;

          if (q * ma != p * mb) {
            cout << "YES" << endl;
            cout << 0 << " " << 0 << endl;
            cout << p * ma << " " << q * ma << endl;
            cout << -q * mb << " " << p * mb << endl;
            return 0;
          }
        }
      }
    }
  }

  cout << "NO" << endl;
  return 0;
}