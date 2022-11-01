#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 2e5 + 10;

ll pw(ll x, ll a) {
  if (!a) return 1;
  if (a % 2) return pw(x, a - 1) * x % MOD;
  ll tmp = pw(x, a / 2);
  return tmp * tmp % MOD;
}

ll t[N]; /// fenwick tree

void add(int i, ll val, int n) {
    while (i < n) {
        t[i] += val;
        i = (i | (i + 1));
    }
}

ll sum(int i) {
    ll ans = 0;
    while (i >= 0) {
        ans += t[i];
        i = (i & (i + 1)) - 1;
    }
    return ans;
}


class Solver {
public:

  ll solve(int n, int m, vector<int> a, vector<int> b) {
    prec();

    cnt.resize(N + 1);
    for (auto e : a) {
      add(e, 1, N);
      cnt[e]++;
    }

    ll ans = 0;
    ll denom = 1;
    for (int i = 0; i < N; ++i) {
      denom = denom * fac[cnt[i]] % MOD;
    }
    for (int i = 0; i < min(n, m); ++i) {
      int last_ok = b[i] - 1;
      if (n < m && i == n - 1) {
        last_ok = b[i];
      }
      ll ad = (fac[n - i - 1] * sum(last_ok) % MOD * pw(denom, MOD - 2) % MOD) % MOD;
      // cout << fac[n - i - 1] << " " << sum(last_ok) << " " << denom << " " << ad << endl;
      ans = (ad + ans) % MOD;
      if (cnt[b[i]] == 0) {
        break;
      }
      denom = (denom * bfac[cnt[b[i]]]) % MOD;
      cnt[b[i]]--;
      denom = (denom * fac[cnt[b[i]]]) % MOD;
      add(b[i], -1, N);
    }
    return ans;

  }

private:
  vector<ll> fac, bfac;
  vector<int> cnt;

  /*
  ll f(vector<int> cnt) {
    int sum = accumulate(cnt.begin(), cnt.end(), 0);
    ll ans = fac[sum];
    for (auto e : cnt) {
      ans = ans * bfac[e] % MOD;
    }
    return ans;
  }
  */

  void prec() {
    fac.resize(N);
    bfac.resize(N);
    fac[0] = bfac[0] = 1;
    assert(pw(2, 3) == 8);
    for (ll i = 1; i < N; ++i) {
      fac[i] = fac[i - 1] * i % MOD;
      bfac[i] = pw(fac[i], MOD - 2);
    }
    assert(fac[4] == 24);
    assert(fac[4] * bfac[4] % MOD == 1);
  }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& e : a) cin >> e;
    for (auto& e : b) cin >> e;
    cout << Solver{}.solve(n, m, a, b) << endl;
  }
}