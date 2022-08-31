#include <iostream>

typedef long long llong;

using namespace std;

int main () {
  llong coinscore;
  cin >> coinscore;

  bool ans = false;
  for (llong i = 0; i < 1000000000; i += 1234567) {
    for (llong j = 0; j < 1000000000; j += 123456) {
      if (i + j <= coinscore &&
          (coinscore - (i + j)) % 1234 == 0) {
        ans = true;
      }
    }
  }

  cout << (ans ? "YES" : "NO") << endl;
}