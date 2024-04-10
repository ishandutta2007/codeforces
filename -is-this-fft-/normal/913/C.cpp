#include <iostream>

using namespace std;

const int MAX_B = 31;

typedef long long llong;

llong cost [MAX_B];

int main () {
  int bottlec, req;
  cin >> bottlec >> req;

  for (int i = 0; i < bottlec; i++) {
    cin >> cost[i];

    if (i > 0) {
      cost[i] = min(cost[i], 2 * cost[i - 1]);
    }
  }

  for (int i = bottlec; i < MAX_B; i++) {
    cost[i] = 2 * cost[i - 1];
  }

  for (int i = MAX_B - 2; i >= 0; i--) {
    cost[i] = min(cost[i], cost[i + 1]);
  }

  llong ans = 0;
  for (int i = 0; i < MAX_B; i++) {
    ans = min(ans, cost[i]);
    if (req & 1 << i) {
      ans += cost[i];
    }
  }

  cout << ans << endl;
}