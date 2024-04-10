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

const int n = 3, pown = (1 << n), m = (1 << pown) * 3;
string s[m];
int used[m];
priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;

void update(int v, const string &a) {
  if (s[v].empty() || sz(a) < sz(s[v]) || (sz(a) == sz(s[v]) && a < s[v])) {
    s[v] = a;
    pq.push(make_pair(sz(a), v));
  }
}

void precalc() {
  for (int i = 0; i < m; i++) {
    s[i].clear();
    used[i] = false;
  }
  while (!pq.empty()) {
    pq.pop();
  }
  {
    int msk[3] = {0, 0, 0};
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
          int cur = (i | (j << 1) | (k << 2));
          if (i) {
            msk[0] |= (1 << cur);
          }
          if (j) {
            msk[1] |= (1 << cur);
          }
          if (k) {
            msk[2] |= (1 << cur);
          }
        }
      }
    }
    s[msk[0] * 3] = 'z';
    s[msk[1] * 3] = 'y';
    s[msk[2] * 3] = 'x';
    for (int i = 0; i < 3; i++) {
      pq.push(make_pair(sz(s[msk[i] * 3]), msk[i] * 3));
    }
  }
  while (!pq.empty()) {
    int dd = pq.top().first, v = pq.top().second;
    pq.pop();
    if (dd != sz(s[v])) {
      continue;
    }
    used[v] = true;
    int mv = v / 3, tv = v % 3;
    for (int u = 0; u < m; u++) {
      if (!used[u]) {
        continue;
      }
      int mu = u / 3, tu = u % 3;
      {
        int to = (mv | mu) * 3 + 2;
        update(to, s[u] + "|" + s[v]);
        update(to, s[v] + "|" + s[u]);
      }
      if (tv < 2 && tu < 2) {
        int to = (mv & mu) * 3 + 1;
        update(to, s[u] + "&" + s[v]);
        update(to, s[v] + "&" + s[u]);
      }
    }
    if (!tv) {
      int to = (mv ^ ((1 << pown) - 1)) * 3;
      update(to, "!" + s[v]);
    }
    {
      int to = mv * 3;
      update(to, "(" + s[v] + ")");
    }
    for (int i = tv + 1; i < 3; i++) {
      int to = mv * 3 + i;
      update(to, s[v]);
    }
  }
  for (int i = 0; i < m; i++) {
    assert(!s[i].empty());
  }
}

char tmp[100];
int x;

int read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  x = 0;
  for (int i = 0; i < 8; i++) {
    x |= ((tmp[i] - '0') << i);
  }
  return true;
}

void solve() {
  printf("%s\n", s[x * 3 + 2].c_str());
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}