#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

const int N = 200010;
const int MOD = 1e9 + 7;

int n;
vector <ll> x;
ll f[N];

void print (vector <ll> z) {
  for (int i = 0; i < int(z.size()); ++i) {
    cout << z[i] << " ";
  } cout << endl;
}

ll bigMod (ll a, ll e) {
  if (e == -1) e = MOD - 2;
  ll ret = 1LL;
  while (e) {
    if (e & 1) ret = (ret * a) % MOD;
    a = (a * a) % MOD;
    e >>= 1LL;
  }
  return ret;
}

ll nCr (int m, int k) {
  if (m < k) return 0;
  ll ret = f[m];
  ret = (ret * bigMod(f[k], -1)) % MOD;
  ret = (ret * bigMod(f[m - k], -1)) % MOD;
  return ret;
}

ll brute (int sz, int sgn, vector <ll> v) {
  if (sz == 1) return v[0];
  vector <ll> w;
  for (int i = 0; i < sz - 1; ++i) {
    if (sgn) {
      if (i & 1) w.push_back(v[i] - v[i + 1]);
      else w.push_back(v[i] + v[i + 1]);
    } else {
      if (i & 1) w.push_back(v[i] + v[i + 1]);
      else w.push_back(v[i] - v[i + 1]);
    }
  }
  if (sz & 1) {
    return brute(sz - 1, sgn, w);
  } else {
    return brute(sz - 1, sgn ^ 1, w);
  }
}

ll coeff[N];

int main() {
  f[0] = 1LL;
  for (int i = 1; i < N; ++i) {
    f[i] = i * 1LL * f[i - 1] % MOD;
  }
  scanf("%d", &n);
  x.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x[i]);
  }   
  // cout << brute(n, 1, x) << endl;
  if (n % 4 == 3) {
    vector <ll> y;
    for (int i = 0; i < n - 1; ++i) {
      if (i & 1) y.push_back(x[i] - x[i + 1]);
      else y.push_back(x[i] + x[i + 1]);
    }
    x = y, --n;
  }
  if (n % 4 == 1) {
    int m = (n - 1) / 2;
    for (int i = 1, j = n, k = 0; i <= j; i += 2, j -= 2, ++k) {
      coeff[i] = coeff[j] = nCr(m, k);
    }
  } 
  if (n % 4 == 2) {
    int m = (n - 1) / 2;
    for (int i = 1, j = n, k = 0; i <= j; i += 2, j -= 2, ++k) {
      coeff[i] = coeff[i + 1] = coeff[j] = coeff[j - 1] = nCr(m, k);
    }
  }
  if (n % 4 == 0) {
    int m = (n - 1) / 2;
    for (int i = 1, j = n, k = 0; i <= j; i += 2, j -= 2, ++k) {
      coeff[i] = coeff[j - 1] = nCr(m, k);
      coeff[i + 1] = coeff[j] = -coeff[i];
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (coeff[i + 1] * x[i]) % MOD;
    ans %= MOD;
  }
  ans += MOD, ans %= MOD;
  printf("%lld\n", ans);
  return 0;
}