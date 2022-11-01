#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

int x, y, z, t1, t2, t3;

int main() {
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stair = abs(x - y) * t1;
  int elev = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
  // cout << stair << " " << elev << endl;
  cout << (stair < elev ? "NO" : "YES") << '\n';
  return 0;
}