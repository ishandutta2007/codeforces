#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main () {
  int guyc, girlc;
  cin >> guyc >> girlc;

  vector<int> guys (guyc), girls (girlc);
  for (int i = 0; i < guyc; i++) {
    cin >> guys[i];
  }
  for (int i = 0; i < girlc; i++) {
    cin >> girls[i];
  }

  sort(guys.begin(), guys.end());
  sort(girls.begin(), girls.end());

  if (guys.back() > girls.front()) {
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  for (int i = 0; i < guyc; i++) {
    ans += (ll) guys[i] * (ll) girlc;
  }

  for (int i = 0; i < girlc; i++) {
    ans += girls[i];
  }

  if (guys.back() < girls.front()) {
    ans -= (ll) guys.back() * (ll) (girlc - 1);
    ans -= guys[guyc - 2];
  } else {
    ans -= (ll) guys.back() * (ll) girlc;
  }

  cout << ans << endl;
}