#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

#define x first
#define y second

const ld IS_QUERY = -(1LL << 62);

struct line {
  ld m, b;
  mutable function <const line*()> succ;

  bool operator < (const line &rhs) const {
    if (rhs.b != IS_QUERY) return m < rhs.m;
    const line *s = succ();
    if (!s) return 0;
    ld x = rhs.m;
    return b - s -> b < (s -> m - m) * x;
  }
};

struct HullDynamic : public multiset <line> { 
  bool bad (iterator y) {
    auto z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y -> m == z -> m && y -> b <= z -> b;
    }
    auto x = prev(y);
    if (z == end()) return y -> m == x -> m && y -> b <= x -> b;
    return (y -> b - z -> b) * (y -> m - x -> m) <= (x -> b - y -> b) * (z -> m - y -> m);
  }

  void insert_line (ld m, ld b) {
    auto y = insert({m, b});
    y -> succ = [=] {return next(y) == end() ? 0 : &*next(y);};
    if (bad(y)) {erase(y); return;}
    while (next(y) != end() && bad(next(y))) erase(next(y));
    while (y != begin() && bad(prev(y))) erase(prev(y));
  }

  ld eval (ld x) {
    auto l = *lower_bound((line) {x, IS_QUERY});
    return l.m * x + l.b;
  }
};

const int N = 2010;
const ld INF = 1e20;
const int M = 4000010;

int n, m, k;
HullDynamic lt, rt;
ll l[N], r[N], y[N];
pair <ld, ld> range[M], normal[M];

inline void fuck (int i, int j) {
  if (y[i] < y[j]) swap(i, j);
  ll one = l[j] - r[i], two = r[j] - l[i], down = y[i] - y[j];
  range[++m] = make_pair((ld) one / down, (ld) two / down);
}

inline ld get (ld x) {
  return lt.eval(x) + rt.eval(x);
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld %lld %lld", l + i, r + i, y + i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (y[i] ^ y[j]) fuck(i, j);
    }
  }
  if (!m) {
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 1; i <= n; ++i) {
      mn = min(mn, l[i]), mx = max(mx, r[i]);
    }
    cout << mx - mn << '\n';
    return 0;
  }
  sort(range + 1, range + m + 1);
  for (int i = 1, j = 1; i <= m; i = j) { 
    pair <ld, ld> cur = range[i];
    while (j <= m and range[j].x < cur.y) cur.y = max(cur.y, range[j++].y);
    normal[++k] = cur;
  }
  for (int i = 1; i <= n; ++i) {
    lt.insert_line(-y[i], -l[i]);
    rt.insert_line(y[i], r[i]);
  }
  ld ans = INF;
  for (int i = 1; i <= k; ++i) {
    ans = min(ans, get(normal[i].x));
    ans = min(ans, get(normal[i].y));
  }
  printf("%0.16f\n", (double) ans);
  return 0;
}