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
int a[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  return true;
}

map<pair<int, int>, int> mp;
int have[maxn];
long long sum;

void update(int i, int x) {
  sum -= max(0, a[i] - have[i]);
  have[i] += x;
  sum += max(0, a[i] - have[i]);
}

void solve() {
  mp.clear();
  sum = 0;
  for (int i = 0; i < n; i++) {
    have[i] = 0;
    sum += a[i];
  }
  int q;
  scanf("%d", &q);
  for (int qq = 0; qq < q; qq++) {
    int s, t, u;
    scanf("%d%d%d", &s, &t, &u);
    s--;
    u--;
    if (mp.count(make_pair(s, t))) {
      int pu = mp[make_pair(s, t)];
      update(pu, -1);
      mp.erase(make_pair(s, t));
    }
    if (u != -1) {
      mp[make_pair(s, t)] = u;
      update(u, 1);
    }
    printf("%lld\n", sum);
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