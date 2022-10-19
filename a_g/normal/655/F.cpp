#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6+5;
int fact[maxn];
int invfact[maxn];
int inv[maxn];
int counts[maxn];
vector<int> phi(maxn);
vector<int> divisors[maxn];
const int MOD = 1000000007;

ll inversemod(ll p, ll q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  ll k = q/p;
  ll b = inversemod(q-k*p, p);
  ll a = (1-b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (1LL*invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = inversemod(fact[maxn-1], MOD);
  for (int i = maxn-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }

  inv[1] = 1;
  for (int i = 2; i < maxn; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  iota(phi.begin(), phi.end(), 0);
  for (int i = 1; i < maxn; i++) {
    for (int j = 2*i; j < maxn; j += i) {
      phi[j] -= phi[i];
    }
  }
  for (int i = 1; i < maxn; i++) {
    for (int j = i; j < maxn; j += i) {
      divisors[j].push_back(i);
    }
  }

  int n, k, q;
  cin >> n >> k >> q;

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int d: divisors[a]) {
      ans += 1LL*phi[d]*binommod(counts[d], k-1) % MOD;
      ans %= MOD;
      counts[d]++;
    }
  }
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    for (int d: divisors[a]) {
      ans += 1LL*phi[d]*binommod(counts[d], k-1) % MOD;
      ans %= MOD;
      counts[d]++;
    }
    cout << ans << '\n';
  }
}