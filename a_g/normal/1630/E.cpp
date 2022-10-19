#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 1e6+5;

int fact[N], invfact[N], inv[N], c2[N];

int inversemod(int p, int q) {
  p %= q;
  if (p < 0) p += q;
  if (p == 1) return 1;
  int b = inversemod(q%p, p);
  int a = (1-1LL*b*q)/p % q;
  if (a < 0) a += q;
  return a;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);

  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1LL*i*fact[i-1] % MOD;
  }
  invfact[N-1] = inversemod(fact[N-1], MOD);
  for (int i = N-1; i >= 1; i--) {
    invfact[i-1] = 1LL*i*invfact[i] % MOD;
  }
  inv[1] = 1;
  for (int i = 2; i < N; i++) {
    inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
    c2[i] = (c2[i-1] + i-1) % MOD;
  }

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> freqs;
    int cur = 0;
    for (int val: a) {
      if (val == cur) {
        freqs.back()++;
      }
      else {
        cur = val;
        freqs.push_back(1);
      }
    }

    int g = 0;
    for (int freq: freqs) {
      g = __gcd(g, freq);
    }
    if (g == n) {
      cout << "1\n";
      continue;
    }

    vector<int> divisors;
    for (int d = 1; d <= g; d++) {
      if (g % d == 0) {
        divisors.push_back(d);
      }
    }
    int k = divisors.size();
    vector<int> dp(k), dp2(k);
    for (int i = k-1; i >= 0; i--) {
      dp[i] = fact[n/divisors[i]];
      for (int freq: freqs) {
        dp[i] = 1LL * dp[i] * invfact[freq/divisors[i]] % MOD;
        dp2[i] = (dp2[i] + c2[freq/divisors[i]]) % MOD;
      }
      for (int v: {dp[i], 2*divisors[i], inv[n/divisors[i]-1]}) {
        dp2[i] = 1LL * v * dp2[i] % MOD;
      }
      for (int j = i+1; j < k; j++) {
        if (divisors[j] % divisors[i] == 0) {
          dp[i] = (dp[i]-dp[j]) % MOD;
          dp2[i] = (dp2[i]-dp2[j]) % MOD;
        }
      }
    }
    for (int i = 0; i < k; i++) {
      dp[i] = 1LL * dp[i] * inv[n/divisors[i]] % MOD;
      dp2[i] = 1LL * dp2[i] * inv[n/divisors[i]] % MOD;
    }
    int perms = accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    int tot_edges = accumulate(dp2.begin(), dp2.end(), 0LL) % MOD;
    int edges = 1LL * tot_edges * inversemod(perms, MOD) % MOD;
    
    cout << (n+MOD-edges)%MOD << '\n';
  }
}