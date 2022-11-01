#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  long long ans = 1, two = 1;
  for (int i = 1; i <= n; ++i) {
    ans = ans * i % MOD;
    if (i < n) two = two * 2 % MOD;
  }
  ans += MOD - two, ans %= MOD;
  cout << ans << endl;
  return 0;
}