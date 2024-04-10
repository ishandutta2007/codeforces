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

const int maxn = 505;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int ask(const vector<int> &s, const vector<int> &t, int v) {
  printf("%d\n", sz(s));
  for (int i = 0; i < sz(s); i++) {
    printf("%d ", s[i] + 1);
  }
  printf("\n");
  printf("%d\n", sz(t));
  for (int i = 0; i < sz(t); i++) {
    printf("%d ", t[i] + 1);
  }
  printf("\n");
  printf("%d\n", v + 1);
  fflush(stdout);
  int res;
  scanf("%d", &res);
  return res;
}

int ts[maxn];
int used[maxn];
int p[maxn];

void solve() {
  {
    ts[0] = n;
    vector<int> s = {0};
    vector<int> t;
    for (int j = 1; j < n; j++) {
      t.push_back(j);
    }
    for (int i = 1; i < n; i++) {
      ts[i] = ask(s, t, i);
    }
  }
  for (int i = 0; i < n; i++) {
    used[i] = false;
    p[i] = -1;
  }
  for (int it = 0; it < n - 1; it++) {
    int v = -1;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      if (v == -1 || (ts[i] < ts[v])) {
        v = i;
      }
    }
    int need = ts[v] - 1;
    while (need) {
      vector<int> vs;
      for (int i = 0; i < n; i++) {
        if (used[i] && p[i] == -1) {
          vs.push_back(i);
        }
      }
      vector<int> s = {0};
      vector<int> t;
      int l = 0, r = sz(vs);
      while (l < r - 1) {
        int m = (l + r) / 2;
        t = vs;
        t.resize(m);
        if (ask(s, t, v)) {
          r = m;
        } else {
          l = m;
        }
      }
      int u = vs[l];
      p[u] = v;
      need -= ts[u];
    }
    used[v] = true;
  }
  for (int i = 1; i < n; i++) {
    if (p[i] == -1) {
      p[i] = 0;
    }
  }
  printf("ANSWER\n");
  for (int i = 1; i < n; i++) {
    printf("%d %d\n", p[i] + 1, i + 1);
  }
  fflush(stdout);
}

int main() {
  precalc();
  read();
  solve();
#ifdef DEBUG
  eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  return 0;
}