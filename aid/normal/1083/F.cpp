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

const int maxn = (int) 2e5 + 5;
int n, k, q;
int as[2][maxn];
int a[maxn];

bool read() {
  if (scanf("%d%d%d", &n, &k, &q) < 3) {
    return false;
  }
  for (int i = 0; i <= n; i++) {
    a[i] = 0;
  }
  for (int t = 0; t < 2; t++) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &as[t][i]);
      a[i] ^= as[t][i];
    }
  }
  return true;
}

int good;
int res;
const int B = 1000;
const int maxx = (1 << 14);

struct block {
  int toxor;
  vector<int> a;
  int cnt[maxx];

  block(const vector<int> &aa) {
    a = aa;
    toxor = 0;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < sz(a); i++) {
      cnt[a[i]]++;
    }
  }

  void update1(int pos, int x) {
    cnt[a[pos]]--;
    a[pos] ^= x;
    cnt[a[pos]]++;
  }

  void update(int x) {
    toxor ^= x;
  }

  int getAt(int pos) {
    return (a[pos] ^ toxor);
  }

  int get1() {
    return sz(a) - cnt[toxor];
  }
};

struct T {
  vector<int> a;
  vector<block> bs;

  T() {}

  T(const vector<int> &aa) {
    a = aa;
    bs.clear();
    if (sz(a) < B) {
      good += (a.back() == 0);
      for (int i = 0; i < sz(a); i++) {
        if (a[i]) {
          res++;
        }
      }
      return;
    }
    for (int i = 0; i < sz(a); i += B) {
      vector<int> b;
      for (int j = i; j < min(sz(a), i + B); j++) {
        b.push_back(a[j]);
      }
      bs.push_back(block(b));
    }
    good += (a.back() == 0);
    for (int i = 0; i < sz(a); i++) {
      if (a[i]) {
        res++;
      }
    }
  }

  void update(int pos, int toxor) {
    if (sz(a) < B) {
      good -= (a.back() == 0);
      for (int i = pos; i < sz(a); i++) {
        res -= (a[i] != 0);
        a[i] ^= toxor;
        res += (a[i] != 0);
      }
      good += (a.back() == 0);
      return;
    }
    good -= (bs.back().getAt((sz(a) - 1) % B) == 0);
    while (pos < sz(a) && pos % B) {
      res -= bs[pos / B].get1();
      bs[pos / B].update1(pos % B, toxor);
      res += bs[pos / B].get1();
      pos++;
    }
    while (pos < sz(a)) {
      res -= bs[pos / B].get1();
      bs[pos / B].update(toxor);
      res += bs[pos / B].get1();
      pos += B;
    }
    good += (bs.back().getAt((sz(a) - 1) % B) == 0);
  }
};

int b[maxn];
int spos[maxn];
vector<int> s[maxn];
T ts[maxn];

void solve() {
  for (int i = 0; i <= n; i++) {
    b[i] = ((i ? a[i - 1] : 0) ^ a[i]);
  }
  good = 0;
  res = 0;
  for (int i = 0; i < k; i++) {
    s[i].clear();
    for (int j = i; j <= n; j += k) {
      spos[j] = sz(s[i]);
      int cur = b[j];
      if (!s[i].empty()) {
        cur ^= s[i].back();
      }
      s[i].push_back(cur);
    }
    ts[i] = T(s[i]);
  }
  if (good < k) {
    printf("-1\n");
  } else {
    printf("%d\n", res);
  }
  for (int qq = 0; qq < q; qq++) {
    char tmp[10];
    int pos, val;
    scanf("%s%d%d", tmp, &pos, &val);
    int t = (tmp[0] == 'a' ? 0 : 1);
    pos--;
    int toxor = (val ^ as[t][pos]);
    as[t][pos] = val;
    for (int it = 0; it < 2; it++) {
      int p = pos + it;
      b[p] ^= toxor;
      int id = p % k;
      int sp = spos[p];
      ts[id].update(sp, toxor);
    }
    if (good < k) {
      printf("-1\n");
    } else {
      printf("%d\n", res);
    }
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