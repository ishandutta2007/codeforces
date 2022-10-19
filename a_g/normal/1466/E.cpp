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
    vector<int> c(60);
    vector<long long> a(n);
    for (long long& x: a) {
      cin >> x;
      for (int j = 0; j < 60; j++) {
        if ((x>>j)&1) c[j]++;
      }
    }
    int ans = 0;
    for (long long x: a) {
      int l = 0, r = 0;
      for (int i = 0; i < 60; i++) {
        if ((x>>i)&1) {
          l += ((1LL<<i) % MOD) * (c[i]) % MOD;
          l %= MOD;
          r += ((1LL<<i) % MOD) * n % MOD;
          r %= MOD;
        }
        else {
          r += ((1LL<<i) % MOD) * (c[i]) % MOD;
          r %= MOD;
        }
      }
      ans += 1LL * l * r % MOD;
      ans %= MOD;
    }
    cout << ans << '\n';
  }
}