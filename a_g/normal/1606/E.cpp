#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 505;
const ll MOD = 998244353;
vector<ll> fact(maxn);
vector<ll> invfact(maxn);

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

ll binommod(int n, int k) {
  if (n < 0 || n < k) return 0;
  return fact[n] * (invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = expmod(fact[maxn-1], MOD-2, MOD);
  for (int i = maxn-1; i > 0; i--) {
    invfact[i-1] = i*invfact[i] % MOD;
  }
  int n, x;
  cin >> n >> x;
  vector<vector<ll>> ans(maxn, vector<ll>(maxn, 0));
  for (int m = 2; m < maxn; m++) {
    for (int y = 1; y < maxn; y++) {
      ans[m][y] = expmod(min(m-1, y), m, MOD);
      if (y > m-1) {
        for (int k = 0; k < m-1; k++) {
          ans[m][y] += expmod(m-1, k, MOD)*(binommod(m, k)*ans[m-k][y-m+1] % MOD) % MOD;
          ans[m][y] %= MOD;
        }
      }
    }
  }
  cout << ans[n][x] << endl;
}