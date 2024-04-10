#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, MOD;
  cin >> n >> m >> MOD;
  int ans = 0;
  int coeff = 1;
  for (int i = 0; i <= m-2; i++) {
    ans = 1LL*ans*(n+1) % MOD;
    ans += coeff;
    if (ans >= MOD) ans -= MOD;
    coeff = 1LL*coeff*(m-2-i) % MOD;
  }
  ans = 1LL*(m*(m-1)*(n+1-m))*ans % MOD;
  for (int i = 0; i < m-1; i++) {
    ans = 2*ans;
    if (ans >= MOD) ans -= MOD;
  }
  cout << ans << '\n';
}