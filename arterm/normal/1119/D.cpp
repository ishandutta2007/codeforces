#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 100100;
const int A = 20;

ll n, a[M];
ll b[M];
ll sb[M];

void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
}

void kill() {
  sort(a, a + n);
  a[n] = ll(2e18) + 100;

  for (int i = 0; i < n; ++i) {
    b[i] = a[i + 1] - a[i];
  }

  sort(b, b + n);

  for (int i = 0; i < n; ++i)
    sb[i + 1] = b[i] + sb[i];

  int q;
  cin >> q;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    ll x = r - l + 1;

    ll at = lower_bound(b, b + n, x) - b;
    ll ans = sb[at] + (n - at) * x;

    cout << ans << " ";
  }
  cout << "\n";
}


int main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}