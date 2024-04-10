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

long long gcd(long long a, long long b) {
  return (b ? gcd(b, a % b) : a);
}

const int maxn = (int) 5e5 + 5;
int n, m;
long long c[maxn];
pair<vector<int>, int> g[maxn];

bool read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  for (int i = 0; i < n; i++) {
    g[i].first.clear();
    g[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%lld", &c[i]);
  }
  for (int i = 0; i < m; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    v--;
    u--;
    g[u].first.push_back(v);
  }
  return true;
}

void solve() {
  for (int v = 0; v < n; v++) {
    sort(g[v].first.begin(), g[v].first.end());
  }
  sort(g, g + n);
  long long res = 0;
  for (int j = 0; j < n;) {
    int i = j;
    long long sum = 0;
    while (j < n && g[j].first == g[i].first) {
      sum += c[g[j].second];
      j++;
    }
    if (g[i].first.empty()) {
      continue;
    }
    res = gcd(res, sum);
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