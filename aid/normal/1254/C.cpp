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

const int maxn = 1005;
int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

int p[maxn];
vector<pair<long long, int>> ps;

long long ask(int t, int i, int j, int k) {
  printf("%d %d %d %d\n", t, i + 1, j + 1, k + 1);
  fflush(stdout);
  long long res;
  scanf("%lld", &res);
  return res;
}

void solve() {
  p[0] = 0;
  p[1] = 1;
  for (int i = 2; i < n; i++) {
    if (ask(2, 0, i, p[1]) > 0) {
      p[1] = i;
    }
  }
  ps.clear();
  for (int i = 1; i < n; i++) {
    if (p[1] == i) {
      continue;
    }
    ps.push_back(make_pair(ask(1, 0, p[1], i), i));
  }
  sort(ps.begin(), ps.end());
  vector<int> l, r;
  int mx = ps.back().second;
  for (int i = sz(ps) - 2; i >= 0; i--) {
    if (ask(2, 0, ps[i].second, mx) > 0) {
      l.push_back(ps[i].second);
    } else {
      r.push_back(ps[i].second);
    }
  }
  reverse(l.begin(), l.end());
  int pos = 2;
  for (int i = 0; i < sz(l); i++) {
    p[pos++] = l[i];
  }
  p[pos++] = mx;
  for (int i = 0; i < sz(r); i++) {
    p[pos++] = r[i];
  }
  printf("0 ");
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i] + 1);
  }
  printf("\n");
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