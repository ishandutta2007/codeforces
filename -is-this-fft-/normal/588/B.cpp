#include <iostream>

using namespace std;

int main () {
  long long product;
  cin >> product;

  for (long long i = 2; i * i <= product; i++) {
    while (product % (i * i) == 0) {
      product /= i;
    }
  }

  cout << product << endl;
}