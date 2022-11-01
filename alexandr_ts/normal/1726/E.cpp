#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int INF = 2e9;
const ll MOD = 998244353;
const ld EPS = 1e-9;
const int M = 31;
const int N = 6e5 + 10;

vector<ll> ffac;
vector<ll> fac;
vector<ll> bfac;

ll pw2(ll x, ll a) {
  if (a == 0) return 1;
  if (a % 2) return pw2(x, a - 1) * x % MOD;
  ll tmp = pw2(x, a / 2);
  return tmp * tmp % MOD;
}

void prec() {
  ffac.resize(N);
  ffac[0] = 1;
  for (ll i = 2; i < N; i += 2) {
    ffac[i] = ffac[i - 2] * (i - 1) % MOD;
  }

  fac.resize(N);
  bfac.resize(N);
  fac[0] = bfac[0] = 1;
  for (ll i = 1; i < N; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }
  bfac[N - 1] = pw2(fac[N - 1], MOD - 2);
  for (ll i = N - 2; i >= 1; --i) {
    bfac[i] = bfac[i + 1] * (i + 1) % MOD;
  }
  assert(bfac[1] = 1);
}

ll cnk(ll n, ll k) {
  if (k < 0 || k > n) return 0;
  return fac[n] * bfac[k] % MOD * bfac[n - k] % MOD;
}

vector<ll> precalced;

void glob_prec() {
  precalced.resize(N);
  precalced[0] = 1;
  precalced[1] = 1;
  precalced[2] = 2;
  precalced[3] = 4;
  for (ll i = 4; i < N; ++i) {
    precalced[i] = (precalced[i - 1] + (i - 1) * precalced[i - 2]) % MOD;
  }
}

class Solver {
public:

  void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (ll pairs = 0; pairs * 2 <= n; ++pairs) {
      ll add = cnk(n - pairs, pairs) * ffac[pairs] % MOD * pw2(2, pairs / 2) % MOD * precalced[n - pairs * 2] % MOD;
      ans = (ans + add) % MOD;
    }
    cout << ans << "\n";
  }

  void solveTL() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = i;
    int ans = 0;
    do {
      vector<int> p(n);
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        p[a[i]] = i;
        if (abs(p[a[i]] - a[a[i]]) > 1) {
          ok = false;
          break;
        }
      }
      if (ok) {
        //for (int i = 0; i < n; ++i) cout << a[i] + 1 << " ";cout << endl;
        ans++;
      }
    }
    while (next_permutation(a.begin(), a.end()));
    cout << n << ": " << ans << endl;

  }

private:

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  cin >> t;
  prec();
  glob_prec();
  assert(cnk(6, 2) == 15);
  assert(cnk(6, 3) == 20);
  while (t--) {
    Solver{}.solve();
  }
}