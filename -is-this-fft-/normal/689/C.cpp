#include <iostream>

typedef long long llong;

using namespace std;

llong wayc (llong val) {
  llong sum = 0;
  for (llong i = 2; i <= (1LL << 18); i++) {
    sum += val / (i * i * i);
  }
  return sum;
}

int main () {
  llong ways;
  cin >> ways;

  llong ans = 0;
  for (llong k = (1LL << 52); k != 0; k /= 2) {
    llong cur = ans + k;
   
    llong sum = 0;
    for (llong i = 2; i <= (1LL << 18); i++) {
      sum += cur / (i * i * i);
    }

    if (sum < ways) {
      ans += k;
    }
  }

  cerr << wayc(ans + 1) << endl;
  if (wayc(ans + 1) == ways) {
    cout << ans + 1 << endl;
  } else {
    cout << -1 << endl;
  }
}