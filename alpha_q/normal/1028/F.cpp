#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;
typedef pair <ll, ll> point;

#define x first
#define y second

int q, t, n; ll x, y;
map <point, int> perp;
map <point, int> slope;
map <ll, set <point>> f; 

inline point normalized (ll x, ll y) {
  ll g = __gcd(abs(x), abs(y));
  x /= g, y /= g;
  if (x < 0) x = -x, y = -y;
  return point(x, y);
}

int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d %lld %lld", &t, &x, &y);
    if (t == 1) {
      ll d = x * x + y * y;
      ++slope[normalized(x, y)];
      for (point p : f[d]) {
        ll dy = x - p.x, dx = p.y - y;
        ++perp[normalized(dx, dy)];
      }
      f[d].emplace(x, y), ++n;
    } else if (t == 2) {
      ll d = x * x + y * y;
      --slope[normalized(x, y)];
      f[d].erase(point(x, y)), --n;
      for (point p : f[d]) {
        ll dy = x - p.x, dx = p.y - y;
        --perp[normalized(dx, dy)];
      }
    } else {
      point p = normalized(x, y);
      ll ans = n - 2 * perp[p] - slope[p];
      printf("%lld\n", ans);
    }
  }
  return 0;
}