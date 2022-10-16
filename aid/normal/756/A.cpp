#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

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

void precalc() {
}

const int maxn = (int) 2e5 + 5;
int n;
int p[maxn], b[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  return true;
}

int used[maxn];

void solve() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    used[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      continue;
    }
    int x = i;
    cnt++;
    while (!used[x]) {
      used[x] = true;
      x = p[x];
    }
  }
  int res = (cnt == 1 ? 0 : cnt);
  int s = 0;
  for (int i = 0; i < n; i++) {
    s ^= b[i];
  }
  if (!s) {
    res++;
  }
  printf("%d\n", res);
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