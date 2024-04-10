#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 300010;
const int MOD = 1e9 + 7;

int n;
ll two[N], a[N];

int main (int argc, char const *argv[]) {
  two[0] = 1ll;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    two[i] = (2ll * two[i - 1]) % MOD;
  }
  sort(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll cur = a[i];
    ll add = (cur * two[i - 1]) % MOD;
    ll sub = (cur * two[n - i]) % MOD;
    ans += add, ans -= sub, ans %= MOD;
  }
  ans += MOD, ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}