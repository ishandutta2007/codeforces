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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int maxn = (int) 1e5 + 5;
const int mod = (int) 1e9 + 7;
int hh, w, n;
pair<pair<int, int>, pair<int, int> > tosort[maxn];

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int read() {
  if (scanf("%d%d%d", &hh, &w, &n) < 3) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d%d", &tosort[i].first.first, &tosort[i].second.first, &tosort[i].second.second, &tosort[i].first.second);
    tosort[i].first.first--;
    tosort[i].second.first--;
  }
  return true;
}

int r[maxn], cl[maxn], cr[maxn], h[maxn];
int dp[maxn];
pair<int, int> ev[maxn];
int del[maxn];
priority_queue< pair<int, int> > st[4 * maxn];

void buildst(int v, int tl, int tr) {
  while (!st[v].empty()) {
    st[v].pop();
  }
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void add(int v, int tl, int tr, int l, int r, int id) {
  if (l == tl && r == tr) {
    st[v].push(make_pair(::r[id], id));
    return;
  }
  int tm = (tl + tr) / 2;
  if (l < tm) {
    add(2 * v, tl, tm, l, min(r, tm), id);
  }
  if (r > tm) {
    add(2 * v + 1, tm, tr, max(l, tm), r, id);
  }
}

int get(int v, int tl, int tr, int x) {
  int res = -1;
  while (!st[v].empty() && del[st[v].top().second]) {
    st[v].pop();
  }
  if (!st[v].empty()) {
    int id = st[v].top().second;
    if (res == -1 || r[id] > r[res]) {
      res = id;
    }
  }
  if (tl == tr - 1) {
    return res;
  }
  int tm = (tl + tr) / 2;
  int id;
  if (x < tm) {
    id = get(2 * v, tl, tm, x);
  } else {
    id = get(2 * v + 1, tm, tr, x);
  }
  if (id == -1) {
    return res;
  }
  if (res == -1 || r[id] > r[res]) {
    res = id;
  }
  return res;
}

void solve() {
  sort(tosort, tosort + n);
  for (int i = 0; i < n; i++) {
    r[i] = tosort[i].first.first;
    cl[i] = tosort[i].second.first;
    cr[i] = tosort[i].second.second;
    h[i] = tosort[i].first.second;
  }
  buildst(1, 0, w);
  for (int i = 0; i < n; i++) {
    ev[i] = make_pair(r[i] + h[i], i);
  }
  sort(ev, ev + n);
  int curev = 0;
  for (int i = 0; i < n; i++) {
    del[i] = false;
  }
  for (int i = 0; i < n; i++) {
    while (curev < n && ev[curev].first < r[i]) {
      int id = ev[curev].second;
      del[id] = true;
      curev++;
    }
    int cnt = 0;
    dp[i] = 0;
    for (int iter = 0; iter < 2; iter++) {
      int x = (!iter ? cl[i] - 1 : cr[i]);
      if (x < 0 || x >= w) {
        continue;
      }
      cnt++;
      int nxt = get(1, 0, w, x);
      if (nxt == -1) {
        add(dp[i], 1);
      } else {
        add(dp[i], dp[nxt]);
      }
    }
    assert(cnt > 0);
    if (cnt == 1) {
      add(dp[i], dp[i]);
    }
    add(1, 0, w, cl[i], cr[i], i);
  }
  while (curev < n && ev[curev].first < hh) {
    int id = ev[curev].second;
    del[id] = true;
    curev++;
  }
  int res = 0;
  for (int i = 0; i < w; i++) {
    int nxt = get(1, 0, w, i);
    if (nxt == -1) {
      add(res, 1);
    } else {
      add(res, dp[nxt]);
    }
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