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

const int maxn = 1005;
int n;
int ls[maxn], rs[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &ls[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &rs[i]);
  }
  return true;
}

int used[maxn];
int ans[maxn];

bool del(int pos) {
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    if (i < pos) {
      rs[i]--;
    } else {
      ls[i]--;
    }
    if (rs[i] < 0 || rs[i] < 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  int val = n;
  while (true) {
    {
      bool ok = true;
      for (int i = 0; i < n; i++) {
        if (!used[i]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        break;
      }
    }
    vector<int> todel;
    for (int i = 0; i < n; i++) {
      if (used[i]) {
        continue;
      }
      if (ls[i] == 0 && rs[i] == 0) {
        ans[i] = val;
        used[i] = true;
        todel.push_back(i);
      }
    }
    if (todel.empty()) {
      printf("NO\n");
      return;
    }
    for (int i = 0; i < sz(todel); i++) {
      if (!del(todel[i])) {
        printf("NO\n");
        return;
      }
    }
    val--;
  }
  printf("YES\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
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