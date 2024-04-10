#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 200200;
const ll infl = 1e18;

ll n, k, s, t;
ll c[M], v[M];
ll g[M];

void read() {
  cin >> n >> k >> s >> t;
  for (int i = 0; i < n; ++i)
    cin >> c[i] >> v[i];
  for (int i = 0; i < k; ++i) {
    cin >> g[i];
  }
  g[k++] = 0;
  g[k++] = s;
  sort(g, g + k);
}

ll time(ll v) {
  ll ans = 0;
  for (int i = 0; i + 1 < k; ++i) {
    ll d = g[i + 1] - g[i];
    if (v < d)
      return infl;
    if (v >= 2 * d)
      ans += d;
    else
      ans += 3 * d - v;
  }
  return ans;
}

void kill() {
  ll l = 0, r = 2e9;
  while (l < r) {
    ll m = (l + r) / 2;
    if (time(m) > t)
      l = m + 1;
    else
      r = m;
  }

  ll best = infl;
  for (int i = 0; i < n; ++i)
    if (v[i] >= l)
      if (c[i] < best)
        best = c[i];

  if (best >= 2e9)
    cout << "-1\n";
  else
    cout << best << "\n";
}

int main() {
  cout.precision(20);
  cout << fixed;
  ios_base::sync_with_stdio(false);
  read();
  kill();
}