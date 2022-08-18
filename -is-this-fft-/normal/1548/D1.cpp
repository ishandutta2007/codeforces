#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll pc (ll x) {
  return (x * (x - 1)) / 2;
}

ll tc (ll x) {
  return (x * (x - 1) * (x - 2)) / 6;
}

int main () {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> cnts (4, 0);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    x %= 4; y %= 4;
    x /= 2; y /= 2;
    int clr = 2 * x + y;
    cnts[clr]++;
  }

  ll ans = 0;
  for (int x : cnts) {
    ans += tc(x);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      ans += pc(cnts[i]) * (ll) cnts[j];
    }
  }

  cout << ans << endl;
}