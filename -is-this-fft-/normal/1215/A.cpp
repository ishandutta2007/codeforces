#include <iostream>

using namespace std;

int main () {
  int a1, a2, k1, k2, n;
  cin >> a1 >> a2 >> k1 >> k2 >> n;

  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }

  int minc = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1));
  int maxc = 0;
  if (k1 * a1 >= n) {
    maxc = n / k1;
  } else {
    maxc = a1;
    n -= k1 * a1;
    maxc += n / k2;
  }

  cout << minc << " " << maxc << endl;
}