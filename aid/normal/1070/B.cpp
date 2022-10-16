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

const int maxn = (int) 2e5 + 5;
int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

struct node {
  int val;
  int all;
  node *l, *r;

  node(): val(0), all(0), l(0), r(0) {}
};

bool update(node *v, unsigned int cur, unsigned int curd, unsigned int x, unsigned int d, int t) {
  bool bad = (v->all & (1 << (t ^ 1)));
  v->val |= (1 << t);
  if (cur == x && curd == d) {
    v->all |= (1 << t);
    return !bad && !(v->val & (1 << (t ^ 1)));
  }
  assert(curd);
  curd--;
  if (!(x & (1u << curd))) {
    if (!v->l) {
      v->l = new node();
    }
    return !bad && update(v->l, cur, curd, x, d, t);
  } else {
    if (!v->r) {
      v->r = new node();
    }
    return !bad && update(v->r, (cur | (1u << curd)), curd, x, d, t);
  }
}

vector<pair<unsigned int, unsigned int>> ans;

void get(node *v, unsigned int cur, unsigned int curd) {
  if (!(v->val & 1)) {
    return;
  }
  if (!(v->val & 2)) {
    ans.push_back(make_pair(cur, curd));
    return;
  }
  assert(curd);
  curd--;
  if (v->l) {
    get(v->l, cur, curd);
  }
  if (v->r) {
    get(v->r, (cur | (1u << curd)), curd);
  }
}

void solve() {
  node *root = new node();
  bool bad = false;
  for (int i = 0; i < n; i++) {
    scanf(" ");
    unsigned int x = 0;
    int t = -1;
    for (int j = 0; j < 4; j++) {
      char c;
      unsigned int cur;
      scanf("%c%u", &c, &cur);
      if (!j) {
        t = (c == '+');
      }
      x = (x << 8u) + cur;
    }
    char c;
    scanf("%c", &c);
    unsigned int dep = 0;
    if (c == '/') {
      scanf("%u", &dep);
      dep = 32u - dep;
    }
    if (!update(root, 0u, 32u, x, dep, t)) {
      bad = true;
    }
  }
  if (bad) {
    printf("-1\n");
    return;
  }
  ans.clear();
  get(root, 0u, 32u);
  printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++) {
    unsigned int x = ans[i].first;
    unsigned int dep = ans[i].second;
    dep = 32u - dep;
    vector<unsigned int> a;
    for (int j = 0; j < 4; j++) {
      a.push_back(x & 255u);
      x >>= 8u;
    }
    reverse(a.begin(), a.end());
    for (int j = 0; j < 4; j++) {
      printf("%u", a[j]);
      if (j + 1 < 4) {
        printf(".");
      }
    }
    printf("/%u\n", dep);
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