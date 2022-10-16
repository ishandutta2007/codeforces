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

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 4e5 + 5;
int n;
int a[maxn], b[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    --a[i];
    --b[i];
  }
  return true;
}

struct node {
  int mn, mx;
};

int ss[maxn];
int ids[maxn];
int del[maxn];
node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v].mn = ss[tl];
    st[v].mx = ss[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
  st[v].mx = max(st[2 * v].mx, st[2 * v + 1].mx);
}

void delPoint(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    st[v].mn = inf;
    st[v].mx = -1;
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    delPoint(2 * v, tl, tm, pos);
  } else {
    delPoint(2 * v + 1, tm, tr, pos);
  }
  st[v].mn = min(st[2 * v].mn, st[2 * v + 1].mn);
  st[v].mx = max(st[2 * v].mx, st[2 * v + 1].mx);
}

int getMin(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].mn;
  }
  int tm = (tl + tr) / 2;
  int res = inf;
  if (l < tm) {
    res = min(res, getMin(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = min(res, getMin(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

int getMax(int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v].mx;
  }
  int tm = (tl + tr) / 2;
  int res = -1;
  if (l < tm) {
    res = max(res, getMax(2 * v, tl, tm, l, min(r, tm)));
  }
  if (r > tm) {
    res = max(res, getMax(2 * v + 1, tm, tr, max(l, tm), r));
  }
  return res;
}

vector<pair<int, int>> q, p;

void delSeg(int id) {
  delPoint(1, 0, 2 * n, a[id]);
  delPoint(1, 0, 2 * n, b[id]);
  del[id] = true;
}

void addEdges(int id, int rot) {
  int x = a[id], y = b[id];
  if (rot) {
    swap(x, y);
  }
  bool rev = true;
  if (x > y) {
    swap(x, y);
    rev = false;
  }
  while (true) {
    int z = getMin(1, 0, 2 * n, x, y);
    if (z >= x) {
      break;
    }
    int i = ids[z];
    delSeg(i);
    int irot = false;
    if (rev) {
      if (a[i] < b[i]) {
        irot = true;
      }
    } else {
      if (a[i] > b[i]) {
        irot = true;
      }
    }
    q.push_back(make_pair(i, irot));
  }
  while (true) {
    int z = getMax(1, 0, 2 * n, x, y);
    if (z <= y) {
      break;
    }
    int i = ids[z];
    delSeg(i);
    int irot = false;
    if (rev) {
      if (a[i] < b[i]) {
        irot = true;
      }
    } else {
      if (a[i] > b[i]) {
        irot = true;
      }
    }
    q.push_back(make_pair(i, irot));
  }
}

void solve() {
  {
    int mx = -1, mn = inf;
    for (int i = 0; i < n; ++i) {
      int x = a[i], y = b[i];
      if (x > y) {
        swap(x, y);
      }
      mx = max(mx, x);
      mn = min(mn, y);
    }
    if (mn < mx) {
      printf("-1\n");
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    ss[a[i]] = b[i];
    ids[a[i]] = i;
    ss[b[i]] = a[i];
    ids[b[i]] = i;
    del[i] = false;
  }
  buildst(1, 0, 2 * n);
  int res = 0;
  for (int s = 0; s < n; ++s) {
    if (del[s]) {
      continue;
    }
    delSeg(s);
    q.clear();
    q.push_back(make_pair(s, 0));
    for (int l = 0; l < sz(q); ++l) {
      addEdges(q[l].first, q[l].second);
    }
    p.clear();
    int cost = 0;
    for (int i = 0; i < sz(q); ++i) {
      int id = q[i].first, rot = q[i].second;
      int x = a[id], y = b[id];
      if (rot) {
        swap(x, y);
        ++cost;
      }
      p.push_back(make_pair(x, y));
    }
    sort(p.begin(), p.end());
    for (int i = 0; i + 1 < sz(p); ++i) {
      if (p[i].second < p[i + 1].second) {
        printf("-1\n");
        return;
      }
    }
    cost = min(cost, sz(p) - cost);
    res += cost;
  }
  printf("%d\n", res);
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