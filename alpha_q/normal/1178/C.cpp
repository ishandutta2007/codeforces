#include <bits/stdc++.h>

using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
  int ans = 1;
  for (int i = 0; i < w + h; ++i) ans = ans * 2LL % 998244353;
  cout << ans << endl;
  return 0;
}