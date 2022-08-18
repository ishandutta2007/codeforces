#include <iostream>

using namespace std;

int cntb (int r, int k) {
  int rm = r % (1 << k);
  r /= 1 << k;

  int ans = (r / 2) * (1 << k);
  if (r % 2 == 1) {
    ans += 1 + rm;
  }
  return ans;
}

int cntb (int l, int r, int k) {
  return cntb(r, k) - cntb(l - 1, k);
}

void solve () {
  int l, r;
  cin >> l >> r;

  int ans = 0;
  for (int k = 0; k < 20; k++) {
    ans = max(ans, cntb(l, r, k));
  }
  
  cout << (r - l) + 1 - ans << '\n';
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int testc;
  cin >> testc;

  for (int i = 0; i < testc; i++) {
    solve();
  }
}