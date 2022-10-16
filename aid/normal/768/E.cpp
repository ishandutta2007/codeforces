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
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

const int maxx = 61;
map<pair<int, int>, int> gr;

void rec(int n, int msk) {
  if (gr.count(make_pair(n, msk))) {
    return;
  }
  int &res = gr[make_pair(n, msk)];
  vector<int> mex(n + 5, 0);
  for (int i = 1; i <= n; i++) {
    if (i <= 30 && msk & (1 << i)) {
      continue;
    }
    int tomsk = msk;
    if (i <= 30) {
      tomsk |= (1 << i);
    }
    rec(n - i, tomsk);
    int cur = gr[make_pair(n - i, tomsk)];
    if (cur < sz(mex)) {
      mex[cur] = true;
    }
  }
  res = 0;
  while (mex[res]) {
    res++;
  }
}

void precalc() {
  for (int i = 0; i < maxx; i++) {
    rec(i, 0);
  }
}

int n;

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

void solve() {
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    res ^= gr[make_pair(x, 0)];
  }
  if (res) {
    printf("NO\n");
  } else {
    printf("YES\n");
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