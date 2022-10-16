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

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

void getZ(const string &s, vector<int> &z) {
  int n = sz(s);
  z.clear();
  z.resize(n, 0);
  z[0] = n;
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) {
      z[i] = min(r - i + 1, z[i - l]);
    }
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
}

const int maxn = (int) 1e5 + 5, K = 100;
int n, m, q;
char tmp[maxn];
string s, t, ss, tt;
vector<int> z, zt;
int p[maxn];
int ps[maxn];
int logs[maxn];

void precalc() {
  logs[1] = 0;
  for (int i = 2; i < maxn; i++) {
    logs[i] = logs[i / 2] + 1;
  }
}

bool cmp(int i, int j) {
  if (i == -1) {
    return false;
  }
  if (j == -1) {
    return true;
  }
  if (i == j) {
    return false;
  }
  bool rev = (i > j);
  if (rev) {
    swap(i, j);
  }
  if (z[m + i] < j - i && z[m + i] < m) {
    return ((t[z[m + i]] < s[i + z[m + i]]) ^ rev);
  }
  if (j - i < m) {
    if (p[j - i] == -1) {
      return !rev;
    }
    return ((tt[p[j - i]] < tt[p[j - i] - (j - i)]) ^ rev);
  }
  if (ps[i] < j) {
    return ((t[(ps[i] - i) % m] < s[ps[i]]) ^ rev);
  }
  int pos = (j - i) % m;
  if (zt[pos] >= m) {
    return !rev;
  }
  return ((tt[pos + zt[pos]] < tt[zt[pos]]) ^ rev);
}

void buildst(vector<int> &st, const vector<int> &a, int v, int tl, int tr) {
  if (tl == tr - 1) {
    st[v] = a[tl];
    return;
  }
  int tm = (tl + tr) / 2;
  buildst(st, a, 2 * v, tl, tm);
  buildst(st, a, 2 * v + 1, tm, tr);
  st[v] = st[2 * v];
  if (cmp(st[2 * v + 1], st[v])) {
    st[v] = st[2 * v + 1];
  }
}

int get(vector<int> &st, int v, int tl, int tr, int l, int r) {
  if (l == tl && r == tr) {
    return st[v];
  }
  int tm = (tl + tr) / 2, res = -1;
  if (l < tm) {
    int cur = get(st, 2 * v, tl, tm, l, min(r, tm));
    if (cmp(cur, res)) {
      res = cur;
    }
  }
  if (r > tm) {
    int cur = get(st, 2 * v + 1, tm, tr, max(l, tm), r);
    if (cmp(cur, res)) {
      res = cur;
    }
  }
  return res;
}

const int logn = 20;
int sp[logn][maxn];
vector<int> sst[K][K];

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  scanf("%s", tmp);
  t = tmp;
  m = sz(t);
  return true;
}

int getsp(int l, int r) {
  int k = logs[r - l];
  int res = sp[k][l];
  if (cmp(sp[k][r - (1 << k)], res)) {
    res = sp[k][r - (1 << k)];
  }
  return res;
}

void solve() {
  {
    ss = t + s;
    getZ(ss, z);
    ps[n] = n;
    for (int i = n - 1; i >= 0; i--) {
      if (z[m + i] < m) {
        ps[i] = i + z[m + i];
      } else {
        ps[i] = ps[i + m];
      }
    }
  }
  {
    tt = t + t;
    getZ(tt, zt);
    for (int k = 1; k <= m; k++) {
      p[k] = -1;
      for (int i = k; i <= m; i += k) {
        if (zt[i] < k) {
          p[k] = i + zt[i];
          break;
        }
      }
    }
  }
  {
    for (int i = 0; i <= n; i++) {
      sp[0][i] = i;
    }
    for (int i = 1; i < logn; i++) {
      for (int j = 0; j + (1 << i) <= n + 1; j++) {
        sp[i][j] = sp[i - 1][j];
        if (cmp(sp[i - 1][j + (1 << (i - 1))], sp[i][j])) {
          sp[i][j] = sp[i - 1][j + (1 << (i - 1))];
        }
      }
    }
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < k; i++) {
      vector<int> a;
      for (int j = i; j <= n; j += k) {
        a.push_back(j);
      }
      sst[k][i].resize(4 * sz(a) + 5);
      if (!a.empty()) {
        buildst(sst[k][i], a, 1, 0, sz(a));
      }
    }
  }
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int l, r, k, x, y;
    scanf("%d%d%d%d%d", &l, &r, &k, &x, &y);
    r++;
    y++;
    int res = -1;
    if (k >= K) {
      for (int i = 0; i <= n; i += k) {
        int lk = i + x, rk = i + y;
        int ll = max(l, lk), rr = min(r, rk);
        if (ll < rr) {
          int cur = getsp(ll, rr);
          if (cmp(cur, res)) {
            res = cur;
          }
        }
      }
    } else {
      for (int i = x; i < y; i++) {
        int ll = (l - i + k - 1) / k, rr = (r - i + k - 1) / k;
        if (ll < rr) {
          int cur = get(sst[k][i], 1, 0, (sz(sst[k][i]) - 5) / 4, ll, rr);
          if (cmp(cur, res)) {
            res = cur;
          }
        }
      }
    }
    printf("%d ", res);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef LOCAL
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (true) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}