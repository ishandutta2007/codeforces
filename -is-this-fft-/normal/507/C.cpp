#include <iostream>

using namespace std;

typedef long long llong;

int main () {
  llong height, exitl;
  cin >> height >> exitl;
  exitl--;

  llong ans = 0;
  llong state = 0; /* 0 is left */
  for (llong i = height - 1; i >= 0; i--) {
    ans++; /* account for this vertex */
    llong exit_dir = (exitl >> i) & 1;
    if (state == 0) {
      if (exit_dir == 0) {
        state = !state;
      } else {
        ans += (1LL << (i + 1)) - 1;
      }
    } else if (state == 1) {
      if (exit_dir == 1) {
        state = !state;
      } else {
        ans += (1LL << (i + 1)) - 1;
      }
    }
  }

  cout << ans << endl;
}