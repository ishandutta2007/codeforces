#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000010;
const int MOD = 1e9 + 7;

ll bigMod (ll a, ll e) {
  ll ret = 1;
  while (e) {
    if (e & 1) ret = ret * a % MOD;
    a = a * a % MOD, e >>= 1;
  }
  return ret;
}

int t; ll n, p, a[N];

int main() {
  cin >> t;
  while (t--) {
    scanf("%lld %lld", &n, &p);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    if (p == 1) {
      printf("%lld\n", n % 2);
      continue;
    }
    sort(a + 1, a + n + 1, greater <ll> ());
    map <ll, ll> lt, rt;
    for (int i = 1; i <= n; ++i) {
      ll cur = a[i];
      if (lt.empty() and rt.empty()) {
        lt[cur] = 1;
        continue;
      }
      ++rt[cur];
      ll at = cur;
      while (rt[at] == p) {
        rt.erase(at); ++at; ++rt[at];
      }
      if (lt.find(at) != lt.end()) {
        lt[at] -= rt[at];
        if (!lt[at]) lt.erase(at);
        rt.erase(at);
      }
    }
    ll ans = 0;
    for (auto it : lt) {
      ll cur = it.second * bigMod(p, it.first) % MOD;
      ans += cur; if (ans >= MOD) ans -= MOD;
    }
    for (auto it : rt) {
      ll cur = it.second * bigMod(p, it.first) % MOD;
      ans -= cur; if (ans < 0) ans += MOD;
    }
    printf("%lld\n", ans);
  }
  return 0;
}

// 69p^10

// p^10 - (p-1)


// p^5 - p^4