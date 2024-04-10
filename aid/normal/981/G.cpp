#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = 998244353;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 2e5 + 5;
int n, q;

int read() {
  if (scanf("%d%d", &n, &q) < 2) {
    return false;
  }
  return true;
}

struct node {
  int val;
  int cnt;
  int a, b;

  void update(int na, int nb) {
    val = mul(val, na);
    add(val, mul(nb, cnt));
    a = mul(a, na);
    b = mul(b, na);
    add(b, nb);
  }
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].cnt = tr - tl;
  st[v].a = 1;
  st[v].b = 0;
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (st[v].a == 1 && st[v].b == 0) {
    return;
  }
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    st[u].update(st[v].a, st[v].b);
  }
  st[v].a = 1;
  st[v].b = 0;
}

void update(int v, int tl, int tr, int l, int r, int a, int b) {
  if (l == tl && r == tr) {
    st[v].update(a, b);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), a, b);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, a, b);
  }
  st[v].val = st[2 * v].val;
  add(st[v].val, st[2 * v + 1].val);
}

int get(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].val;
  }
  push(v);
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    add(res, get(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    add(res, get(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

set<pair<int, int>> segs[maxn];

void solve() {
  buildst(1, 0, n);
  for (int i = 0; i < n; i++) {
    segs[i].clear();
  }
  for (int qq = 0; qq < q; qq++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      l--;
      auto &st = segs[x];
      auto it = st.lower_bound(make_pair(l, -1));
      int nl = l, nr = r;
      if (it != st.begin()) {
        it--;
        if (it->second > l) {
          if (it->second >= r) {
            update(1, 0, n, l, r, 2, 0);
            continue;
          }
          update(1, 0, n, l, it->second, 2, 0);
          l = it->second;
        }
        if (it->second == l) {
          nl = it->first;
          auto todel = it;
          it++;
          st.erase(todel);
        } else {
          it++;
        }
      }
      while (it != st.end() && it->first <= r) {
        if (l < it->first) {
          update(1, 0, n, l, it->first, 1, 1);
          l = it->first;
        }
        {
          int curl = l, curr = min(it->second, r);
          if (curl < curr) {
            update(1, 0, n, curl, curr, 2, 0);
          }
          l = curr;
        }
        if (r <= it->second) {
          nr = it->second;
        }
        auto todel = it;
        it++;
        st.erase(todel);
      }
      if (l < r) {
        update(1, 0, n, l, r, 1, 1);
      }
      st.insert(make_pair(nl, nr));
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      l--;
      printf("%d\n", get(1, 0, n, l, r));
    }
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}