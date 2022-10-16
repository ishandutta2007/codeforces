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

#define ws wwwwwwws

const int maxk = 8, maxq = 30, logn = 28;
int x, k, n, q;
long long c[maxk + 5];
int ps[maxq];
long long ws[maxq];

int read() {
  if (scanf("%d%d%d%d", &x, &k, &n, &q) < 4) {
    return false;
  }
  for (int i = 1; i <= k; i++) {
    scanf("%lld", &c[i]);
  }
  for (int i = 0; i < q; i++) {
    scanf("%d%lld", &ps[i], &ws[i]);
    ps[i]--;
  }
  return true;
}

map<int, int> ids;
vector<int> msks;

void remin(long long &a, long long b) {
  a = min(a, b);
}

vector< vector<long long> > matMul(const vector< vector<long long> > &a, const vector< vector<long long> > &b) {
  int n = sz(a);
  vector< vector<long long> > res(n, vector<long long>(n, infll));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        remin(res[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return res;
}

void mulVec(vector<long long> &v, const vector< vector<long long> > &a) {
  int n = sz(v);
  vector<long long> res(n, infll);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      remin(res[j], v[i] + a[i][j]);
    }
  }
  v = res;
}

vector< vector<long long> > a;
vector< vector<long long> > as[logn];
vector<long long> v;
int curp;

void go(int pos) {
  if (pos <= curp) {
    return;
  }
  int d = pos - curp;
  for (int i = 0; i < logn; i++) {
    if (d & (1 << i)) {
      mulVec(v, as[i]);
    }
  }
  curp = pos;
}

pair<int, int> tosort[maxq];

void solve() {
  int y = k - x + 1;
  ids.clear();
  msks.clear();
  for (int msk = 1; msk < (1 << k); msk += 2) {
    if (__builtin_popcount(msk) != x) {
      continue;
    }
    ids[msk] = sz(msks);
    msks.push_back(msk);
  }
  a = vector< vector<long long> >(y * sz(msks), vector<long long>(y * sz(msks), infll));
  for (int i = 0; i < sz(msks); i++) {
    int msk = msks[i];
    for (int d = 1; d <= k; d++) {
      if (msk & (1 << d)) {
        continue;
      }
      int nmsk = msk;
      nmsk ^= 1;
      nmsk ^= (1 << d);
      int sh = 0;
      while (!(nmsk & 1)) {
        nmsk >>= 1;
        sh++;
      }
      int nid = ids[nmsk];
      remin(a[(sh - 1) * sz(msks) + i][nid], c[d]);
    }
  }
  for (int i = 0; i < (y - 1) * sz(msks); i++) {
    remin(a[i][sz(msks) + i], 0);
  }
  as[0] = a;
  for (int i = 1; i < logn; i++) {
    as[i] = matMul(as[i - 1], as[i - 1]);
  }
  v = vector<long long>(y * sz(msks), infll);
  v[ids[(1 << x) - 1]] = 0;
  for (int i = 0; i < q; i++) {
    tosort[i] = make_pair(ps[i], i);
  }
  sort(tosort, tosort + q);
  curp = 0;
  for (int i = 0; i < q; i++) {
    int id = tosort[i].second;
    go(ps[id] - maxk);
    while (curp < ps[id] && curp < n - x) {
      a = vector< vector<long long> >(y * sz(msks), vector<long long>(y * sz(msks), infll));
      for (int i = 0; i < sz(msks); i++) {
        int msk = msks[i];
        for (int d = 1; d <= k; d++) {
          if (msk & (1 << d)) {
            continue;
          }
          int nmsk = msk;
          nmsk ^= 1;
          nmsk ^= (1 << d);
          int sh = 0;
          while (!(nmsk & 1)) {
            nmsk >>= 1;
            sh++;
          }
          int nid = ids[nmsk];
          int pos = curp - sh + 1;
          int val = c[d];
          for (int j = 0; j < q; j++) {
            if (pos + d == ps[j]) {
              val += ws[j];
            }
          }
          remin(a[(sh - 1) * sz(msks) + i][nid], val);
        }
      }
      for (int i = 0; i < (y - 1) * sz(msks); i++) {
        remin(a[i][sz(msks) + i], 0);
      }
      mulVec(v, a);
      curp++;
    }
  }
  go(n - x);
  printf("%lld\n", v[ids[(1 << x) - 1]]);
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