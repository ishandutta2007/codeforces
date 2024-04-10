#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

const int M = 300;
const ll inf = ll(2e16) + ll(1e15);
const int S = M - 1;


int n = 0;
ll x[M], y[M], ax, ay, bx, by, xs, ys, t;

ll mabs(ll x) {
  return x < 0 ? -x : x;
}

ll dist(ll i, ll j) {
  return mabs(x[i] - x[j]) + mabs(y[i] - y[j]);
}

void read() {
  cin >> x[0] >> y[0];
  cin >> ax >> ay;
  cin >> bx >> by;
  cin >> x[S] >> y[S];
  cin >> t;
}

void kill() {
  while (x[n] < inf && y[n] < inf) {
    x[n + 1] = ax * x[n] + bx;
    y[n + 1] = ay * y[n] + by;
    ++n;
  }
  assert(x[n] > 0 && y[n] > 0);

  int ans = 0;
  for (int to = 0; to < n; ++to) {
    ll rem = t - dist(S, to);
    if (rem < 0) continue;

    for (int l = 0; l <= to; ++l)
      for (int r = to; r < n; ++r) {
        ll sum = dist(l, r) + min(dist(to, l), dist(to, r));
        if (sum <= rem)
          ans = max(ans, r - l + 1);
      }
  }

  cout << ans << "\n";
}

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  read();
  kill();
}