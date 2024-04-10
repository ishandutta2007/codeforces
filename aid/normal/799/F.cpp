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
int m, n;
int ls[maxn], rs[maxn];

int read() {
  if (scanf("%d%d", &m, &n) < 2) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &ls[i], &rs[i]);
    ls[i]--;
  }
  return true;
}

struct node {
  int mn[2][2], toadd[2][2];
  int cnt[2][2];
  long long sum[2][2];

  node() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        mn[i][j] = 0;
        toadd[i][j] = 0;
        cnt[i][j] = 0;
        sum[i][j] = 0;
      }
    }
  }

  node(const node &l, const node &r) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        toadd[i][j] = 0;
        if (l.mn[i][j] < r.mn[i][j]) {
          mn[i][j] = l.mn[i][j];
          cnt[i][j] = l.cnt[i][j];
          sum[i][j] = l.sum[i][j];
        } else if (r.mn[i][j] < l.mn[i][j]) {
          mn[i][j] = r.mn[i][j];
          cnt[i][j] = r.cnt[i][j];
          sum[i][j] = r.sum[i][j];
        } else {
          mn[i][j] = l.mn[i][j];
          cnt[i][j] = l.cnt[i][j] + r.cnt[i][j];
          sum[i][j] = l.sum[i][j] + r.sum[i][j];
        }
      }
    }
  }

  void add(int a[2][2]) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        toadd[i][j] += a[i][j];
        mn[i][j] += a[i][j];
      }
    }
  }
};

node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = node();
  if (tl == tr - 1) {
    for (int i = 0; i < 2; i++) {
      st[v].cnt[i][tl & 1]++;
      st[v].sum[i][tl & 1] += tl;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  st[v] = node(st[2 * v], st[2 * v + 1]);
}

void push(int v) {
  for (int it = 0; it < 2; it++) {
    int u = 2 * v + it;
    st[u].add(st[v].toadd);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      st[v].toadd[i][j] = 0;
    }
  }
}

void add(int v, int tl, int tr, int l, int r, int toadd[2][2]) {
  if (l == tl && r == tr) {
    st[v].add(toadd);
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v] = node(st[2 * v], st[2 * v + 1]);
}

void del(int v, int tl, int tr, int pos) {
  if (tl == tr - 1) {
    for (int i = 0; i < 2; i++) {
      st[v].cnt[i][tl & 1]--;
      st[v].sum[i][tl & 1] -= tl;
    }
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    del(2 * v, tl, tm, pos);
  } else {
    del(2 * v + 1, tm, tr, pos);
  }
  st[v] = node(st[2 * v], st[2 * v + 1]);
}

vector<int> evs[maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    evs[i].clear();
  }
  buildst(1, 0, n);
  for (int i = 0; i < m; i++) {
    evs[ls[i]].push_back(i);
    evs[rs[i]].push_back(i);
    int toadd[2][2];
    for (int it = 0; it < 2; it++) {
      toadd[it][ls[i] & 1] = 0;
      toadd[it][(ls[i] & 1) ^ 1] = 1;
    }
    add(1, 0, n, ls[i], rs[i], toadd);
    if (rs[i] < n && !((rs[i] - ls[i]) & 1)) {
      toadd[0][0] = 1;
      toadd[0][1] = 1;
      toadd[1][0] = 1;
      toadd[1][1] = 1;
      add(1, 0, n, rs[i], n, toadd);
    }
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < sz(evs[i]); j++) {
      int id = evs[i][j];
      if (i == ls[id]) {
        int toadd[2][2];
        for (int it = 0; it < 2; it++) {
          toadd[it][ls[id] & 1] = 0;
          toadd[it][(ls[id] & 1) ^ 1] = -1;
        }
        add(1, 0, n, ls[id], rs[id], toadd);
        if (rs[id] < n && !((rs[id] - ls[id]) & 1)) {
          toadd[0][0] = -1;
          toadd[0][1] = -1;
          toadd[1][0] = -1;
          toadd[1][1] = -1;
          add(1, 0, n, rs[id], n, toadd);
        }
        for (int a = 0; a < 2; a++) {
          for (int b = 0; b < 2; b++) {
            toadd[a][b] = (a != b);
          }
        }
        add(1, 0, n, ls[id], rs[id], toadd);
        if (rs[id] < n) {
          for (int it = 0; it < 2; it++) {
            toadd[rs[id] & 1][it] = 1;
            toadd[(rs[id] & 1) ^ 1][it] = 0;
          }
          add(1, 0, n, rs[id], n, toadd);
        }
      } else {
        int toadd[2][2];
        for (int it = 0; it < 2; it++) {
          toadd[rs[id] & 1][it] = -1;
          toadd[(rs[id] & 1) ^ 1][it] = 0;
        }
        add(1, 0, n, rs[id], n, toadd);
      }
    }
    for (int it = 0; it < 2; it++) {
      if (!st[1].mn[i & 1][it]) {
        res += st[1].sum[i & 1][it];
        res -= (long long) st[1].cnt[i & 1][it] * (i - 1);
      }
    }
    del(1, 0, n, i);
  }
  {
    vector< pair<int, int> > evs;
    for (int i = 0; i < m; i++) {
      evs.push_back(make_pair(ls[i], 1));
      evs.push_back(make_pair(rs[i], -1));
    }
    evs.push_back(make_pair(0, 0));
    evs.push_back(make_pair(n, 0));
    sort(evs.begin(), evs.end());
    int bal = 0;
    for (int i = 0; i + 1 < sz(evs); i++) {
      bal += evs[i].second;
      if (!bal) {
        int len = evs[i + 1].first - evs[i].first;
        res += (long long) len * (len + 1) * (2 * len + 1) / 6;
        res -= (long long) (len + 1) * (len + 1) * len / 2;
      }
    }
  }
  printf("%lld\n", res);
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