#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

ll n, dx[2], dy[2];

int main() {
  cin >> n >> dx[0] >> dy[0] >> dx[1] >> dy[1];
  ll det = abs(dx[0] * dy[1] - dx[1] * dy[0]);
  if (det != n) {
    cout << "NO\n";
    return 0;
  }
  ll one = __gcd(abs(dx[0]), abs(dx[1])), two = n / one;
  cout << "YES\n";
  for (int i = 0; i < one; ++i) {
    for (int j = 0; j < two; ++j) {
      printf("%d %d\n", i, j);
    }
  }
  return 0;
}