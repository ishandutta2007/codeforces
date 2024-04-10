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

const int maxn = (int) 3e5 + 5;
int n, m;
int ks[maxn];
int c[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &ks[i]);
    --ks[i];
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &c[i]);
  }
  return true;
}

int cnt[maxn];
priority_queue<int, vector<int>, greater<int>> pq;

void solve() {
  for (int i = 0; i < m; ++i) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[ks[i]];
  }
  while (!pq.empty()) {
    pq.pop();
  }
  long long res = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      if (pq.empty() || pq.top() >= c[i]) {
        res += c[i];
      } else {
        res += pq.top();
        pq.pop();
        pq.push(c[i]);
      }
    }
    pq.push(c[i]);
  }
  printf("%lld\n", res);
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