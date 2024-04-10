#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;

const int maxn = 1e6+2;
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

ll g(int n, int k) {
  if (k < 0) return 0;
  return binommod(n-k+1, k);
}

ll f(int n, int k) {
  return (g(n, k) -g(n-4, k-2) + MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n;
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = expmod(fact[maxn-1], MOD-2, MOD);
  for (int i = maxn-1; i > 0; i--) {
    invfact[i-1] = i*invfact[i] % MOD;
  }
  ll ans = 0;
  for (int k = 0; k <= n/2; k++) {
    if (n%2 == k%2) {
      ans = (ans + 2*fact[n-k]*f(n, k)) % MOD;
    }
  }
  cout << ans << endl;
}