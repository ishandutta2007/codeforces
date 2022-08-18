#include <iostream>

const long long MODULUS = 1000000007;

using namespace std;

int main () {
  long long all = 1, bad = 1, gnomec;

  cin >> gnomec;
  for (int i = 0; i < gnomec; i++) {
    all *= 27;
    all %= MODULUS;
    bad *= 7;
    bad %= MODULUS;
  }

  cout << (all - bad + MODULUS) % MODULUS << endl;
}