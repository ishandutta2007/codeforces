#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500010;
const int MOD = 998244353;

int n; ll pwr[N];

int main() {
  pwr[0] = 1;
  for (int i = 1; i < N; ++i) pwr[i] = 10LL * pwr[i - 1] % MOD;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    ll cur = (i == n - 1) ? 0 : (810LL * pwr[n - i - 2] % MOD);
    cur = cur * (n - i - 1) % MOD;
    cur = (cur + 180LL * pwr[n - i - 1]) % MOD;
    printf("%lld ", cur);
  }
  puts("10");
  return 0;
}