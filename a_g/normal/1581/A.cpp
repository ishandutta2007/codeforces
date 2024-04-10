#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 3; i <= 2*n; i++) ans = 1LL*i*ans % MOD;
    cout << ans << '\n';
  }
}