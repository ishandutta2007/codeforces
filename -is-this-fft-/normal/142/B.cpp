#include <iostream>

using namespace std;

int main () {
  int a, b;
  cin >> a >> b;

  if (min(a, b) == 1) {
    cout << a * b << '\n';
  } else if (min(a, b) == 2) {
    int mx = max(a, b);
    int ans = 4 * (mx / 4);
    if (mx % 4 != 0) {
      ans += 2;
      if (mx % 4 != 1) {
        ans += 2;
      }
    }
    cout << ans << '\n';
  } else {
    cout << (a * b + 1) / 2 << '\n';
  }
}