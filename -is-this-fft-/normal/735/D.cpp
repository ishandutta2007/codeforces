#include <iostream>
using namespace std;

typedef long long llong;

const int MAX_PRIME = 50000;

bool is_prime (llong num) {
  for (llong i = 2; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int main () {
  llong income;
  cin >> income;

  if (is_prime(income)) {
    cout << 1 << endl;
  } else if (is_prime(income - 2)) {
    cout << 2 << endl;
  } else if (income % 2 == 0) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }
}