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

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn], b[maxn];
vector<int> g[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n - 1; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  return true;
}

struct line {
  long long a, b;
  mutable function<const line *()> nxt;

  line(long long _a, long long _b): a(_a), b(_b) {}

  long long eval(long long x) const {
    return a * x + b;
  }

  bool operator < (const line &l) const {
    if (l.a >= infll) {
      const line *f = nxt();
      if (!f) {
        return false;
      }
      return eval(l.b) > f->eval(l.b);
    }
    return a > l.a;
  }
};

bool cmp(long long a, long long b, long long c, long long d) {
  //a * b >= c * d
  ld dif = (ld) a * b - (ld) c * d;
  if (abs(dif) > infll) {
    return dif > 0;
  }
  long long dif1 = a * b - c * d;
  return dif1 >= 0;
}

struct T : public multiset<line> {
  bool bad(iterator it) {
    auto nxt = next(it);
    if (nxt != end() && it->a == nxt->a && it->b >= nxt->b) {
      return true;
    }
    if (it == begin()) {
      return false;
    }
    auto prv = prev(it);
    if (it->a == prv->a && it->b >= prv->b) {
      return true;
    }
    if (nxt == end()) {
      return false;
    }
    if (it->a == nxt->a || it->a == prv->a) {
      return false;
    }
    return cmp(prv->b - it->b, nxt->a - it->a, it->b - nxt->b, it->a - prv->a);
  }

  void add(const line &l) {
    auto it = insert(l);
    it->nxt = [=] { return next(it) == end() ? 0 : &*next(it); };
    if (bad(it)) {
      erase(it);
      return;
    }
    while (next(it) != end() && bad(next(it))) {
      erase(next(it));
    }
    while (it != begin() && bad(prev(it))) {
      erase(prev(it));
    }
  }

  long long get(long long x) {
    auto it = lower_bound(line(infll, x));
    return it->eval(x);
  }
};

long long dp[maxn];
int ts[maxn];
T *st[maxn];

void dfs(int v, int p) {
  ts[v] = 1;
  int maxu = -1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p) {
      continue;
    }
    dfs(u, v);
    ts[v] += ts[u];
    if (maxu == -1 || (ts[u] > ts[maxu])) {
      maxu = u;
    }
  }
  if (maxu == -1) {
    dp[v] = 0;
    st[v] = new T;
    st[v]->add(line(b[v], dp[v]));
    return;
  }
  dp[v] = infll;
  st[v] = st[maxu];
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i];
    if (u == p || u == maxu) {
      continue;
    }
    for (auto it = st[u]->begin(); it != st[u]->end(); it++) {
      st[v]->add(*it);
    }
  }
  dp[v] = st[v]->get(a[v]);
  st[v]->add(line(b[v], dp[v]));
}

void solve() {
  dfs(0, -1);
  for (int i = 0; i < n; i++) {
    printf("%lld ", dp[i]);
  }
  printf("\n");
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