#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int r;
  cin >> r;
  int ans;
  for (int v: {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000}) {
    if (r < v) {
      ans = v;
      break;
    }
  }
  cout << ans << '\n';
}