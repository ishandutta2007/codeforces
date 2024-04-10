#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;
const int MOD = 1e9 + 7;

vector <int> g[N];
int t, n, m, sub[N];
vector <ll> primes, weights;

void go (int u = 1, int pr = -1) {
  sub[u] = 1;
  for (int v : g[u]) if (v ^ pr) {
    go(v, u);
    sub[u] += sub[v];
    weights.emplace_back((ll) sub[v] * (n - sub[v]));
  }
}

int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      g[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d %d", &u, &v);
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
    scanf("%d", &m);
    primes.resize(m), weights.clear();
    for (auto &x : primes) scanf("%lld", &x);
    go();
    sort(weights.begin(), weights.end());
    for (auto &x : weights) x %= MOD;
    if (m <= n - 1) {
      while (primes.size() < n - 1) primes.emplace_back(1);
      sort(primes.begin(), primes.end());
      assert(primes.size() == n - 1 and weights.size() == n - 1);
      ll ans = 0;
      for (int i = 0; i < n - 1; ++i) {
        ll cur = primes[i] * weights[i] % MOD;
        ans += cur;
      }
      ans %= MOD;
      printf("%lld\n", ans);
      continue;
    }
    sort(primes.begin(), primes.end());
    while (primes.size() > n - 1) {
      ll cur = primes.back();
      primes.pop_back();
      primes.back() *= cur, primes.back() %= MOD;
    }
    assert(primes.size() == n - 1 and weights.size() == n - 1);
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      ll cur = primes[i] * weights[i] % MOD;
      ans += cur;
    }
    ans %= MOD;
    printf("%lld\n", ans);
  }
  return 0;
}