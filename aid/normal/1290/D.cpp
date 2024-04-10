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

int n, k;

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  return true;
}

const int maxn = 1030;
int bad[maxn];
int curb;

void clearMem() {
  printf("R\n");
  fflush(stdout);
}

char tmp[10];

bool ask(int x) {
  printf("? %d\n", x + 1);
  fflush(stdout);
  scanf("%s", tmp);
  return tmp[0] == 'N';
}

void solve1(const vector<int> &a, const vector<int> &b) {
  int al = sz(a) / 2, bl = sz(b) / 2;
  clearMem();
  for (int i = 0; i < al; i++) {
    ask(a[i]);
  }
  for (int i = 0; i < bl; i++) {
    if (!ask(b[i])) {
      bad[b[i]] = curb;
    }
  }
  for (int i = al; i < sz(a); i++) {
    if (!ask(a[i])) {
      bad[a[i]] = curb;
    }
  }
  for (int i = bl; i < sz(b); i++) {
    if (!ask(b[i])) {
      bad[b[i]] = curb;
    }
  }
  clearMem();
  for (int i = 0; i < al; i++) {
    ask(a[i]);
  }
  for (int i = bl; i < sz(b); i++) {
    if (!ask(b[i])) {
      bad[b[i]] = curb;
    }
  }
}

vector<int> merge(const vector<int> &a, const vector<int> &b) {
  curb++;
  for (int i = 0; i < sz(a); i += k) {
    vector<int> aa;
    for (int ii = i; ii < min(sz(a), i + k); ii++) {
      if (bad[a[ii]] != curb) {
        aa.push_back(a[ii]);
      }
    }
    for (int j = 0; j < sz(b); j += k) {
      vector<int> bb;
      for (int jj = j; jj < min(sz(b), j + k); jj++) {
        if (bad[b[jj]] != curb) {
          bb.push_back(b[jj]);
        }
      }
      solve1(aa, bb);
    }
  }
  vector<int> c;
  for (int i = 0; i < sz(a); i++) {
    if (bad[a[i]] != curb) {
      c.push_back(a[i]);
    }
  }
  for (int i = 0; i < sz(b); i++) {
    if (bad[b[i]] != curb) {
      c.push_back(b[i]);
    }
  }
  return c;
}

vector<vector<int>> a, b;

void solve() {
  a.clear();
  if (k == 1) {
    a.push_back({});
    for (int i = 0; i < n; i++) {
      bool ok = true;
      for (int j = 0; j < i; j++) {
        ask(j);
        if (!ask(i)) {
          ok = false;
          break;
        }
      }
      if (ok) {
        a.back().push_back(i);
      }
    }
  } else {
    for (int i = 0; i < n; i += k) {
      clearMem();
      a.push_back({});
      for (int j = 0; j < k; j++) {
        if (ask(i + j)) {
          a.back().push_back(i + j);
        }
      }
    }
    while (sz(a) > 1) {
      b.clear();
      for (int i = 0; i < sz(a); i += 2) {
        b.push_back(merge(a[i], a[i + 1]));
      }
      swap(a, b);
    }
  }
  printf("! %d\n", sz(a[0]));
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