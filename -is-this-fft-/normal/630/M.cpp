#include <iostream>
#include <algorithm>

using namespace std;

long long mod (long long a, long long b) {
  long long ans = a % b;
  if (ans < 0) ans += b;
  if (ans > 180) ans = 360 - ans;
  return ans;
}

int main () {
  long long angle;
  cin >> angle;

  int ans, bestan = 361;
  for (int i = 0; i < 4; i++) {
    if (mod((i * 90 - angle), 360) < bestan) {
      ans = i;
      bestan = mod((i * 90 - angle), 360);
    }
  }

  cout << ans << endl;
}