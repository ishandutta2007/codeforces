#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

#define x first
#define y second

const int N = 200005;
const int MOD = 998244353;

set <pii> s[N];
int n, q, t[4 * N], add[4 * N], mul[4 * N];

inline void inc (int &x) {
  ++x;
  if (x >= MOD) x -= MOD;
}

inline void two (int &x) {
  x <<= 1;
  if (x >= MOD) x -= MOD;
}

inline void mult (int &x, int y) {
  x = x * 1LL * y % MOD;
}

inline void sum (int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

void propagate (int u, int b, int e) {
  t[u] = (mul[u] * 1LL * t[u] + add[u] * 1LL * (e - b + 1)) % MOD;
  if (b != e) {
    mult(mul[u << 1], mul[u]);
    mult(add[u << 1], mul[u]);
    sum(add[u << 1], add[u]);
    mult(mul[u << 1 | 1], mul[u]);
    mult(add[u << 1 | 1], mul[u]);
    sum(add[u << 1 | 1], add[u]);
  }
  mul[u] = 1, add[u] = 0;
}

void update (int u, int b, int e, int l, int r, int x) {
  if (mul[u] != 1 or add[u] != 0) propagate(u, b, e);
  if (b > r or e < l) return;
  if (b >= l and e <= r) {
    if (x) inc(add[u]);
    else two(mul[u]), two(add[u]);
    propagate(u, b, e);
    return;
  }
  int m = b + e >> 1;
  update(u << 1, b, m, l, r, x);
  update(u << 1 | 1, m + 1, e, l, r, x);
  t[u] = t[u << 1] + t[u << 1 | 1];
  if (t[u] >= MOD) t[u] -= MOD;
}

int query (int u, int b, int e, int l, int r) {
  if (b > r or e < l) return 0;
  if (mul[u] != 1 or add[u] != 0) propagate(u, b, e);
  if (b >= l and e <= r) return t[u];
  int m = b + e >> 1;
  int ret = query(u << 1, b, m, l, r) + query(u << 1 | 1, m + 1, e, l, r);
  if (ret >= MOD) ret -= MOD;
  return ret;
}

int main() {
  for (int i = 0; i < 4 * N; ++i) mul[i] = 1;
  scanf("%d %d", &n, &q);
  while (q--) {
    int cmd, l, r, x;
    scanf("%d %d %d", &cmd, &l, &r);
    if (cmd == 1) {
      scanf("%d", &x);
      pii p = pii(l, r);
      if (s[x].empty()) {
        s[x].insert(p);
        update(1, 1, n, p.x, p.y, 1);
        continue;
      } 
      auto it = s[x].lower_bound(p);
      if (it != s[x].begin()) {
        --it;
      }
      vector <pii> side, bad;
      while (it != s[x].end()) {
        pii cur = *it;
        ++it;
        if (cur.y == p.x - 1) {
          l = min(l, cur.x);
          side.push_back(cur);
          continue;
        }
        if (cur.x == p.y + 1) {
          r = max(r, cur.y);
          side.push_back(cur);
          continue;
        }
        if (cur.y < p.x) continue;
        if (cur.x > p.y) break;
        bad.push_back(cur);
        l = min(l, cur.x), r = max(r, cur.y);
      }
      for (pii z : side) s[x].erase(z);
      int lt = p.x;
      for (pii z : bad) {
        s[x].erase(z);
        z.x = max(p.x, z.x);
        z.y = min(p.y, z.y);
        if (lt < z.x) {
          update(1, 1, n, lt, z.x - 1, 1);
        }
        update(1, 1, n, z.x, z.y, 0);
        lt = z.y + 1;
      }
      if (lt <= p.y) update(1, 1, n, lt, p.y, 1);
      s[x].insert(pii(l, r));
    } else {
      printf("%d\n", query(1, 1, n, l, r));
    }
  }
  return 0;
}