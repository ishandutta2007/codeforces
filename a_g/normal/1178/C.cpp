#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int w, h;
  cin >> w >> h;
  int ans = 1;
  for (int i = 0; i < w+h; i++) {
    ans = 2*ans % MOD;
  }
  cout << ans << '\n';
}