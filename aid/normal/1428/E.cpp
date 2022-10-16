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

const int maxn = (int) 1e5 + 5;
int n, k;
int a[maxn];

bool read() {
  if (scanf("%d%d", &n, &k) < 2) {
    return false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  return true;
}

int cnt[maxn];
priority_queue<pair<long long, int>> pq;

long long sqr(long long x) {
  return x * x;
}

long long getVal(long long a, long long k) {
  return sqr(a / k) * k + (a % k) * (sqr(a / k + 1) - sqr(a / k));
}

void solve() {
  long long res = 0;
  while (!pq.empty()) {
    pq.pop();
  }
  for (int i = 0; i < n; ++i) {
    cnt[i] = 1;
    res += getVal(a[i], 1);
    pq.push(make_pair(getVal(a[i], 1) - getVal(a[i], 2), i));
  }
  for (int it = n; it < k; ++it) {
    int i = pq.top().second;
    res -= pq.top().first;
    pq.pop();
    ++cnt[i];
    if (cnt[i] + 1 <= a[i]) {
      pq.push(make_pair(getVal(a[i], cnt[i]) - getVal(a[i], cnt[i] + 1), i));
    }
  }
  printf("%lld\n", res);
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