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
int n, q;
long long s[maxn];
long long lens[maxn];

bool read() {
  if (scanf("%d", &n) < 1) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &s[i]);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    r++;
    lens[i] = r - l;
  }
  return true;
}

long long ans[maxn];
vector<pair<long long, int>> evs;

void solve() {
  sort(s, s + n);
  n = unique(s, s + n) - s;
  evs.clear();
  for (int i = 0; i < q; i++) {
    evs.push_back(make_pair(lens[i], i));
  }
  for (int i = 0; i + 1 < n; i++) {
    evs.push_back(make_pair(s[i + 1] - s[i], -1));
  }
  sort(evs.begin(), evs.end());
  long long cur = 0;
  long long d = n;
  long long pt = 0;
  for (int i = 0; i < sz(evs); i++) {
    cur += d * (evs[i].first - pt);
    pt = evs[i].first;
    if (evs[i].second == -1) {
      d--;
    } else {
      ans[evs[i].second] = cur;
    }
  }
  for (int i = 0; i < q; i++) {
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