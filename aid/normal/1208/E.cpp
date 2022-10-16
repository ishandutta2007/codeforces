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

const int maxn = (int) 1e6 + 5;
int n, w;

bool read() {
  if (scanf("%d%d", &n, &w) < 2) {
    return false;
  }
  return true;
}

long long ans[maxn];
long long toadd[maxn];
int a[maxn];
deque<int> dq;

void solve() {
  for (int i = 0; i < w; i++) {
    ans[i] = 0;
    toadd[i] = 0;
  }
  for (int t = 0; t < n; t++) {
    int l;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
      scanf("%d", &a[i]);
    }
    dq.clear();
    for (int i = 0; i < w; i++) {
      if (l <= i && i + l <= w) {
        int j = w - l + 1;
        int val = max(0, a[dq.front()]);
        toadd[i] += val;
        toadd[j] -= val;
        i = j - 1;
        continue;
      }
      if (i < l) {
        while (!dq.empty() && a[dq.back()] <= a[i]) {
          dq.pop_back();
        }
        dq.push_back(i);
      }
      if (i + l > w) {
        int j = i - (w - l) - 1;
        if (dq.front() == j) {
          dq.pop_front();
        }
      }
      int val = a[dq.front()];
      if (l <= i || i + l < w) {
        val = max(val, 0);
      }
      ans[i] += val;
    }
  }
  {
    long long cur = 0;
    for (int i = 0; i < w; i++) {
      cur += toadd[i];
      ans[i] += cur;
    }
  }
  for (int i = 0; i < w; i++) {
    printf("%lld ", ans[i]);
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