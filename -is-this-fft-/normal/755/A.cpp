#include <iostream>

using namespace std;

bool not_prime [1000005];

int main () {
  for (int i = 2; i < 1000005; i++) {
    if (!not_prime[i]) {
      for (int j = 2 * i; j < 1000005; j += i) {
        not_prime[j] = true;
      }
    }
  }

  int n;
  cin >> n;

  for (int i = 1; i <= 1000; i++) {
    if (not_prime[n * i + 1]) {
      cout << i << endl;
      break;
    }
  }
}