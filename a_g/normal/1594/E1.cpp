#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 

  if (a == 0) return 0;

  while (b > 0)
  {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int k;
  cin >> k;
  ll power = (1LL << k) - 2;
  ll ans = expmod(4, power, MOD);
  ans *= 6;
  ans %= MOD;
  cout << ans << endl;
}