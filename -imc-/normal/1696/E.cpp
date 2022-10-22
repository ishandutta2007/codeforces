#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;
vector<li> fac, invfac;

int c(int n, int k) {
  return ((fac[n] * invfac[k]) % MOD * invfac[n - k]) % MOD;
}

int modpow(li x, int p) {
  li ans = 1;
  while (p) {
    if (p % 2 == 1) {
      (ans *= x) %= MOD;
    }
    p /= 2;
    (x *= x) %= MOD;
  }
  return ans;
}

void solve(bool read) {
  int n;
  cin >> n;
  ++n;

  vector<int> a(n);
  for (int& x : a) { cin >> x; }

  li mf = n + *max_element(all(a)) + 3;

  fac.resize(mf);
  invfac.resize(mf);
  for (int i = 0; i < fac.size(); ++i) {
    fac[i] = (i == 0 ? 1 : fac[i - 1] * i) % MOD;
    invfac[i] = modpow(fac[i], MOD - 2);
  }

  li ans = 0;
  for (int i = 0; i < n; ++i) {
    /*if (a[i] > a[i + 1]) {
      cout << "add " << a[i] - 1 + i << " " << i << "\n";
      ans += c(a[i] - 1 + i, i);
    }*/

    if (a[i] > 0) {
      (ans += c(a[i] + i, a[i] - 1)) %= MOD;
    }
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

#if 1
  int nt = 1;
  //cin >> nt;

  for (int i = 0; i < nt; ++i) {
    solve(true);
  }
#endif

  //solve(false);

  return 0;
}