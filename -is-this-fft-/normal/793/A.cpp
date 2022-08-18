#include <iostream>

const int MAX_SHARE = 100005;
const int INF = 1023456789;

using namespace std;

int shares [MAX_SHARE];

int main () {
  int sharec, decay;
  cin >> sharec >> decay;

  int minshare = INF;
  for (int i = 0; i < sharec; i++) {
    cin >> shares[i];
    minshare = min(minshare, shares[i]);
  }

  long long ans = 0;
  for (int i = 0; i < sharec; i++) {
    if ((shares[i] - minshare) % decay != 0) {
      cout << -1 << endl;
      return 0;
    } else {
      ans += (shares[i] - minshare) / decay;
    }
  }

  cout << ans << endl;
}