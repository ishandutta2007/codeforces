#include <iostream>

typedef long long llong;

using namespace std;

llong fastexp (llong base, llong exponent) {
  llong powers [32];
  
  powers[0] = base;
  for (int i = 1; i < 32; i++) {
    powers[i] = powers[i - 1] * powers[i - 1];
  }

  llong ans = 1LL;
  for (int i = 0; i < 32; i++) {
    if (exponent & 1LL << i) {
      ans *= powers[i];
    }
  }

  return ans;
}

int main () {
  llong spacec;
  cin >> spacec;

  cout << 2 * 4 * 3 * fastexp(4, spacec - 3) +
    (spacec - 3) * 4 * 9 * fastexp(4, spacec - 4) << endl;
}