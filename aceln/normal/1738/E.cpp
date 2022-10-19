#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

#define all(v) (v).begin(), (v).end()

ll p[100007], invp[100007];

ll ppow(ll x, ll y = MOD - 2) {
  ll ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  p[0] = invp[0] = 1;
  for (int i = 1; i <= 100005; i++) {
    p[i] = p[i - 1] * i % MOD;
    invp[i] = ppow(p[i]);
  }

  auto C = [&](int n, int m) {
    if (n < 0 || m < 0 || n - m < 0)
      return 0LL;
    return p[n] * invp[m] % MOD * invp[n - m] % MOD;
  };

  while (t--) {
    int n;
    cin >> n;
    vector<long long> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
      cin >> a[i], pre[i] = pre[i - 1] + a[i];

    ll las = -1, sum = pre[n];
    ll ans = 0, pre_ways = 1;
    int cnt_mid;
    if (sum & 1)
      cnt_mid = 0;
    else
      cnt_mid = upper_bound(all(pre), sum / 2) - lower_bound(all(pre), sum / 2);

    for (int i = 0; i <= n; i++) {
      if (pre[i] == las)
        continue;
      if (pre[i] > sum - pre[i])
        break;
      las = pre[i];
      if (pre[i] == sum - pre[i]) { //
        ll ways_now = 0;
        if (sum == 0)
          cnt_mid -= 2;
        for (int j = 1; j <= cnt_mid; j++)
          ways_now = (ways_now + C(cnt_mid, j)) % MOD;
        ans = (ans + pre_ways * ways_now) % MOD;
      } else {
        int cntl =
            upper_bound(all(pre), pre[i]) - lower_bound(all(pre), pre[i]);
        int cntr = upper_bound(all(pre), sum - pre[i]) -
                   lower_bound(all(pre), sum - pre[i]);
        if (pre[i] == 0) {
          cntl--;
          cntr--;
        }
        ll ways_now = 0;
        for (int j = 0; j <= min(cntl, cntr); j++)
          ways_now = (ways_now + C(cntl, j) * C(cntr, j)) % MOD;

        ans = (ans + pre_ways * (ways_now + MOD - 1) % MOD) % MOD;
        pre_ways = pre_ways * ways_now % MOD;
      }
    }
    cout << (ans + 1) % MOD << '\n'; // +1?
  }
}