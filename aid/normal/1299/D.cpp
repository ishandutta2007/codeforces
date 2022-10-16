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

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int k = 5;
vector<vector<int>> bs, bits;
vector<vector<int>> go;

void gen(vector<int> b, vector<int> bit) {
  bs.push_back(b);
  bits.push_back(bit);
  for (int x = 1; x < (1 << k); x++) {
    bool ok = true;
    for (int i = 0; i < sz(b); i++) {
      if (x & (1 << bit[i])) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    int bb = 0;
    while (!(x & (1 << bb))) {
      bb++;
    }
    for (int i = 0; i < sz(b); i++) {
      if ((b[i] & (1 << bb)) || bb <= bit[i]) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      continue;
    }
    b.push_back(x);
    bit.push_back(bb);
    gen(b, bit);
    b.pop_back();
    bit.pop_back();
  }
}

vector<pair<vector<int>, vector<int>>> tosort;

int getId(const vector<int> &b, const vector<int> &bit) {
  int pos = lower_bound(tosort.begin(), tosort.end(), make_pair(b, bit)) - tosort.begin();
  assert(pos < sz(tosort) && tosort[pos] == make_pair(b, bit));
  return pos;
}

void precalc() {
  gen({}, {});
  eprintf("%d\n", sz(bs));
  for (int i = 0; i < sz(bs); i++) {
    tosort.push_back(make_pair(bs[i], bits[i]));
  }
  sort(tosort.begin(), tosort.end());
  for (int i = 0; i < sz(bs); i++) {
    bs[i] = tosort[i].first;
    bits[i] = tosort[i].second;
  }
  go = vector<vector<int>>(sz(bs), vector<int>((1 << k), -1));
  for (int i = 0; i < sz(bs); i++) {
    for (int x = 0; x < (1 << k); x++) {
      int y = x;
      for (int j = 0; j < sz(bs[i]); j++) {
        if (y & (1 << bits[i][j])) {
          y ^= bs[i][j];
        }
      }
      if (!y) {
        continue;
      }
      vector<int> nb = bs[i], nbit = bits[i];
      int bb = 0;
      while (!(y & (1 << bb))) {
        bb++;
      }
      for (int j = 0; j < sz(nb); j++) {
        if (nb[j] & (1 << bb)) {
          nb[j] ^= y;
        }
      }
      nb.push_back(y);
      nbit.push_back(bb);
      vector<pair<int, int>> srt(sz(nb));
      for (int j = 0; j < sz(nb); j++) {
        srt[j] = make_pair(nbit[j], nb[j]);
      }
      sort(srt.begin(), srt.end());
      for (int j = 0; j < sz(nb); j++) {
        nb[j] = srt[j].second;
        nbit[j] = srt[j].first;
      }
      go[i][x] = getId(nb, nbit);
    }
  }
}

const int maxn = (int) 1e5 + 5;
int n, m;
vector<pair<int, int>> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < m; i++) {
    int v, u, w;
    scanf("%d%d%d", &v, &u, &w);
    v--;
    u--;
    g[v].push_back(make_pair(u, w));
    g[u].push_back(make_pair(v, w));
  }
  return true;
}

int used[maxn];
int val[maxn];
vector<int> cs, bc;
int c0;
vector<int> dp, ndp;

void dfs(int v, int p) {
  used[v] = 1;
  for (int i = 0; i < sz(g[v]); i++) {
    int u = g[v][i].first, w = g[v][i].second;
    if (u == p) {
      continue;
    }
    if (used[u] == 2) {
      continue;
    }
    if (used[u] == 1) {
      int c = (val[v] ^ val[u] ^ w);
      if (u == 0) {
        c0 = c;
      } else {
        cs.push_back(c);
      }
      continue;
    }
    val[u] = (val[v] ^ w);
    dfs(u, v);
  }
  used[v] = 2;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = 0;
  }
  used[0] = 1;
  dp.clear();
  dp.resize(sz(bs));
  ndp.clear();
  ndp.resize(sz(bs));
  dp[getId({}, {})] = 1;
  for (int i = 0; i < sz(g[0]); i++) {
    int v = g[0][i].first, w = g[0][i].second;
    if (used[v]) {
      continue;
    }
    cs.clear();
    c0 = -1;
    val[v] = w;
    dfs(v, 0);
    bc.clear();
    bool ok = true;
    int k = 0;
    for (int j = 0; j < sz(cs); j++) {
      for (int l = 0; l < k; l++) {
        if (cs[j] & (1 << bc[l])) {
          cs[j] ^= cs[l];
        }
      }
      if (!cs[j]) {
        ok = false;
        break;
      }
      int bb = 0;
      while (!(cs[j] & (1 << bb))) {
        bb++;
      }
      for (int l = 0; l < k; l++) {
        if (cs[l] & (1 << bb)) {
          cs[l] ^= cs[j];
        }
      }
      cs[k++] = cs[j];
      bc.push_back(bb);
    }
    if (!ok) {
      continue;
    }
    cs.resize(k);
    for (int i = 0; i < sz(bs); i++) {
      ndp[i] = 0;
    }
    if (c0 == -1) {
      for (int i = 0; i < sz(bs); i++) {
        int cur = dp[i];
        if (!cur) {
          continue;
        }
        add(ndp[i], cur);
        int j = i;
        for (int l = 0; l < k && j != -1; l++) {
          j = go[j][cs[l]];
        }
        if (j != -1) {
          add(ndp[j], cur);
        }
      }
    } else {
      for (int i = 0; i < sz(bs); i++) {
        int cur = dp[i];
        if (!cur) {
          continue;
        }
        add(ndp[i], cur);
        int j = i;
        for (int l = 0; l < k && j != -1; l++) {
          j = go[j][cs[l]];
        }
        if (j != -1) {
          add(ndp[j], mul(cur, 2));
          j = go[j][c0];
          if (j != -1) {
            add(ndp[j], cur);
          }
        }
      }
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int i = 0; i < sz(bs); i++) {
    add(res, dp[i]);
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