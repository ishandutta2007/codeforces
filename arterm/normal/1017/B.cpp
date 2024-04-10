#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;


int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int n;
  string s, t;
  cin >> n;
  cin >> s >> t;

  map<int, ll> cnt;

  auto enc = [=](int x, int y) {
    return 2 * y + x;
  };

  for (int i = 0; i < n; ++i) {
    int x = s[i] - '0';
    int y = t[i] - '0';
    cnt[enc(x, y)]++;
  }

  ll ans = cnt[enc(0, 0)] * (cnt[enc(1, 0)] + cnt[enc(1, 1)]) +
    cnt[enc(0, 1)] * cnt[enc(1, 0)];

  cout << ans << "\n";
}