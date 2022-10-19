#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

ll expmod(ll a, ll b, int m) {
  int res = 1;
  a = a % m; 
  if (a == 0) return 0;
  while (b > 0) {
    if (b & 1) {
      res = (res*a) % m;
    }
    b = b>>1;
    a = (a*a) % m;
  }
  return res;
}

int v2(int n) {
  int k = 0;
  while (!(n&1)) {
    n >>= 1;
    k++;
  }
  return k;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(32);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    p[v2(a)]++;
  }
  ll ans = 0;
  int total = n;
  for (int i = 0; i < 32; i++) {
    if (i == 0) {
      ans += (expmod(2, p[i], MOD) - 1)*(expmod(2, total-p[0], MOD)) % MOD;
    }
    else {
      ans += (expmod(2, max(0, p[i]-1), MOD) - 1)*(expmod(2, total-p[i], MOD)) % MOD;
      ans %= MOD;
    }
    total -= p[i];
  }
  cout << ans << endl;
}