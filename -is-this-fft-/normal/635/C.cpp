#include <iostream>

typedef long long llong;

using namespace std;

int main () {
  llong sum, bxor;
  cin >> sum >> bxor;

  llong band = sum - bxor;
  if (band < 0 || band % 2 == 1) {
    cout << 0 << endl;
  } else {
    band /= 2;
    llong ans = 1;
    for (int i = 0; i < 62; i++) {
      if ((bxor & 1LL << i) && (band & 1LL << i)) {
	ans *= 0LL;
      } else if ((bxor & 1LL << i) && !(band & 1LL << i)) {
	ans *= 2LL;
      }
    }
    
    if (bxor == sum) {
      ans -= 2; /* Discount the possib that a == 0 or b == 0 */
    }

    cout << ans << endl;
  }
}