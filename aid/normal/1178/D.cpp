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

const int maxn = 5005;
int isp[maxn];

void precalc() {
  isp[1] = false;
  for (int i = 2; i < maxn; i++) {
    isp[i] = true;
  }
  for (int i = 2; i < maxn; i++) {
    if (isp[i]) {
      for (int j = 2 * i; j < maxn; j += i) {
        isp[j] = false;
      }
    }
  }
}

int n;

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  return true;
}

vector<pair<int, int>> es;

void solve() {
  es.clear();
  for (int i = 0; i < n; i++) {
    es.push_back(make_pair(i, (i + 1) % n));
  }
  int m = sz(es);
  for (int i = 0; i + 3 < n && !isp[m]; i += 4) {
    es.push_back(make_pair(i, i + 2));
    m++;
    if (isp[m]) {
      break;
    }
    es.push_back(make_pair(i + 1, i + 3));
    m++;
  }
  assert(isp[m]);
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    printf("%d %d\n", es[i].first + 1, es[i].second + 1);
  }
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  /*for (n = 3; n <= 1000; n++) {
    solve();
  }*/
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}