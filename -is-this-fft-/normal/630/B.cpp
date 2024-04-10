#include <iostream>
#include <math.h>

typedef long double ldouble;

const ldouble change = 1.000000011L;

using namespace std;

ldouble fastexp (ldouble base, long long exponent) {
  ldouble powers [32];
  
  powers[0] = base;
  for (int i = 1; i < 32; i++) {
    powers[i] = powers[i - 1] * powers[i - 1];
  }

  ldouble ans = 1.0L;
  for (int i = 0; i < 32; i++) {
    if (exponent & 1LL << i) {
      ans *= powers[i];
    }
  }

  return ans;
}

int main () {
  int initial, tchange;

  cin >> initial >> tchange;
  
  cout << (ldouble) initial * fastexp(change, tchange) << endl;
}