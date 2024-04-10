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
int n, m, k;
int mx[3];
int op[maxn][3], cl[maxn][3], qs[maxn][3];

int read() {
  if (scanf("%d%d%d%d%d%d", &mx[0], &mx[1], &mx[2], &n, &m, &k) < 6) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &op[i][j]);
      op[i][j]--;
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &cl[i][j]);
      cl[i][j]--;
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &qs[i][j]);
      qs[i][j]--;
    }
  }
  return true;
}

int ans[maxn];
int cnt[maxn];
vector<vector<int>> evs[maxn];
vector<int> tosort[maxn];
vector<int> ps[maxn];
vector<int> st[4 * maxn];
vector<pair<int, int>> srt[4 * maxn];
vector<int> pp[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v] = vector<int>(tr - tl, 0);
  srt[v] = vector<pair<int, int>>(tr - tl);
  pp[v] = vector<int>(tr - tl);
  if (tl == tr - 1) {
    srt[v][0] = make_pair(cl[tl][2], tl);
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
  merge(srt[2 * v].begin(), srt[2 * v].end(), srt[2 * v + 1].begin(), srt[2 * v + 1].end(), srt[v].begin());
  for (int i = 0; i < sz(srt[v]); i++) {
    pp[v][srt[v][i].second - tl] = i;
  }
}

void fenAdd(vector<int> &fen, int x, int toadd) {
  for (; x < sz(fen); x |= x + 1) {
    fen[x] += toadd;
  }
}

int fenGet(vector<int> &fen, int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    res += fen[x];
  }
  return res;
}

int get1(int v, int y) {
  int p = lower_bound(srt[v].begin(), srt[v].end(), make_pair(y, -1)) - srt[v].begin();
  if (!p) {
    return 0;
  }
  p--;
  return fenGet(st[v], p);
}

int get(int v, int tl, int tr, int l, int r, int y0, int y1) {
  if (l == tl && r == tr) {
    return get1(v, y1) - get1(v, y0);
  }
  int tm = (tl + tr) / 2;
  int res = 0;
  if (l < tm) {
    res += get(2 * v, tl, tm, l, min(r, tm), y0, y1);
  }
  if (r > tm) {
    res += get(2 * v + 1, tm, tr, max(l, tm), r, y0, y1);
  }
  return res;
}

void add(int v, int tl, int tr, int pos) {
  fenAdd(st[v], pp[v][pos - tl], 1);
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos < tm) {
    add(2 * v, tl, tm, pos);
  } else {
    add(2 * v + 1, tm, tr, pos);
  }
}

int xs[maxn];

void solve() {
  int l[3] = {inf, inf, inf}, r[3] = {-inf, -inf, -inf};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      l[j] = min(l[j], op[i][j]);
      r[j] = max(r[j], op[i][j] + 1);
    }
  }
  for (int i = 0; i < m; i++) {
    bool ok = true;
    for (int j = 0; j < 3; j++) {
      if (cl[i][j] < l[j] || cl[i][j] >= r[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      printf("INCORRECT\n");
      return;
    }
  }
  printf("CORRECT\n");
  for (int i = 0; i <= mx[0]; i++) {
    evs[i].clear();
    ps[i].clear();
  }
  for (int i = 0; i < k; i++) {
    bool ok = true;
    for (int j = 0; j < 3; j++) {
      if (qs[i][j] < l[j] || qs[i][j] >= r[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans[i] = 2;
      continue;
    }
    ans[i] = -1;
    int nl[3] = {l[0], l[1], l[2]}, nr[3] = {r[0], r[1], r[2]};
    for (int j = 0; j < 3; j++) {
      nl[j] = min(nl[j], qs[i][j]);
      nr[j] = max(nr[j], qs[i][j] + 1);
    }
    evs[nl[0]].push_back({nl[1], nl[2], nr[1], nr[2], i, -1});
    evs[nr[0]].push_back({nl[1], nl[2], nr[1], nr[2], i, 1});
  }
  if (!m) {
    for (int i = 0; i < k; i++) {
      if (ans[i] == -1) {
        ans[i] = 1;
      }
      printf(ans[i] == 0 ? "CLOSED\n" : (ans[i] == 1 ? "UNKNOWN\n" : "OPEN\n"));
    }
    return;
  }
  for (int i = 0; i < m; i++) {
    tosort[i] = {cl[i][1], cl[i][2], cl[i][0]};
  }
  sort(tosort, tosort + m);
  for (int i = 0; i < m; i++) {
    cl[i][0] = tosort[i][2];
    cl[i][1] = tosort[i][0];
    cl[i][2] = tosort[i][1];
  }
  for (int i = 0; i < m; i++) {
    ps[cl[i][0]].push_back(i);
    xs[i] = cl[i][1];
  }
  buildst(1, 0, m);
  for (int x = 0; x <= mx[0]; x++) {
    for (int i = 0; i < sz(evs[x]); i++) {
      auto &cur = evs[x][i];
      int x0 = cur[0], y0 = cur[1], x1 = cur[2], y1 = cur[3], id = cur[4], sgn = cur[5];
      int l = lower_bound(xs, xs + m, x0) - xs, r = lower_bound(xs, xs + m, x1) - xs;
      if (l < r) {
        cnt[id] += sgn * get(1, 0, m, l, r, y0, y1);
      }
    }
    for (int i = 0; i < sz(ps[x]); i++) {
      int pos = ps[x][i];
      add(1, 0, m, pos);
    }
  }
  for (int i = 0; i < k; i++) {
    if (ans[i] == -1) {
      if (cnt[i]) {
        ans[i] = 0;
      } else {
        ans[i] = 1;
      }
    }
    printf(ans[i] == 0 ? "CLOSED\n" : (ans[i] == 1 ? "UNKNOWN\n" : "OPEN\n"));
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