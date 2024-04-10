#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int x;
  string y, z;
  cin >> x >> y >> z;
  int ans = 0;
  if (z == "month") {
    for (int p: {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}) {
      if (p >= x) ans++;
    }
  }
  else {
    for (int p = 0; p < 366; p++) {
      int day = (5+p)%7;
      if (day == 0) day = 7;
      if (day == x) ans++;
    }
  }
  cout << ans << '\n';
}