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

void precalc() {
}

const int maxn = (int) 3e5 + 5;
int n;
long long t[maxn], w[maxn];

int read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &t[i], &w[i]);
  }
  return true;
}

pair<long long, int> tosort[maxn];

void solve() {
  for (int i = 1; i < n; i++) {
    tosort[i - 1] = make_pair(t[i], i);
  }
  sort(tosort, tosort + n - 1, greater< pair<long long, int> >());
  long long curt = t[0] - t[tosort[0].second];
  int res = inf;
  priority_queue<long long, vector<long long>, greater<long long> > pq;
  priority_queue<long long> take;
  for (int i = 0; i < n - 1; i++) {
    int id = tosort[i].second;
    if (i) {
      curt += t[tosort[i - 1].second] - t[id];
    }
    while (!pq.empty() && pq.top() <= curt) {
      curt -= pq.top();
      take.push(pq.top());
      pq.pop();
    }
    if (curt >= 0) {
      res = min(res, i - sz(take));
    }
    long long cur = w[id] - t[id] + 1;
    if (!take.empty() && take.top() > cur) {
      curt += take.top();
      pq.push(take.top());
      take.pop();
      take.push(cur);
      curt -= cur;
    } else {
      pq.push(cur);
    }
  }
  curt += t[tosort[n - 2].second];
  while (!pq.empty() && pq.top() <= curt) {
    curt -= pq.top();
    take.push(pq.top());
    pq.pop();
  }
  if (curt >= 0) {
    res = min(res, n - 1 - sz(take));
  }
  res++;
  printf("%d\n", res);
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