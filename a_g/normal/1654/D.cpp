#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
int spf[N], inv[N], vp[N], vpmin[N];
vector<tuple<int, int, int>> G[N];

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

vector<int> pfact(int m) {
  vector<int> ans;
  while (m != 1) {
    int p = spf[m];
    while (m % p == 0) {
      ans.push_back(p);
      m /= p;
    }
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  iota(spf, spf+N, 0);
  for (int i = 2; i <= N; i++) {
    if (spf[i] == i) {
      for (int j = 2*i; j < N; j+=i) {
        if (spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
      int u, v, x, y;
      cin >> u >> v >> x >> y;
      G[u].emplace_back(v, x, y);
      G[v].emplace_back(u, y, x);
    }
    int val = 1;
    int ans = 0;
    function<void(int, int)> dfs = [&] (int v, int p) {
      ans = (ans+val) % MOD;
      for (tuple<int, int, int>& e: G[v]) {
        if (get<0>(e) != p) {
          vector<int> primes;
          for (int q: pfact(get<1>(e))) {
            primes.push_back(q);
            vp[q]--;
            val = 1LL * inv[q] * val % MOD;
          }
          for (int q: pfact(get<2>(e))) {
            primes.push_back(q);
            vp[q]++;
            val = 1LL * q * val % MOD;;
          }
          for (int q: primes) {
            vpmin[q] = min(vpmin[q], vp[q]);
          }
          dfs(get<0>(e), v);
          for (int q: pfact(get<1>(e))) {
            primes.push_back(q);
            vp[q]++;
            val = 1LL * q * val % MOD;;
          }
          for (int q: pfact(get<2>(e))) {
            primes.push_back(q);
            vp[q]--;
            val = 1LL * inv[q] * val % MOD;
          }
        }
      }
    };
    dfs(1, 1);

    for (int p = 1; p <= n; p++) {
      if (spf[p] == p) {
        ans = 1LL * expmod(p, -vpmin[p], MOD) * ans % MOD;
      }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      G[i].clear();
    }
    fill(vp, vp+n+1, 0);
    fill(vpmin, vpmin+n+1, 0);
  }
}