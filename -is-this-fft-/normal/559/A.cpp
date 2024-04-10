#include <iostream>

using namespace std;

int main () {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int ans = 0;

  int n_grow = min(b, f);
  int n_shrink = min(c, e);
  int n_stab = b + c - n_grow - n_shrink;

  int bw = a;
  for (int i = 0; i < n_grow; i++) {
    ans += 2 * bw + 1;
    bw++;
  }

  for (int i = 0; i < n_stab; i++) {
    ans += 2 * bw;
  }

  for (int i = 0; i < n_shrink; i++) {
    ans += 2 * bw - 1;
    bw--;
  }

  cout << ans << endl;
}