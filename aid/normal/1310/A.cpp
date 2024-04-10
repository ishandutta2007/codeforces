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

const int maxn = (int) 2e5 + 5;
int n;
int a[maxn], t[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }
  return true;
}

pair<int, int> tosort[maxn];
priority_queue<pair<int, int>> pq;

void solve() {
  for (int i = 0; i < n; i++) {
    tosort[i] = make_pair(a[i], i);
  }
  sort(tosort, tosort + n);
  while (!pq.empty()) {
    pq.pop();
  }
  long long sum = 0;
  int p = 0;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    int cur = tosort[i].first, id = tosort[i].second;
    while (!pq.empty() && p < cur) {
      int j = pq.top().second;
      pq.pop();
      sum -= t[j];
      res += sum;
      p++;
    }
    pq.push(make_pair(t[id], id));
    sum += t[id];
    p = cur;
  }
  while (!pq.empty()) {
    int j = pq.top().second;
    pq.pop();
    sum -= t[j];
    res += sum;
    p++;
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