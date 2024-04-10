#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int f = 1;
  for (int i = 1; i <= n; i++) {
    f = 1LL*f*i % MOD;
  }
  int ans = 1LL*n*f % MOD;
  f = 1;
  for (int i = n; i >= 2; i--) {
    f = 1LL*f*i % MOD;
    ans -= f;
    if (ans < 0) ans += MOD;
  }
  cout << ans << '\n';
}