#include <bits/stdc++.h>
using namespace std;

using ll = long long;

tuple<ll, ll, ll> extgcd(ll a, ll b) {
  ll s = 1, t = 0, u = 0, v = 1;
  while (b) {
    ll q = a / b;
    swap(a -= q * b, b);
    swap(s -= q * t, t);
    swap(u -= q * v, v);
  }
  return {s, u, a};
}

constexpr int B = 500;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<ll> a(n + 1), v;
  for (int i = 1; i <= n; i++) {
    ll aa, bb;
    cin >> aa >> bb;
    a[0] += aa;
    v.push_back(bb - aa);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] + v[i - 1];
  }
  reverse(a.begin(), a.end());

  vector<vector<ll>> ans(B + 1, vector<ll>(B + 1));
  for (int i = 1; i <= B; i++) {
    for (int j = 0; j <= n; j++) {
      ans[i][j % i] = max(ans[i][j % i], a[j]);
    }
  }

  int m;
  cin >> m;
  while (m--) {
    ll x, y;
    cin >> x >> y;
    ll l = lcm(x, y);

    auto [p, q, g] = extgcd(x, y);
    if (n % g != 0) {
      cout << -1 << '\n';
      continue;
    }
    p *= (n / g), q *= (n / g);

    if (p < 0) {
      ll am = ((-p) + (l / x) - 1) / (l / x);
      p += (am * (l / x)), q -= (am * (l / y));
    } else if (p >= (l / x)) {
      ll am = p / (l / x);
      p -= (am * (l / x)), q += (am * (l / y));
    }

    if (q < 0) {
      cout << -1 << '\n';
      continue;
    }

    if (p < 0 || q < 0) {
      cout << "WA\n";
      break;
    }

    // assert(p >= 0 && q >= 0);
    if (l <= B) {
      if (p * x >= l) {
        cout << "WA\n";
        break;
      }
      cout << ans[l][p * x] << '\n';
    } else {
      ll ret = 0;
      for (ll i = p * x; i <= n; i += l)
        ret = max(ret, a[i]);
      cout << ret << '\n';
    }
  }
}