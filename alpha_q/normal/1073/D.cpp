#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 400010;

int n;
ll t, a[N], f[N], act[N], tot;

void upd (int p, ll v, int yo) {
  while (p < N) act[p] += yo, f[p] += v, p += p & -p;
}

pair <ll, int> pref (int p) {
  pair <ll, int> ret = {0, 0};
  while (p > 0) ret.first += f[p], ret.second += act[p], p -= p & -p;
  return ret;
}

inline pair <ll, int> get (int l, int r) {
  if (l > r) return {0, 0};
  pair <ll, int> one = pref(r), two = pref(l - 1);
  return {one.first - two.first, one.second - two.second};
}

int main() {
  scanf("%d %lld", &n, &t);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    a[n + i] = a[i];
    tot += a[i];
    upd(i, a[i], 1);
    upd(n + i, a[i], 1);
  }
  ll ans = 0;
  int at = 1, alive = n;
  while (alive) {
    ans += alive * (t / tot);
    t %= tot;
    int lo = at, hi = at + n - 1;
    while (lo < hi) {
      int mid = lo + hi >> 1;
      if (get(at, mid).first > t) hi = mid;
      else lo = mid + 1;
    }
    pair <ll, int> cur = get(at, lo - 1);
    ans += cur.second;
    t -= cur.first;
    at = lo;
    if (at > n) at -= n;
    upd(at, -a[at], -1);
    upd(n + at, -a[at], -1);
    --alive, tot -= a[at];
    a[at] = a[n + at] = 0;
  }
  printf("%lld\n", ans);
  return 0;
}