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
int p[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  return true;
}

int fen[maxn];

void fenAdd(int i, int x) {
  for (; i < n; i |= i + 1) {
    fen[i] += x;
  }
}

int fenGet(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    res += fen[i];
  }
  return res;
}

int q[maxn];
priority_queue<pair<int, int>> l;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> r;

void solve() {
  for (int i = 0; i < n; i++) {
    fen[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int j = p[i];
    q[j] = i;
  }
  while (!l.empty()) {
    l.pop();
  }
  while (!r.empty()) {
    r.pop();
  }
  long long lsum = 0, rsum = 0;
  long long inv = 0;
  for (int i = 0; i < n; i++) {
    int x = q[i];
    inv += i - fenGet(x);
    fenAdd(x, 1);
    if (!(i & 1)) {
      r.push(make_pair(x, i));
      rsum += x;
    } else {
      l.push(make_pair(x, i));
      lsum += x;
    }
    if (!l.empty() && !r.empty()) {
      while (l.top() > r.top()) {
        auto a = l.top(), b = r.top();
        lsum -= a.first;
        rsum -= b.first;
        l.pop();
        r.pop();
        l.push(b);
        r.push(a);
        lsum += b.first;
        rsum += a.first;
      }
    }
    int y = r.top().first;
    long long res = rsum - lsum - ((i & 1) ? 0 : y) - (long long) (sz(r) - 1) * sz(r) / 2 - (long long) (sz(l) + 1) * sz(l) / 2;
    res += inv;
    printf("%lld ", res);
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