#include <iostream>

const int INF = 101;

using namespace std;

int main () {
  int dayc;
  cin >> dayc;

  int ans = 0, cmin = INF;
  for (int i = 0; i < dayc; i++) {
    int req, cost;
    cin >> req >> cost;
    cmin = min(cmin, cost);
    ans += req * cmin;
  }

  cout << ans << endl;
}