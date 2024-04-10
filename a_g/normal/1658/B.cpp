#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n&1) {
      cout << "0\n";
      continue;
    }
    int ans = 1;
    for (int i = 1; i <= n/2; i++) {
      for (int j = 0; j < 2; j++) {
        ans = 1LL * ans * i % MOD;
      }
    }
    cout << ans << '\n';
  }
}