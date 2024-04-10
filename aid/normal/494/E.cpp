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

/*const int maxn = 105;
int dp[maxn][maxn][maxn];
int mex[maxn];*/

void precalc() {
  /*for (int k = 1; k < maxn; k++) {
    for (int x = 0; x < maxn; x++) {
      for (int y = 0; y < maxn; y++) {
        for (int i = 0; i <= k; i++) {
          mex[i] = false;
        }
        for (int len = 1; len <= k && len <= x + 1 && len <= y + 1; len++) {
          int cur = 0;
          for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
              if (!i && !j) {
                continue;
              }
              cur ^= dp[k][x - i][y - j];
            }
          }
          if (cur <= k) {
            mex[cur] = true;
          }
        }
        auto &cur = dp[k][x][y];
        cur = 0;
        while (mex[cur]) {
          cur++;
        }
        int bit = __builtin_ctz((x + 1) | (y + 1));
        bit = min(bit, 31 - __builtin_clz(k));
        //eprintf("%d (%d %d): %d\n", k, x, y, cur);
        assert(cur == (1 << bit));
      }
    }
  }*/
}

const int maxm = (int) 5e4 + 5;
int n, m, k;
int ps[maxm][2][2];

bool read() {
  if (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      for (int l = 0; l < 2; l++) {
        scanf("%d", &ps[i][j][l]);
      }
    }
    ps[i][0][0]--;
    ps[i][0][1]--;
  }
  return true;
}

vector<int> xs;
vector<pair<int, pair<int, int>>> evs;

struct node {
  int val, toadd;
  int x;
};

const int maxn = 2 * maxm;
node st[4 * maxn];

void buildst(int v, int tl, int tr) {
  st[v].val = 0;
  st[v].toadd = 0;
  st[v].x = ((xs[tr] - xs[tl]) & 1);
  if (tl == tr - 1) {
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(2 * v, tl, tm);
  buildst(2 * v + 1, tm, tr);
}

void push(int v) {
  if (!st[v].toadd) {
    return;
  }
  for (int i = 0; i < 2; i++) {
    int u = 2 * v + i;
    st[u].val += st[v].toadd;
    st[u].toadd += st[v].toadd;
  }
  st[v].toadd = 0;
}

void update(int v, int tl, int tr, int l, int r, int toadd) {
  if (l == tl && r == tr) {
    st[v].val += toadd;
    st[v].toadd += toadd;
    return;
  }
  push(v);
  int tm = (tl + tr) / 2;
  if (l < tm) {
    update(2 * v, tl, tm, l, min(r, tm), toadd);
  }
  if (r > tm) {
    update(2 * v + 1, tm, tr, max(l, tm), r, toadd);
  }
  st[v].val = min(st[2 * v].val, st[2 * v + 1].val);
  st[v].x = (st[2 * v].val < st[2 * v + 1].val ? st[2 * v].x :
             (st[2 * v + 1].val < st[2 * v].val ? st[2 * v + 1].x : (st[2 * v].x ^ st[2 * v + 1].x)));
}

int qs[maxn][2];

int solve1(int bit) {
  xs.clear();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      xs.push_back(ps[i][j][1] >> bit);
    }
  }
  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  if (sz(xs) <= 1) {
    return 0;
  }
  evs.clear();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      qs[i][j] = lower_bound(xs.begin(), xs.end(), ps[i][j][1] >> bit) - xs.begin();
    }
    if (qs[i][0] < qs[i][1]) {
      evs.push_back(make_pair(ps[i][0][0] >> bit, make_pair(0, i)));
      evs.push_back(make_pair(ps[i][1][0] >> bit, make_pair(1, i)));
    }
  }
  sort(evs.begin(), evs.end());
  int res = 0;
  buildst(1, 0, sz(xs) - 1);
  int pr = 0;
  for (int i = 0; i < sz(evs); i++) {
    int y = ((evs[i].first - pr) & 1);
    int x = (st[1].val ? 0 : st[1].x);
    x ^= ((xs.back() - xs[0]) & 1);
    res ^= (x & y);
    int id = evs[i].second.second;
    if (!evs[i].second.first) {
      update(1, 0, sz(xs) - 1, qs[id][0], qs[id][1], 1);
    } else {
      update(1, 0, sz(xs) - 1, qs[id][0], qs[id][1], -1);
    }
    pr = evs[i].first;
  }
  return res;
}

void solve() {
  int res = 0;
  for (int bit = 0; (1ll << bit) <= k; bit++) {
    res ^= solve1(bit) * ((1ll << (bit + 1)) - 1);
  }
  printf(res ? "Hamed\n" : "Malek\n");
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