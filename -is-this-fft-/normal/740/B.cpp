#include <iostream>

typedef long long llong;

const int MAX_FLOWER = 105;

using namespace std;

llong mood [MAX_FLOWER], cummood [MAX_FLOWER], val [MAX_FLOWER];

int main () {
  llong flowerc, arrc;
  cin >> flowerc >> arrc;

  for (llong i = 0; i < flowerc; i++) {
    cin >> mood[i];
  }

  cummood[0] = mood[0];
  for (llong i = 1; i < flowerc; i++) {
    cummood[i] = cummood[i - 1] + mood[i];
  }

  for (llong i = 0; i < arrc; i++) {
    llong l, r;
    cin >> l >> r;
    l--;
    r--;

    if (l == 0) {
      val[i] = cummood[r];
    } else {
      val[i] = cummood[r] - cummood[l - 1];
    }
  }

  llong ans = 0;
  for (llong i = 0; i < arrc; i++) {
    if (val[i] > 0) {
      ans += val[i];
    }
  }

  cout << ans << endl;
}