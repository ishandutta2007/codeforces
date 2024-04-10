#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int expmod(long long a, long long b, int m) {
  int ans = 1;
  a %= m;
  while (b) {
    if (b&1) ans = 1LL*ans*a % m;
    b >>= 1;
    a = 1LL*a*a % m;
  }
  return ans;
}

const int half = expmod(2, MOD-2, MOD);

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int l, r, m, n;
  cin >> n >> m >> l >> r;
  long long e = 1LL*m*n;
  int a = expmod(r-l+1, e, MOD);
  if (e%2 != 0) {
    cout << a << '\n';
  }
  else if (r%2 != l%2) {
    cout << (1LL*a*half)% MOD << '\n';
  }
  else {
    cout << (1LL*(a+1)*half)% MOD << '\n';
  }
}