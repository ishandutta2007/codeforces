#include <iostream>

using namespace std;

int main () {
  int n, p;
  cin >> n >> p;

  for (int k = 1; k <= 1000; k++) {
    if (n - k * p < 0) break;

    if (__builtin_popcount(n - k * p) <= k && n - k * p >= k) {
      cout << k << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}