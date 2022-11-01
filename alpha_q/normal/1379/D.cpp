#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100010;

int n; ll h, m, k, hr[N], mn[N], pt[N];

int main() {
  cin >> n >> h >> m >> k;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld", hr + i, mn + i);
    pt[i] = hr[i] * m + mn[i];
    // cerr << pt[i] << " ";
  }
  // cerr << '\n';
  if (k == 1) {
    cout << "0 0\n\n";
    return 0;
  }
  ll period = m >> 1, tot = h * m, tram = tot / period;
  // cerr << period << " " << tot << " " << tram << '\n';
  vector <pair <ll, ll>> vec;
  map <ll, int> f;
  ll run = 0, ans = n + 1, tym = 0;
  for (int i = 1; i <= n; ++i) {
    ll cur = pt[i] % period, l = cur - k + 1, r = cur - 1;
    while (l < 0) l += period, r += period;
    l %= period, r %= period;
    vec.emplace_back(l, r);
    if (l > r or r == period - 1) ++run;
    ++f[l], --f[(r + 1) % period];
  } f[0], f[period - 1];
  // for (auto it : vec) cerr << it.first << " " << it.second << '\n';
  // cerr << run << '\n';
  for (auto it : f) {
    run += it.second;
    if (run < ans) {
      ans = run, tym = it.first;
    }
  }
  cout << ans << " " << (tym + k) % period << '\n';
  for (int i = 1; i <= n; ++i) {
    ll cur = pt[i] % period, l = cur - k + 1, r = cur - 1;
    while (l < 0) l += period, r += period;
    ll at = tym;
    while (at < l) at += period;
    if (at <= r) printf("%d ", i);
  }
  cout << '\n';
  return 0;
}