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

const string ops[9] = {"lock", "unlock", "red", "orange", "yellow", "green", "blue", "indigo", "violet"};

char tmp[100];

int readOp() {
  scanf("%s", tmp);
  string s = tmp;
  return find(ops, ops + 9, s) - ops;
}

const int maxn = (int) 1e5 + 5;
int n;
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  a[0] = 1;
  a[1] = 6;
  n += 2;
  for (int i = 2; i < n; ++i) {
    a[i] = readOp();
  }
  return true;
}

int who[maxn];
set<int> locks, cols;

void getAns() {
  printf("%s\n", ops[a[*cols.rbegin()]].c_str());
}

void solve() {
  locks.clear();
  for (int i = 0; i < n; ++i) {
    if (a[i] < 2) {
      locks.insert(i);
      who[i] = -1;
    }
  }
  cols.clear();
  for (auto it = locks.begin(); it != locks.end();) {
    auto nit = it;
    ++nit;
    if (a[*it] == 1) {
      int pos = (nit == locks.end() ? n : *nit) - 1;
      if (pos > *it) {
        cols.insert(pos);
        who[*it] = pos;
      }
    }
    it = nit;
  }
  getAns();
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