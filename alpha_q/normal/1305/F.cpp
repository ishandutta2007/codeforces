#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 200010;

int n; ll a[N], ans;

void relax (ll x) {
  vector <ll> pr;
  for (ll i = 2; i * i <= x; ++i) {
    if (x % i) continue;
    while (x % i == 0) x /= i;
    pr.emplace_back(i);
  }
  if (x > 1) pr.emplace_back(x);
  for (ll p : pr) {
    ll cur = 0;
    for (int i = 1; i <= n; ++i) {
      if (a[i] < p) cur += p - a[i];
      else cur += min(a[i] % p, p - a[i] % p);
    }
    ans = min(ans, cur);
  }
}

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    ans += (a[i] & 1);
  }
  for (int it = 0; it < 20; ++it) {
    int i = 1 + rng() % n;
    relax(a[i]); relax(a[i] + 1);
    if (a[i] > 1) relax(a[i] - 1);
  }
  cout << ans << '\n';
  return 0;
}