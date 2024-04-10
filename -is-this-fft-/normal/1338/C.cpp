#include <iostream>

using namespace std;

typedef long long ll;

ll maps (ll x) {
  if (x == 0) return 0;
  if (x == 1) return 2;
  if (x == 2) return 3;
  if (x == 3) return 1;
  return 0;
}

void solve () {
  ll idx;
  cin >> idx;
  idx--;

  ll block = idx / 3;
  ll elm = idx % 3;

  ll grp = 0;
  while (block >= 1LL << grp) {
    block -= (1LL << grp);
    grp += 2;
  }

  ll a = (1LL << grp) + block;
  ll b = 0;
  for (int k = 0; k < 60; k += 2) {
    b += maps((a >> k) & 3) << k;
  }
  ll c = a ^ b;

  if (elm == 0) cout << a << '\n';
  if (elm == 1) cout << b << '\n';
  if (elm == 2) cout << c << '\n';
}

int main () {
  ios::sync_with_stdio(false);

  int testc;
  cin >> testc;

  for (int t = 0; t < testc; t++) {
    solve();
  }
}