#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300300;

ll n, a[M];
ll s[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

void kill() {
  s[0] = a[0];
  for (int i = 1; i < n; ++i) {
    s[i] = a[i] + s[i - 1];
  }

  ll ans = 0;
  ll x = 0;
  for (int i = n - 1; i >= 0; --i) {
    assert(s[i] >= x);
    ll y = min((s[i] - x) / 3, a[i] / 2);
    ans += y;

    a[i] -= 2 * y;
    x += y;
    x -= a[i];
    x = max(x, 0ll);
  }

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}