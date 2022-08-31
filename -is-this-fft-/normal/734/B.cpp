#include <iostream>

using namespace std;

int main () {
  long long twoc, threec, fivec, sixc, ans = 0;
  cin >> twoc >> threec >> fivec >> sixc;
  sixc = min(sixc, fivec);
  ans += min(sixc, twoc) * 256;
  twoc -= min(sixc, twoc);
  ans += min(threec, twoc) * 32;
  cout << ans << endl;
}