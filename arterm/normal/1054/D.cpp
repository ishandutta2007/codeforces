#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

map<int, int> cnt;

ll c2(ll x) {
  return x * (x - 1) / 2;
}

int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int cur = 0;
  cnt[cur]++;

  ll n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if ((x >> (k - 1)) & 1)
      x ^= (1 << k) - 1;
    cur ^= x;
    cnt[cur]++;
  }

  ll ans = c2(n + 1);
  for (auto e : cnt) {
    ll x = e.second;
    ans -= c2(x / 2);
    ans -= c2((x + 1) / 2);
  }

  cout << ans << "\n";
}