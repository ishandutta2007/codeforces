#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 1000000007;
const int maxn = 2e5;
vector<vector<int>> divisors(maxn);
vector<int> phi(maxn);
vector<int> phisum(maxn);

/*
int g(int n, int a, int b) {
  return max(n-a-b, __gcd(n-a, n-b));
}
*/

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

int h(int n, int i) {
  // a+b = n+i, gcd(a, b) < i
  int ans = -2*i;
  for (int d: divisors[n+i]) {
    if (d >= i) break;
    ans += phi[(n+i)/d];
  }
  // if (n % i == 0) ans += 2;

  // gcd(a, b) = i, a+b <= n+i
  ans += phisum[n/i+1]-1;
  // if (n % i == 0) ans -= 2;
  return ans;
}

// g(n, n-a, n-b) = max(a+b-n, gcd(a, b))

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  iota(phi.begin(), phi.end(), 0);
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      divisors[j].push_back(i);
      if (j != i) phi[j] -= phi[i];
    }
    phisum[i] = (phisum[i-1] + phi[i]) % MOD;
  }

  int n, k;
  cin >> n >> k;
  vector<ll> powers(n);
  powers[0] = 1;
  for (int i = 0; i < n-1; i++) {
    powers[i+1] = k*powers[i] % MOD;
  }

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans = (ans + powers[i]*h(n, i)) % MOD;
  }
  ans = (ans * expmod(k, MOD-1-n, MOD)) % MOD;
  cout << ans << endl;
}