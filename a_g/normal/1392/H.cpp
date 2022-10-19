#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int maxn = 4e6+5;
vector<ll> fact(maxn);
vector<ll> invfact(maxn);
vector<ll> inv(maxn);

// Let f(t) be the expected number of steps given that t cards are still missing
// Claim: f(t) = (m+n+1)p(t) where p(t) is a function of m and t
// p(1) = (m+1)(2/((m+1)(m+2)) + m/((m+1)(m+2))) = 1
// p(2) = (3m+2)/(2m+2)
// Let s(k) = p(0) + (m choose 1) p(1) + (m+1 choose 2)p(2) + ...
// Then (m+k choose k)p(k) = s(k) + (1/(m+k+1))((m choose 0) + (m+1 choose 1) + ... + (m+k choose k))
// Recurrence relation of s:
// s(k) = ((m+k)/k)s(k-1) + (m/(k(m+k+1)))(sum)

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

ll binommod(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * (invfact[k]*invfact[n-k] % MOD) % MOD;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, m;
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i < maxn; i++) {
    fact[i] = i*fact[i-1] % MOD;
  }
  invfact[maxn-1] = inversemod(fact[maxn-1], MOD);
  for (int i = maxn-1; i >= 1; i--) {
    invfact[i-1] = i*invfact[i] % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < maxn; i ++) {
    inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  vector<ll> g(n+1);
  g[0] = 1;
  for (int k = 1; k <= n; k++) {
    g[k] = (g[k-1] + binommod(m+k, k)) % MOD;
  }
  vector<ll> s(n+1);
  s[0] = 0;
  for (int k = 1; k <= n; k++) {
    ll a = s[k-1]*((m+k)*inv[k] % MOD) % MOD;
    a += (m*g[k] % MOD) * (inv[k]*inv[m+k+1] % MOD) % MOD;
    s[k] = a;
  }
  ll ans = ((s[n]-s[n-1]) * inversemod(binommod(m+n-1, n), MOD) % MOD) * (m+n+1) % MOD;
  cout << (ans+MOD)%MOD << endl;
}